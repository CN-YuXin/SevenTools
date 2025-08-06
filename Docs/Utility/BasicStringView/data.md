# SevenTools::BasicStringView::data

```cpp
constexpr ConstPointer data() const noexcept;
```

返回指向底层字符数组的指针，保证范围 [`data()`, `data() + length()`) 有效

## 返回值

指向底层字符数组的指针

## 注解

不保证 `data()[length() - 1]` 一定为空字符，因此将 `data()` 直接传给期望空字符终止的函数(例如 `strlen`)通常是错误的