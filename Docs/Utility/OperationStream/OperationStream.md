# SevenTools::OperationStream::OperationStream

```cpp
OperationStream() noexcept;// 1
OperationStream(const OperationStream& other);// 2
OperationStream(OperationStream&& other) noexcept;// 3
```

1. 默认构造函数，构造空的操作序列
2. 拷贝构造函数，构造后 [`length()`](length.md) 等于 `other.length()`，并且所有在相同位置的操作均等价(也就是说操作的先后顺序不变)
3. 移动构造函数，构造后 [`length()`](length.md) 等于在构造前 `other.length()` 的值，并且与构造前的 `other` 比较所有在相同位置的操作均等价，构造后 `other.length()` 返回 0

## 参数

- `other` \- 另一操作序列