# SevenTools::Fraction::Fraction

```cpp
constexpr Fraction() noexcept;// 1
Fraction(T n, T d = 1) noexcept;// 2 (C++20 起 constexpr)
constexpr Fraction(const Fraction& other) noexcept;// 3
```

1. 构造一个分数，构造后 [`getDenominator`](getDenominator.md) 为 0，且 [`getNumerator`](getNumerator.md) 为 1
2. 构造一个分数，构造后 [`getDenominator`](getDenominator.md) 为 `d`，且 [`getNumerator`](getNumerator.md) 为 `n`
3. 构造一个分数，构造后 [`getDenominator`](getDenominator.md) 为 `other.getDenominator()`，且 [`getNumerator`](getNumerator.md) 为 `other.getNumerator()`

## 参数

- `n` \- 分子
- `d` \- 分母
- `other` \- 要拷贝的另一分数