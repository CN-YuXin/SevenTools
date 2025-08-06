#ifndef IntegerSequenceByYX
#define IntegerSequenceByYX

#include <cstddef>

namespace SevenTools {
    template <class T, T... i>
    struct IntegerSequence {
        using ValueType = T;
        constexpr static std::size_t length() noexcept {
            return sizeof...(i);
        }
    };
    template <std::size_t... i>
    using IndexSequence = IntegerSequence<std::size_t, i...>;

    template <class T, T i, T n, T... is>
    struct SevenToolsMKIntHelper {
        static_assert(n >= 0, "N cannot be negative");
        using Ty = typename SevenToolsMKIntHelper<T, i + 1, n, is..., i>::Ty;
    };
    template <class T, T i, T... is>
    struct SevenToolsMKIntHelper<T, i, i, is...> {
        using Ty = IntegerSequence<T, is...>;
    };

    template <class T, T N>
    using MakeIntegerSequence = typename SevenToolsMKIntHelper<T, 0, N>::Ty;
    template <std::size_t N>
    using MakeIndexSequence   = MakeIntegerSequence<std::size_t, N>;
}

#endif // IntegerSequenceByYX