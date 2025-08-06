# ThreadPool.h

提供线程数固定的线程池类

## 类

| 标识符 | 介绍 |
| :-    | :-  |
| [`ThreadPool`](../ThreadPool.md) | 线程数固定的线程池类 |

## 概要

```cpp
namespace SevenTools {
    template <std::size_t N>
    class ThreadPool {
        ThreadPool();
        ThreadPool(const ThreadPool&) = delete;
        ~ThreadPool();

        constexpr static std::size_t size = N;

        template <class F, class... Args>
        /* 见介绍 */ addTask(F&& fn, Args&&... args);
    };
}
```