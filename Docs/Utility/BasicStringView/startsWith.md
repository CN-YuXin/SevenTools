# SevenTools::BasicStringView::startsWith

```cpp
bool startsWith(const BasicStringView& sv) const noexcept;// 1 (C++17 起 constexpr)
constexpr bool startsWith(C ch) const noexcept;// 2
```

判断视图是否以指定的内容开头

1. 返回 `subStr(0, rlen) == sv`，其中 `rlen` 是 `length()` 与 `sv.length()` 之间的较小者
2. 返回 `!empty() && CTraits::eq(front(), ch)`

## 参数

- `sv` \- 一个视图
- `ch` \- 一个字符

## 返回值

如果视图以指定的内容开头则返回 `true`，否则返回 `false`