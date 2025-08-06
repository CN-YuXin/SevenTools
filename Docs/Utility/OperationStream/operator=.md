# SevenTools::OperationStream::operator=

```cpp
OperationStream& operator=(const OperationStream& v);// 1
OperationStream& operator=(OperationStream&& v);// 2
```

1. 拷贝赋值，赋值后此操作序列的内容被 `v` 的内容所替换(就如同拷贝构造中所述)
2. 如同执行 `Operation(std::move(v)).swap(*this)`

## 参数

- `v` \- 另一操作序列

## 返回值

`*this`