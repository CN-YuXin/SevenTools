# SevenTools::BasicStringView::front, SevenTools::BasicStringView::operator\*

```cpp
constexpr Reference front() const noexcept;
constexpr Reference operator*() const noexcept;
```

返回第一个字符的引用，即 `operator[](0)`

## 返回值

第一个字符的引用