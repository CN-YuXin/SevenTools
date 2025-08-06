# SevenTools::BasicStringView::subStr

```cpp
BasicStringView subStr(SizeType pos, SizeType count = npos) const;
```

返回 `BasicStringView(data() + pos, rlen)`，其中 `rlen` 是 `count` 与 `length() - pos` 中的较小者

## 参数

- `pos` \- 其子视图第一个字符位于此视图的位置
- `count` \- 子视图的长度

## 返回值

`BasicStringView(data() + pos, rlen)`

## 异常

当 `pos > length()` 时，抛出 `std::out_of_range`