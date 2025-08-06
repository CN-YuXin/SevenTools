# StringView.h

提供在 C++17 前可用的 `std::basic_string_view`

## 类

| 标识符 | 介绍 |
| :-    | :-  |
| [`StringView`](../StringView.md) | C++17 前可用的 `std::basic_string_view` |

## 概要

```cpp
namespace SevenTools {
    template <class C, class CTraits = std::char_traits<C>>
    class BasicStringView {
    public:
        using ValueType      = C;
        using TraitsType     = CTraits;
        using ConstIterator  = const C*;
        using Iterator       = ConstIterator;
        using SizeType       = std::size_t;
        using ConstReference = const C&;
        using Reference      = ConstReference;
        using ConstPointer   = const C*;
        using Pointer        = ConstPointer;

        constexpr static SizeType npos = -1;

        constexpr BasicStringView() noexcept;
        constexpr BasicStringView(const std::basic_string<C>& t) noexcept;
        constexpr BasicStringView(const BasicStringView& other) noexcept = default;
        constexpr BasicStringView(const C* b, SizeType n) noexcept;
        constexpr BasicStringView(const C(&r)[N]) noexcept;
        BasicStringView(const C* str) noexcept;// (C++14 起 constexpr)
        BasicStringView(std::nullptr_t) = delete;

        BasicStringView& operator=(const BasicStringView&) noexcept = default;// (C++14 起 constexpr)

        constexpr SizeType size() const noexcept;
        constexpr SizeType length() const noexcept;

        constexpr SizeType maxSize() const noexcept;
        constexpr bool empty() const noexcept;

        constexpr Iterator begin() const noexcept;
        constexpr Iterator end() const noexcept;

        constexpr Reference operator[](SizeType i) const noexcept;
        Reference at(SizeType i) const;// (C++14 起 constexpr)
        constexpr Reference front() const noexcept;
        constexpr Reference operator*() const noexcept;
        constexpr Reference back() const noexcept;
        constexpr ConstPointer data() const noexcept;

        BasicStringView subStr(SizeType pos, SizeType count = npos) const;// (C++14 起 constexpr)
        int compare(const BasicStringView& sv) const noexcept;// (C++17 起 constexpr)
        int compare(SizeType pos, const BasicStringView& sv, SizeType count = npos) const;// (C++17 起 constexpr)
        bool startsWith(const BasicStringView& sv) const noexcept;// (C++17 起 constexpr)
        constexpr bool startsWith(C ch) const noexcept;
        bool endsWith(const BasicStringView& sv) const noexcept;// (C++17 起 constexpr)
        constexpr bool endsWith(C ch) const noexcept;
        
        bool contains(const BasicStringView& sv) const noexcept;// (C++17 起 constexpr)
        bool contains(C ch) const noexcept;// (C++17 起 constexpr)
        SizeType find(const BasicStringView& sv, SizeType pos = 0) const noexcept;// (C++17 起 constexpr)
        SizeType find(C ch, SizeType pos = 0) const noexcept;// (C++17 起 constexpr)
        SizeType rfind(const BasicStringView& sv, SizeType pos = 0) const noexcept;// (C++17 起 constexpr)
        SizeType rfind(C ch, SizeType pos = 0) const noexcept;// (C++14 起 constexpr)
        SizeType findFirstOf(const BasicStringView& sv, SizeType pos = 0) const noexcept;// (C++17 起 constexpr)
        SizeType findFirstNotOf(const BasicStringView& sv, SizeType pos = 0) const noexcept;// (C++17 起 constexpr)
        SizeType findLastOf(const BasicStringView& sv, SizeType pos = 0) const noexcept;// (C++17 起 constexpr)
        SizeType findLastNotOf(const BasicStringView& sv, SizeType pos = 0) const noexcept;// (C++17 起 constexpr)

        void swap(BasicStringView& other) noexcept;// (C++20 起 constexpr)

        friend bool operator==(const BasicStringView& lhs, const BasicStringView& rhs) noexcept;// (C++17 起 constexpr)
        friend bool operator!=(const BasicStringView& lhs, const BasicStringView& rhs) noexcept;// (C++17 起 constexpr)
    };
    using StringView  = BasicStringView<char>;
    using WStringView = BasicStringView<wchar_t>;
}
```