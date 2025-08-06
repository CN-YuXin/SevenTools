# SevenTools::BasicStringView::compare

```cpp
int compare(const BasicStringView& sv) const noexcept;// 1 (C++17 起 constexpr)
int compare(SizeType pos, const BasicStringView& sv, SizeType count = npos) const;// 2 (C++17 起 constexpr)
```

1. 设 `rlen` 为 [`length()`](length.md) 与 `sv.length()` 之间的较小值，此函数通过调用 `CTraits::compare(data(), sv.data(), rlen)` 来比较两个视图，返回值如下:
   1. `CTraits::compare(data(), sv.data(), rlen)` 为负，返回 -1
   2. `CTraits::compare(data(), sv.data(), rlen)` 为正，返回 1
   3. `CTraits::compare(data(), sv.data(), rlen)` 为 0，此时根据视图长度返回:
      - 若 [`length()`](length.md) 大于 `sv.length()` 返回 1
      - 否则，若 [`length()`](length.md) 小于 `sv.length()` 返回 -1
      - 否则返回 0
2. 等价于 `subStr(pos, count).compare(sv)`

## 参数

- `sv` \- 要比较的视图
- `pos` \- 要比较的位置
- `count` \- 要比较的字符数

## 返回值

如果此视图小于 `sv` 则返回 -1，否则若大于返回 1，否则返回 0