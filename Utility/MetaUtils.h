#ifndef MetaUtilsByYX
#define MetaUtilsByYX

#include <CppVersions.h>
#include <cstddef>

namespace SevenTools {
    // 主模板仅在 Types 为空时被使用
    template <std::size_t idx, class... Types>
    struct TypeAt {
        static_assert(idx < sizeof...(Types), "Idx too large");
    };
    template <std::size_t idx, class T, class... Types>
    struct TypeAt<idx, T, Types...> {
        static_assert(idx < sizeof...(Types) + 1, "Idx too large");
        using Type = typename TypeAt<idx - 1, Types...>::Type;
    };
    template <class T, class... Types>
    struct TypeAt<0, T, Types...> {
        using Type = T;
    };
    template <std::size_t idx, class... Types>
    using TypeAtAlias = typename TypeAt<idx, Types...>::Type;


    struct InPlace {explicit InPlace() = default;};
    template <class T>
    struct InPlaceType {explicit InPlaceType() = default;};
    template <std::size_t idx>
    struct InPlaceIndex {explicit InPlaceIndex() = default;};
    
    // inline 变量需要 C++17
    #if HasCpp17
    constexpr inline InPlace inPlace{};
    template <class T>
    constexpr inline InPlaceType<T> inPlaceType{};
    template <std::size_t idx>
    constexpr inline InPlaceIndex<idx> inPlaceIndex{};
    #endif
}

#endif // MetaUtilsByYX