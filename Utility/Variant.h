#ifndef VariantByYX
#define VariantByYX

#include <cstddef>

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

        constexpr std::size_t index() const {
            return idx;
        }
    };
}

#endif // VariantByYX