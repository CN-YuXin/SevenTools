# SevenTools::BasicStringView::findLastOf

```cpp
SizeType findLastOf(const BasicStringView& sv, SizeType pos = 0) const noexcept;// (C++17 起 constexpr)
```

查找最后一个等于 `sv` 中任意一个字符的字符的位置，具体来说它返回 `xpos`，`xpos` 是满足以下条件的最大值:
- `xpos >= pos`
- `xpos < length()`
- `CTraits::eq(at(xpos), sv.at(i))` 对于 `sv` 中任意一个可能的索引 `i` 为 `true`  
若不存在这样的 `xpos` 则返回 `npos`

## 参数

- `sv` \- 要查找的视图
- `pos` \- 查找开始的位置(从 0 开始)

## 返回值

最后一个等于 `sv` 中任意一个字符的字符的位置