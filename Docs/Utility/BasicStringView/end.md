# SevenTools::BasicStringView::end

```cpp
constexpr Iterator end() const noexcept;
```

返回指向最后一个字符的下一个位置的迭代器(即尾后迭代器)，访问其指向的字符可能导致未定义行为(取决于视图在原字符串中的位置)

## 返回值

尾后迭代器