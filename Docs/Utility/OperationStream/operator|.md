# operator|(SevenTools::OperationStream)

```cpp
template <class F>
friend OperationStream operator|(const OperationStream& os, F&& op);// 1
template <class F>
friend OperationStream operator|(OperationStream&& os, F&& op);// 2
friend T operator|(const T& v, const OperationStream& os);// 3
friend OperationStream operator|(const OperationStream& lhs, const OperationStream& rhs);// 4
```

拼接操作序列或将输入送入流中

1. 返回 `OperationStream(os).addOperation(std::forward<F>(op))`，如果 `F` 删除引用和 CV 限定后与 `OperationStream<T>` 为同一类型则不参加重载决议
2. 返回 `OperationStream(std::move(os)).addOperation(std::forward<F>(op))`，如果 `F` 删除引用和 CV 限定后与 `OperationStream<T>` 为同一类型则不参加重载决议
3. 返回 `os(v)`
4. 返回新的操作序列 `t`，此操作序列等同于将 `rhs` 的所有操作依次追加到 `lhs` 末尾的版本

## 参数

- `os`, `lhs`, `rhs` \- 操作序列
- `op` \- 操作
- `v` \- 数据

## 返回值

1. `OperationStream(os).addOperation(std::forward<F>(op))`
2. `OperationStream(std::move(os)).addOperation(std::forward<F>(op))`
3. `os(v)`
4. `t`