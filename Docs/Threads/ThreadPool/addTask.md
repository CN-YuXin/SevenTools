# SevenTools::ThreadPool::addTask

```cpp
template <class F, class... Args>
std::future<std::invoke_result_t<std::decay_t<F>, Args...>> addTask(F&& fn, Args&&... args);// (C++17 起)

template <class F, class... Args>
std::future<typename std::result_of<typename std::decay<F>::type(Args...)>::type> addTask(F&& fn, Args&&... args);// (C++17 前)
```

添加执行的任务，如果没有空闲线程那么任务的执行会被推迟

执行任务的方式等同于 `INVOKE(f, decay-copy(std::forward<Args>(args))...)`，其中 `f` 的类型是 `typename std::decay<F>::type`，使用 `std::forward<F>(fn)` 初始化(直接初始化)

要求 `INVOKE(std::declval<typename std::decay<F>::type&>(), std::declval<typename std::decay<Args>::type&>()...)` 是合法的表达式

## 参数

- `fn` \- 可调用对象
- `args` \- 调用可调用对象的实参

## 异常

- `std::bad_alloc`: 分配失败
- `fn` 的移动构造或拷贝构造抛出的异常
- `args...` 的移动构造或拷贝构造抛出的异常

此函数具有强异常安全保证: 若抛出任何异常则此函数无效果