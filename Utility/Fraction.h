#ifndef FractionByYX
#define FractionByYX

#include <CppVersions.h>
#include <type_traits>
#include <utility>
#include <cmath>

// 嘛的全因为 std::exchange 不然就能直接写 constexpr 了
#if HasCpp20
    #define SevenToolsFractionConstexpr constexpr
#else
    #define SevenToolsFractionConstexpr
#endif

namespace SevenTools {
    template <class T = int>
    class Fraction {
        T den{}, num{};
        static_assert(
            std::is_integral<T>::value and
            !std::is_same<T, bool>::value,
            "Illegal type");
        static SevenToolsFractionConstexpr T gcd(T a, T b) {
            a = std::abs(a);
            b = std::abs(b);
            while (b != 0) {
                b = std::exchange(a, b) % b;
            }
            return a;
        }
        static SevenToolsFractionConstexpr T lcm(T a, T b) {
            if (a == 0 or b == 0)
                return 0;
            a = std::abs(a);
            b = std::abs(b);
            return a / gcd(a, b) * b;
        }
    public:
        using ValueType = T;    

        constexpr Fraction() noexcept: den(1), num(0) {}
        SevenToolsFractionConstexpr Fraction(T n, T d = 1) noexcept:
        den(gcd(d, n)),
        num(n / std::exchange(den, d / den)) {
        }
        constexpr Fraction(const Fraction& other) noexcept: den(other.den), num(other.num) {
        }

        #if HasCpp14
        constexpr
        #endif
        Fraction& operator=(T val) noexcept {
            num = val;
            den = 1;
            return *this;
        }
        #if HasCpp14
        constexpr
        #endif
        Fraction& operator=(const Fraction& other) noexcept {
            num = other.num;
            den = other.den;
            return *this;
        }

        constexpr T getDenominator() const noexcept {
            return den;
        }
        void setDenominator(T newValue) noexcept {
            const auto g = gcd(newValue, num);
            den = newValue / g;
            num /= g;
        }
        constexpr T getNumerator() const noexcept {
            return num;
        }
        void setNumerator(T newValue) noexcept {
            const auto g = gcd(den, newValue);
            den /= g;
            num = newValue / g;
        }
        template <class U = double>
        constexpr U getValue() const noexcept {
            return (U)num / den;
        }
        template <class U>
        constexpr explicit operator U() const noexcept {
            return getValue<U>();
        }

        SevenToolsFractionConstexpr Fraction reciprocal() const noexcept {
            return {den, num};
        }

        constexpr Fraction operator+() const noexcept {
            return *this;
        }
        SevenToolsFractionConstexpr Fraction operator-() const noexcept {
            return {-num, den};
        }

        SevenToolsFractionConstexpr Fraction operator+(const Fraction& other) const noexcept {
            return Fraction(*this) += other;
        }
        SevenToolsFractionConstexpr Fraction operator-(const Fraction& other) const noexcept {
            return Fraction(*this) -= other;
        }
        SevenToolsFractionConstexpr Fraction operator*(const Fraction& other) const noexcept {
            return Fraction(*this) *= other;
        }
        SevenToolsFractionConstexpr Fraction operator/(const Fraction& other) const noexcept {
            return Fraction(*this) /= other;
        }

        SevenToolsFractionConstexpr Fraction& operator+=(const Fraction& other) noexcept {
            if (den != other.den) {
                const T l = lcm(den, other.den);
                den = l;
                num = num * (l / den) + other.num * (l / other.den);
            } else {
                num += other.num;
            }
            const T g = gcd(den, num);
            num /= g;
            den /= g;
            return *this;
        }
        SevenToolsFractionConstexpr Fraction& operator-=(const Fraction& other) noexcept {
            if (den != other.den) {
                const T l = lcm(den, other.den);
                den = l;
                num = num * (l / den) - other.num * (l / other.den);
            } else {
                num -= other.num;
            }
            const T g = gcd(den, num);
            num /= g;
            den /= g;
            return *this;
        }
        SevenToolsFractionConstexpr Fraction& operator*=(const Fraction& other) noexcept {
            num *= other.num;
            den *= other.den;
            const T g = gcd(den, num);
            num /= g;
            den /= g;
            return *this;
        }
        SevenToolsFractionConstexpr Fraction& operator/=(const Fraction& other) noexcept {
            *this *= other.reciprocal();
            return *this;
        }

        void swap(Fraction& other) noexcept {
            std::swap(den, other.den);
            std::swap(num, other.num);
        }

        friend constexpr bool operator==(const Fraction& lhs, const Fraction& rhs) noexcept {
            return lhs.num == rhs.num and lhs.den == rhs.den;
        }
        friend constexpr bool operator!=(const Fraction& lhs, const Fraction& rhs) noexcept {
            return lhs.num != rhs.num or lhs.den != rhs.den;
        }
        friend SevenToolsFractionConstexpr bool operator<(const Fraction& lhs, const Fraction& rhs) noexcept {
            if (lhs.den != rhs.den) {
                const T l = lcm(lhs.den, rhs.den);
                return lhs.num * (l / lhs.den) < rhs.num * (l / rhs.den);
            } else {
                return lhs.num == rhs.num;
            }
        }
        friend SevenToolsFractionConstexpr bool operator<=(const Fraction& lhs, const Fraction& rhs) noexcept {
            return lhs < rhs or lhs == rhs;
        }
        friend SevenToolsFractionConstexpr bool operator>(const Fraction& lhs, const Fraction& rhs) noexcept {
            return rhs < lhs;
        }
        friend SevenToolsFractionConstexpr bool operator>=(const Fraction& lhs, const Fraction& rhs) noexcept {
            return lhs > rhs or lhs == rhs;
        }
    };
    template <class T>
    void swap(Fraction<T>& lhs, Fraction<T>& rhs) noexcept {
        lhs.swap(rhs);
    }
}

#endif // FractionByYX