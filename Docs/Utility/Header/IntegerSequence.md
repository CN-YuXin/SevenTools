# IntegerSequence.h

提供等价于 `std::integer_sequence` 的类模板(不同的是此类目标只需 C++11 即可使用)

## 类

| 标识符 | 介绍 |
| :-    | :-  |
| [`IntegerSequence`](../IntegerSequence.md) | 任意类型的整数序列 |

## 概要

```cpp
namespace SevenTools {
    template <class T, T... i>
    struct IntegerSequence {
        using ValueType = T;
        constexpr static std::size_t size() noexcept {
            return sizeof...(i);
        }
    };
    template <std::size_t... i>
    using IndexSequence = IntegerSequence<std::size_t, i...>;

    template <class T, T N>
    using MakeIntegerSequence = IntegerSequence<T, /* 见介绍 */>;
    template <std::size_t N>
    using MakeIndexSequence = MakeIntegerSequence<std::size_t, N>;
}
```