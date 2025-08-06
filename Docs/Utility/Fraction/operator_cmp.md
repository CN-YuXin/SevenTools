# operator==, !=, <, <=, >, >=(SevenTools::Fraction)

```cpp
friend constexpr bool operator==(const Fraction& lhs, const Fraction& rhs) noexcept;// 1
friend constexpr bool operator!=(const Fraction& lhs, const Fraction& rhs) noexcept;// 2
friend bool operator<(const Fraction& lhs, const Fraction& rhs) noexcept;// 3 (C++20 起 constexpr)
friend bool operator<=(const Fraction& lhs, const Fraction& rhs) noexcept;// 4 (C++20 起 constexpr)
friend bool operator>(const Fraction& lhs, const Fraction& rhs) noexcept;// 5 (C++20 起 constexpr)
friend bool operator>=(const Fraction& lhs, const Fraction& rhs) noexcept;// 6 (C++20 起 constexpr)
```

1. 返回 `lhs.getNumerator() == rhs.getNumerator() && lhs.getDenominator() == rhs.getDenominator()`
2. 返回 `lhs.getNumerator() != rhs.getNumerator() || lhs.getDenominator() != rhs.getDenominator()`
3. 设 `l` 为 [`lhs.getDenominator()`](getDenominator.md) 与 `rhs.getDenominator()` 的最小公倍数，返回 `lhs.getNumerator() * (l / lhs.getDenominator()) < rhs.getNumerator() * (l / rhs.getDenominator())`
4. 返回 `lhs < rhs || lhs == rhs`
5. 返回 `rhs > lhs`
6. 返回 `lhs > rhs || lhs == rhs`

## 参数

- `lhs` \- 左操作数
- `rhs` \- 右操作数

## 返回值

1. `lhs.getNumerator() == rhs.getNumerator() && lhs.getDenominator() == rhs.getDenominator()`
2. `lhs.getNumerator() != rhs.getNumerator() || lhs.getDenominator() != rhs.getDenominator()`
3. `lhs.getNumerator() * (l / lhs.getDenominator()) < rhs.getNumerator() * (l / rhs.getDenominator())`
4. `lhs < rhs || lhs == rhs`
5. `rhs > lhs`
6. `lhs > rhs || lhs == rhs`