#ifndef OperationStreamByYX
#define OperationStreamByYX

#include <CppVersions.h>
#include <type_traits>
#include <functional>
#include <utility>
#include <vector>

namespace SevenTools {
    template <class T>
    class OperationStream {
        // 没错，这个命名灵感来源于某 R 字开头的语言 (︎ ᐛ )
        using Vec = std::vector<std::function<bool(T&)>>;
        
        static_assert(!std::is_reference<T>::value, "Illegal type");
    public:
        using SizeType = typename Vec::size_type;
        using DataType = T;

        OperationStream() noexcept {}
        OperationStream(const OperationStream& other):
        operations(other.operations) {
        }
        OperationStream(OperationStream&& other) noexcept:
        operations(std::move(other.operations)) {
            other.clear();
        }

        OperationStream& operator=(const OperationStream& v) {
            operations = v.operations;
            return *this;
        }
        OperationStream& operator=(OperationStream&& v) {
            OperationStream(std::move(v)).swap(*this);
            return *this;
        }

        SizeType maxSize() const noexcept {
            return operations.max_size();
        }
        template <class F,
            typename std::enable_if<
                !std::is_same<
                    typename std::remove_cv<typename std::remove_reference<F>::type>::type,
                    OperationStream
                >::value, bool>::type = true>
        void addOperation(F&& op) {
            operations.emplace_back(std::forward<F>(op));
        }
        void clear() {
            operations.clear();
        }

        SizeType size() const {
            return operations.size();
        }
        SizeType length() const {
            return operations.size();
        }
        bool empty() const {
            return operations.empty();
        }

        template <class... Args>
        T inputData(Args&&... args) const {
            T tmp(std::forward<Args>(args)...);
            if (!operations.empty()) {
                for (auto&& e : operations) {
                    if (!e(tmp))
                        break;
                }
            }
            return tmp;
        }
        template <class... Args>
        T operator()(Args&&... args) const {
            return inputData(std::forward<Args>(args)...);
        }

        void swap(OperationStream& other) {
            std::swap(operations, other.operations);
        }
        
        template <class F,
            typename std::enable_if<
                !std::is_same<
                    typename std::remove_cv<typename std::remove_reference<F>::type>::type,
                    OperationStream
                >::value, bool>::type = true>
        friend OperationStream operator|(const OperationStream& os, F&& op) {
            return OperationStream(os).addOperation(std::forward<F>(op));
        }
        template <class F,
            typename std::enable_if<
                !std::is_same<
                    typename std::remove_cv<typename std::remove_reference<F>::type>::type,
                    OperationStream
                >::value, bool>::type = true>
        friend OperationStream operator|(OperationStream&& os, F&& op) {
            return OperationStream(std::move(os)).addOperation(std::forward<F>(op));
        }
        friend T operator|(const T& v, const OperationStream& os) {
            return os(v);
        }
        friend OperationStream operator|(const OperationStream& lhs, const OperationStream& rhs) {
            OperationStream t = lhs;
            t.operations.insert(t.operations.end(), rhs.operations.begin(), rhs.operations.end());
            return t;
        }

        #if HasCpp14
        static auto add(const T& v) {
            return [v](T& d) {
                d += v;
                return true;
            };
        }
        static auto sub(const T& v) {
            return [v](T& d) {
                d -= v;
                return true;
            };
        }
        static auto mul(const T& v) {
            return [v](T& d) {
                d *= v;
                return true;
            };
        }
        static auto div(const T& v) {
            return [v](T& d) {
                d /= v;
                return true;
            };
        }
        #endif // HasCpp14
    private:
        std::vector<std::function<bool(T&)>> operations;
    };

    template <class T>
    void swap(OperationStream<T>& lhs, OperationStream<T>& rhs) {
        lhs.swap(rhs);
    }
}

#endif // OperationStreamByYX