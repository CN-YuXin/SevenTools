# SevenTools::BasicStringView::endsWith

```cpp
bool endsWith(const BasicStringView& sv) const noexcept;// 1 (C++17 起 constexpr)
constexpr bool endsWith(C ch) const noexcept;// 2
```

判断视图是否以指定的内容结尾

1. 返回 `length() >= sv.length() && subStr(length() - sv.length()) == sv`
2. 返回 `!empty() && CTraits::eq(back(), ch)`

## 参数

- `sv` \- 一个视图
- `ch` \- 一个字符

## 返回值

如果视图以指定的内容结尾则返回 `true`，否则返回 `false`