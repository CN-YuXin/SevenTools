# SevenTools::BasicStringView::find

```cpp
SizeType find(const BasicStringView& sv, SizeType pos = 0) const noexcept;// 1 (C++17 起 constexpr)
SizeType find(C ch, SizeType pos = 0) const noexcept;// 2 (C++17 起 constexpr)
```

查找首个等于给定字符(序列)的子视图的位置

1. 查找 `sv` 的内容在此视图中的首次出现，从 `pos` 开始查找，具体来说它返回 `xpos`，`xpos` 是满足以下条件的最小值:
   - `xpos >= pos`
   - `xpos + sv.length() <= length()`
   - `CTraits::eq(at(xpos + i), sv.at(i))` 对于 `sv` 中所有可能的索引 `i` 都为 `true`  
    若不存在这样的 `xpos` 则返回 `npos`
2. 等价于 `find(BasicStringView(&ch, 1), pos)`

## 参数

- `sv` \- 要查找的视图
- `pos` \- 查找开始的位置(从 0 开始)
- `ch` \- 要查找的字符

## 返回值

首个等于给定内容的子视图的位置