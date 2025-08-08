#ifndef VariantByYX
#define VariantByYX

#include <MetaUtils.h>
#include <cstddef>
#include <utility>

namespace SevenTools {
    template <class... Types>
    class Variant {
        template <class Head, class... Tail>
        union VariantStorage {
            Head head;
            VariantStorage<Tail...> tail;

            VariantStorage() {}
            ~VariantStorage() {}
        };
        template <class Head>
        union VariantStorage<Head> {
            Head head;

            VariantStorage() {}
            ~VariantStorage() {}
        };
        VariantStorage<Types...> storage;

        // index，活跃成员的索引
        std::size_t idx;
    public:
        constexpr Variant(): idx(0) {
            new (&storage) TypeAtAlias<0, Types...> ();
        }
        template <std::size_t i, class... Args>
        constexpr Variant(InPlaceIndex<i>, Args&&... args): idx(i) {
            new (&storage) TypeAtAlias<0, Types...> (std::forward<Args>(args)...);
        }

        constexpr std::size_t index() const {
            return idx;
        }

        template <std::size_t i>
        constexpr TypeAtAlias<i, Types...> get() const {
            // TODO: 实现异常类并在此通过 idx 检查
            return *static_cast<TypeAtAlias<i, Types...>*>(&storage);
        }
    };
}

#endif // VariantByYX