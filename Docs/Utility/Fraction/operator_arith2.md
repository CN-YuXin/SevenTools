# SevenTools::Fraction::operator+, SevenTools::Fraction::operator-, SevenTools::Fraction::operator*, SevenTools::Fraction::operator/

```cpp
Fraction operator+(const Fraction& other) const noexcept;// 1 (C++20 起 constexpr)
Fraction operator-(const Fraction& other) const noexcept;// 2 (C++20 起 constexpr)
Fraction operator*(const Fraction& other) const noexcept;// 3 (C++20 起 constexpr)
Fraction operator/(const Fraction& other) const noexcept;// 4 (C++20 起 constexpr)
```

1. 返回 `Fraction(*this) += other`
2. 返回 `Fraction(*this) -= other`
3. 返回 `Fraction(*this) *= other`
4. 返回 `Fraction(*this) /= other`

## 参数

- `other` \- 与此分数运算的另一分数

## 返回值

1. 返回 `Fraction(*this) += other`
2. 返回 `Fraction(*this) -= other`
3. 返回 `Fraction(*this) *= other`
4. 返回 `Fraction(*this) /= other`