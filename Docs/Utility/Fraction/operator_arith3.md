# SevenTools::Fraction::operator+=, SevenTools::Fraction::operator-=, SevenTools::Fraction::operator*=, SevenTools::Fraction::operator/=

```cpp
Fraction& operator+=(const Fraction& other) noexcept;// 1 (C++20 起 constexpr)
Fraction& operator-=(const Fraction& other) noexcept;// 2 (C++20 起 constexpr)
Fraction& operator*=(const Fraction& other) noexcept;// 3 (C++20 起 constexpr)
Fraction& operator/=(const Fraction& other) noexcept;// 4 (C++20 起 constexpr)
```

设 `l` 为 [`getDenominator()`](getDenominator.md) 与 `other.getDenominator()` 的最小公倍数:
1. `*this = Fraction(getNumerator() * (l / getDenominator()) + other.getNumerator() * (l / other.getDenominator()), l)`
2. `*this = Fraction(getNumerator() * (l / getDenominator()) - other.getNumerator() * (l / other.getDenominator()), l)`
3. `*this = Fraction(getNumerator() * other.getNumerator(), getDenominator() * other.getDenominator())`
4. `*this *= other.reciprocal()`

## 参数

- `other` \- 与此分数运算的另一分数

## 返回值

`*this`