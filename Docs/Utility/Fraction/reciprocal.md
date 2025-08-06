# SevenTools::Fraction::reciprocal

```cpp
Fraction reciprocal() const noexcept;// (C++20 起 constexpr)
```

返回此分数的倒数，即 `Fraction(getDenominator(), getNumerator())

## 返回值

`Fraction(getDenominator(), getNumerator())`