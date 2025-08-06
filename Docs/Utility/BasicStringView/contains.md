# SevenTools::BasicStringView::contains

```cpp
bool contains(const BasicStringView& sv) const noexcept;// 1 (C++17 起 constexpr)
bool contains(C ch) const noexcept;// 2 (C++17 起 constexpr)
```

判断视图是否包含指定内容

1. 返回 `find(sv) != npos`
2. 返回 `find(ch) != npos`

## 参数

- `sv` \- 一个视图
- `ch` \- 一个字符

## 返回值

若视图包含指定的内容则返回 `true`，否则返回 `false`