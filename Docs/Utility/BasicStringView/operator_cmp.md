# operator==, !=(SevenTools::BasicStringView)

```cpp
template <class C>
bool operator==(const BasicStringView<C>& lhs, const BasicStringView<C>& rhs) noexcept;// 1 (C++17 起 constexpr)
template <class C>
bool operator!=(const BasicStringView<C>& lhs, const BasicStringView<C>& rhs) noexcept;// 2 (C++17 起 constexpr)
```

通过调用 `lhs.compare(rhs)` 来比较两个视图
1. 等价于 `lhs.compare(rhs) == 0`
2. 等价于 `lhs.compare(rhs) != 0`

## 参数

- `lhs`, `rhs` \- 要比较的视图