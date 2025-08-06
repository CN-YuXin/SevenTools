# SevenTools::BasicStringView::operator[]

```cpp
constexpr Reference operator[](SizeType i) const noexcept;
```

返回视图中位于位置 `i` 的字符的引用(第一个字符位置为 0)，如果 `i >= length()` 则可能导致未定义行为(取决于视图在原字符串中的位置)

## 参数

- `i` \- 要返回的字符的引用的位置

## 返回值

视图中位于位置 `i` 的字符的引用