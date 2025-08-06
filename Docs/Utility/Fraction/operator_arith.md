# SevenTools::Fraction::operator+, SevenTools::Fraction::operator-

```cpp
constexpr Fraction operator+() const noexcept;// 1
Fraction operator-() const noexcept;// 2 (C++20 起 constexpr)
```

实现一元 + 和 - 运算符
1. 返回 `*this`
2. 返回 `Fraction(-getNumerator(), getDenominator())`

## 返回值

1. `*this`
2. `Fraction(-getNumerator(), getDenominator())`