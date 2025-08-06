# SevenTools::BasicStringView::BasicStringView

```cpp
constexpr BasicStringView() noexcept;// 1
constexpr BasicStringView(const std::basic_string<C>& t) noexcept;// 2
constexpr BasicStringView(const BasicStringView& other) noexcept = default;// 3
constexpr BasicStringView(const C* b, SizeType n) noexcept;// 4
BasicStringView(const C* str) noexcept;// 5 (C++14 起 constexpr)
BasicStringView(std::nullptr_t) = delete;// 6
```

1. 构造一个空视图
2. 以 `t` 构造视图，`t.size()` 不应大于 [`maxSize()`](maxSize.md)
3. 默认生成的拷贝构造函数
4. 以 [b, b + n) 范围构造视图，若此范围不合法(例如 `n` 大于 `b` 后的字符个数)则行为未定义
5. 以 `str` 所指向的空终止字符串构造视图(不包括空字符)，设正整数 `n` 为满足 `str[n] == C()` 的最小值(如果 `str` 指向的字符串不以空字符终止，则行为未定义)，C++17 起 `n` 使用 `CTraits::length(str)` 确定
6. 不能从 `nullptr` 构造

## 参数

- `t` \- 用于初始化视图的 `std::basic_string<C>`
- `other` \- 用于初始化此视图的另一视图
- `b` \- 指向用于初始化视图的字符数组的元素的指针
- `n` \- 视图的长度
- `str` \- 指向空终止字符串的指针

## 后条件

1. [`data()`](data.md) 为 `nullptr` 且 [`length()`](length.md) 为 0
2. [`data()`](data.md) 为 `t.data()` 且 [`length()`](length.md) 为 `t.size()`
3. [`data()`](data.md) 为 `other.data()` 且 [`length()`](length.md) 为 `other.length()`
4. [`data()`](data.md) 为 `b` 且 [`length()`](length.md) 为 `n`
5. [`data()`](data.md) 为 `str` 且 [`length()`](length.md) 为 `n`(见上文)
