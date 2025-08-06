#ifndef ThreadPoolByYX
#define ThreadPoolByYX

#include <condition_variable>
#include <IntegerSequence.h>
#include <CppVersions.h>
#include <type_traits>
#include <functional>
#include <cstddef>
#include <utility>
#include <memory>
#include <thread>
#include <future>
#include <queue>
#include <mutex>

namespace SevenTools {
    template <std::size_t N>
    class ThreadPool {
        std::thread allThreads[N];
        std::queue<std::function<void()>> allTasks;
        std::mutex mtx;
        std::condition_variable cva;

        bool destroyed{false};

        template <class... Ts, std::size_t... I>
        static void call(std::tuple<Ts...>& t, IndexSequence<I...>) noexcept {
            std::get<0>(t)(std::move(std::get<I + 1>(t))...);
        }
    public:
        constexpr static std::size_t size = N;
        ThreadPool() {
            try {
                for (std::size_t i = 0;i < N;++i) {
                    allThreads[i] = std::thread([this] {
                        while (true) {
                            std::unique_lock<std::mutex> ulk(mtx);
                            while (allTasks.empty() and !destroyed)
                                cva.wait(ulk);
                            
                            if (!allTasks.empty()) {
                                std::function<void()> tk = allTasks.front();
                                allTasks.pop();
                                
                                ulk.unlock();

                                tk();
                            } else if (destroyed) {
                                break;
                            }
                        }
                    });
                }
            } catch(...) {
                mtx.lock();
                destroyed = true;
                mtx.unlock();
                cva.notify_all();
                for (std::thread& th : allThreads)
                    if (th.joinable())
                        th.join();
                throw;
            }
        }
        ThreadPool(const ThreadPool&) = delete;
        ~ThreadPool() {
            mtx.lock();
            destroyed = true;
            mtx.unlock();
            cva.notify_all();
            for (std::size_t i = 0;i < N;++i) {
                allThreads[i].join();
            }
        }

        ThreadPool& operator=(const ThreadPool&) = delete;

        template <class F, class... Args>
        #if HasCpp17
        std::future<std::invoke_result_t<std::decay_t<F>, Args...>> addTask(F&& fn, Args&&... args)
        #else
        std::future<typename std::result_of<typename std::decay<F>::type(Args...)>::type> addTask(F&& fn, Args&&... args)
        #endif
            {
            mtx.lock();
            
            #if HasCpp17
            using RT = std::invoke_result_t<std::decay_t<F>, Args...>;
            #else
            using RT = typename std::result_of<typename std::decay<F>::type(Args...)>::type;
            #endif

            try {
                using TupleType = std::tuple<std::packaged_task<RT(typename std::decay<Args>::type&...)>, typename std::decay<Args>::type...>;
                auto tk = std::make_shared<TupleType>(std::forward<F>(fn), std::forward<Args>(args)...);
                allTasks.emplace([tk]() mutable {
                    call(*tk, MakeIndexSequence<sizeof...(Args)>{});
                });

                mtx.unlock();
                cva.notify_one();
                return std::get<0>(*tk).get_future();
            } catch(...) {
                mtx.unlock();
                throw;
            }
        }

        typename decltype(allTasks)::size_type taskCount() {
            std::unique_lock<std::mutex> ulk(mtx);
            return allTasks.size();
        }
    };
}

#endif // ThreadPoolByYX