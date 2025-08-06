# SevenTools::OperationStream::inputData, SevenTools::OperationStream::operator()

```cpp
template <class... Args>
T inputData(Args&&... args) const;// 1
template <class... Args>
T operator()(Args&&... args) const;// 2
```

将数据给到操作序列中的操作使其依次处理

1. 设块变量 `tmp` 其定义为 `T tmp(std::forward<Args>(args)...)`，首先将从第一个操作开始将 `tmp` 作为唯一实参传入此操作，若操作不返回 `false` 则继续对下一个操作(如果有)进行此操作，重复此行为直到没有下一个操作或操作返回 `false`，最后返回 `tmp`
2. 返回 `inputData(std::forward<Args>(args)...)`

## 参数

- `args` \- 用于初始化 `tmp` 的实参

## 返回值

1. `tmp`
2. `inputData(std::forward<Args>(args)...)`

## 异常

构造 `tmp` 或操作所抛出的异常