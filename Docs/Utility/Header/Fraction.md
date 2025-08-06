# Fracrion.h

提供分数类，与 `std::ratio` 不同的是此类可以在运行时使用

## 类

| 标识符 | 介绍 |
| :-    | :-  |
| [`Fraction`](../Fraction.md) | 提供分数类 |

## 概要

```cpp
namespace SevenTools {
    template <class T = int>
    class Fraction {
    public:
        using ValueType = T;

        constexpr Fraction() noexcept;
        Fraction(T n, T d = 1) noexcept;// (C++20 起 constexpr)
        constexpr Fraction(const Fraction& other) noexcept;

        Fraction& operator=(T val) noexcept;// (C++14 起 constexpr)
        Fraction& operator=(const Fraction& other) noexcept;// (C++14 起 constexpr)

        constexpr T getDenominator() const noexcept;
        void setDenominator(T newValue) noexcept;
        constexpr T getNumerator() const noexcept;
        void setNumerator(T newValue) noexcept;
        template <class U = double>
        constexpr U getValue() const noexcept;
        template <class U>
        constexpr explicit operator U() const noexcept;

        Fraction reciprocal() const noexcept;// (C++20 起 constexpr)

        constexpr Fraction operator+() const noexcept;
        Fraction operator-() const noexcept;// (C++20 起 constexpr)

        Fraction operator+(const Fraction& other) const noexcept;// (C++20 起 constexpr)
        Fraction operator-(const Fraction& other) const noexcept;// (C++20 起 constexpr)
        Fraction operator*(const Fraction& other) const noexcept;// (C++20 起 constexpr)
        Fraction operator/(const Fraction& other) const noexcept;// (C++20 起 constexpr)

        Fraction& operator+=(const Fraction& other) noexcept;// (C++20 起 constexpr)
        Fraction& operator-=(const Fraction& other) noexcept;// (C++20 起 constexpr)
        Fraction& operator*=(const Fraction& other) noexcept;// (C++20 起 constexpr)
        Fraction& operator/=(const Fraction& other) noexcept;// (C++20 起 constexpr)

        void swap(Fraction& other) noexcept;

        friend constexpr bool operator==(const Fraction& lhs, const Fraction& rhs) noexcept;
        friend constexpr bool operator!=(const Fraction& lhs, const Fraction& rhs) noexcept;
        friend bool operator<(const Fraction& lhs, const Fraction& rhs) noexcept;// (C++20 起 constexpr)
        friend bool operator<=(const Fraction& lhs, const Fraction& rhs) noexcept;// (C++20 起 constexpr)
        friend bool operator>(const Fraction& lhs, const Fraction& rhs) noexcept;// (C++20 起 constexpr)
        friend bool operator>=(const Fraction& lhs, const Fraction& rhs) noexcept;// (C++20 起 constexpr)
    };
    template <class T>
    void swap(Fraction<T>& lhs, Fraction<T>& rhs) noexcept;
}
```