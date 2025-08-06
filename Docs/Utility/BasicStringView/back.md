# SevenTools::BasicStringView::back

```cpp
constexpr Reference back() const noexcept;
```

返回最后一个字符的引用，即 `operator[](length() - 1)`

## 返回值

最后一个字符的引用