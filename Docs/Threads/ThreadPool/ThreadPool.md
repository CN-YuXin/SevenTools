# SevenTools::ThreadPool::ThreadPool

```cpp
ThreadPool();// 1
ThreadPool(const ThreadPool&) = delete;// 2
```

1. 构造一个没有任何任务的线程池，底层使用 `std::thread`，若构造期间抛出异常(例如资源不足)则令所有已创建的线程退出并重抛异常
2. 拷贝构造被显式弃置