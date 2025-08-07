#ifndef MetaUtilsByYX
#define MetaUtilsByYX

#include <cstddef>

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

#endif // MetaUtilsByYX