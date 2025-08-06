# SevenTools::Fraction::operator=

```cpp
Fraction& operator=(T val) noexcept;// 1 (C++14 起 constexpr)
Fraction& operator=(const Fraction& other) noexcept;// 2 (C++14 起 constexpr)
```

1. 赋值后 [`getNumerator`](getNumerator.md) 为 `val`，且 [`getDenominator`](getDenominator) 为 1
2. 赋值后 [`getNumerator`](getNumerator.md) 为 `other.getNumerator()`，且 [`getDenominator`](getDenominator) 为 `other.getDenominator()`

## 参数

- `val`, `other` \- 新值

## 返回值

`*this`