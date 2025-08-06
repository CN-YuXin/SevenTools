# SevenTools::BasicStringView::at

```cpp
Reference at(SizeType i) const;// (C++14 起 constexpr)
```

返回视图中位于位置 `i` 的字符的引用(第一个字符位置为 0)，与 [`operator[]`](operator[].md) 不同的是，此函数会进行边界检查

## 参数

- `i` \- 要返回的字符的引用的位置

## 返回值

视图中位于位置 `i` 的字符的引用

## 异常

如果 `i >= length()` 则抛出 `std::out_of_range`