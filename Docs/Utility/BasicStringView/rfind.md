# SevenTools::BasicStringView::rfind

```cpp
SizeType rfind(const BasicStringView& sv, SizeType pos = 0) const noexcept;// 1 (C++17 起 constexpr)
SizeType rfind(C ch, SizeType pos = 0) const noexcept;// 2 (C++14 起 constexpr)
```

查找最后一个等于给定字符(序列)的子视图的位置

1. 查找 `sv` 的内容在此视图的最后一次出现，从 `pos` 开始查找(如同从末端向开头查找)，具体来说它返回 `xpos`，`xpos` 是满足以下条件的最大值:
   - `pos >= xpos`
   - `xpos + sv.length() <= length()`
   - `CTraits::eq(at(xpos + i), sv.at(i))` 对于 `sv` 中所有可能的索引 `i` 都为 `true`  
    若不存在这样的 `xpos` 则返回 `npos`
2. 等价于 `rfind(BasicStringView(&ch, 1), pos)`

## 参数

- `sv` \- 要查找的视图
- `pos` \- 查找开始的位置(从 0 开始)
- `ch` \- 要查找的字符

## 返回值

最后一个等于给定内容的子视图的位置

## 注解

第二个版本真没写错，就是 14 起 `constexpr` 不是 17 起