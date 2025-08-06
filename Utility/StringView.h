#ifndef StringViewByYX
#define StringViewByYX

#include <CppVersions.h>
#include <type_traits>
#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <limits>
#include <string>

namespace SevenTools {
    template <class C, class CTraits = std::char_traits<C>>
    class BasicStringView {
        static_assert(
            std::is_same<C, typename CTraits::char_type>::value and
            !std::is_array<C>::value,"Illegal type");
    public:
        using ValueType      = const C;
        using TraitsType     = CTraits;
        using ConstIterator  = const C*;
        using Iterator       = ConstIterator;
        using SizeType       = std::size_t;
        using ConstReference = const C&;
        using Reference      = ConstReference;
        using ConstPointer   = const C*;
        using Pointer        = ConstPointer;

        constexpr static SizeType npos = -1;

        constexpr BasicStringView() noexcept: begin_(nullptr), length_(0) {
        }
        constexpr BasicStringView(const std::basic_string<C>& t) noexcept:
        begin_(t.data()),
        length_(t.size()) {}
        constexpr BasicStringView(const BasicStringView& other) noexcept = default;
        constexpr BasicStringView(const C* b, SizeType n) noexcept:
        begin_(b),
        length_(n) {}
        #if HasCpp14
        constexpr
        #endif
        #if HasCpp17
        BasicStringView(const C* str) noexcept: begin_(str), length_(CTraits::length(str)) {
        }
        #else
        BasicStringView(const C* str) noexcept: begin_(str), length_(0) {
            SizeType n = 0;
            while (*str)
                ++n;
            length_ = n;
        }
        #endif
        BasicStringView(std::nullptr_t) = delete;

        #if HasCpp14
        constexpr
        #endif
        BasicStringView& operator=(const BasicStringView&) noexcept = default;

        constexpr SizeType size() const noexcept {
            return length_;
        }
        constexpr SizeType length() const noexcept {
            return length_;
        }
        constexpr SizeType maxSize() const noexcept {
            return std::numeric_limits<SizeType>::max();
        }
        constexpr bool empty() const noexcept {
            return length_ == 0;
        }

        constexpr Iterator begin() const noexcept {
            return begin_;
        }
        constexpr Iterator end() const noexcept {
            return begin_ + length_;
        }

        constexpr Reference operator[](SizeType i) const noexcept {
            return begin_[i];
        }
        #if HasCpp14
        constexpr
        #endif
        Reference at(SizeType i) const {
            if (i >= length_)
                throw std::out_of_range("i is too big");
            return begin_[i];
        }
        constexpr Reference front() const noexcept {
            return *begin_;
        }
        constexpr Reference operator*() const noexcept {
            return *begin_;
        }
        constexpr Reference back() const noexcept {
            return begin_[length_ - 1];
        }

        // [begin(), begin() + length_)
        constexpr ConstPointer data() const noexcept {
            return begin_;
        }

        #if HasCpp14
        constexpr
        #endif
        BasicStringView subStr(SizeType pos, SizeType count = npos) const {
            if (pos > length_)
                throw std::out_of_range("pos cannot be greater than length()");
            return {begin_ + pos, std::min(count, length_ - pos)};
        }
        #if HasCpp17
        constexpr
        #endif
        int compare(const BasicStringView& sv) const noexcept {
            const int r = CTraits::compare(begin_, sv.begin_, std::min(length_, sv.length_));
            if (r != 0)
                return r < 0 ? -1 : 1;
            if (length_ < sv.length_)
                return -1;
            if (length_ > sv.length_)
                return 1;
            return 0;
        }
        #if HasCpp17
        constexpr
        #endif
        int compare(SizeType pos, const BasicStringView& sv, SizeType count = npos) const {
            return subStr(pos, count).compare(sv);
        }

        #if HasCpp17
        constexpr
        #endif
        bool startsWith(const BasicStringView& sv) const noexcept {
            return subStr(0, std::min(length_, sv.length_)) == sv;
        }
        constexpr bool startsWith(C ch) const noexcept {
            return !empty() and CTraits::eq(front(), ch);
        }
        #if HasCpp17
        constexpr
        #endif
        bool endsWith(const BasicStringView& sv) const noexcept {
            return length_ >= sv.length_ and subStr(length_ - sv.length_) == sv;
        }
        constexpr bool endsWith(C ch) const noexcept {
            return !empty() and CTraits::eq(back(), ch);
        }

        #if HasCpp17
        constexpr
        #endif
        bool contains(const BasicStringView& sv) const noexcept {
            return find(sv) != npos;
        }
        #if HasCpp17
        constexpr
        #endif
        bool contains(C ch) const noexcept {
            return find(ch) != npos;
        }

        /*
            我找不到什么比这个方法更快的算法了，这个 BF 快
            纯粹是因为 std::char_traits，其他算法要想快
            得充分利用 std::char_traits 的速度

            ╮(￣▽￣")╭
        */
        #if HasCpp17
        constexpr
        #endif
        SizeType find(const BasicStringView& sv, SizeType pos = 0) const noexcept {
            if (sv.length_ == 0)
                return pos <= length_ ? pos : npos;
            if (pos < length_) {
                SizeType rlen = length_ - pos;
                Iterator f = begin_ + pos;
                const Iterator ed = begin_ + length_;
                while (rlen >= sv.length_) {
                    f = CTraits::find(f, rlen - sv.length_ + 1, *sv.begin_);
                    if (!f)
                        return npos;

                    if (CTraits::compare(f, sv.begin_, sv.length_) == 0)
                        return f - begin_;
                    rlen = ed - ++f;
                }
            }
            return npos;
        }

        #if HasCpp17
        constexpr
        #endif
        SizeType find(C ch, SizeType pos = 0) const noexcept {
            if (pos < length_) {
                const C* const r = CTraits::find(begin_ + pos, length_ - pos, ch);
                if (r)
                    return r - begin_;
            }
            return npos;
        }
        #if HasCpp17
        constexpr
        #endif
        SizeType rfind(const BasicStringView& sv, SizeType pos = 0) const noexcept {
            if (sv.length_ <= length_) {
                pos = std::min(length_ - sv.length_, pos);
                do {
                    if (compare(pos, sv, sv.length_) == 0)
                        return pos;
                } while (pos-- > 0);
            }
            return npos;
        }
        #if HasCpp14
        constexpr
        #endif
        SizeType rfind(C ch, SizeType pos = 0) const noexcept {
            if (length_ > 0) {
                pos = std::min(pos, length_ - 1);
                do {
                    if (CTraits::eq(begin_[pos], ch))
                        return pos;
                } while (pos-- > 0);
            }
            return npos;
        }
        #if HasCpp17
        constexpr
        #endif
        SizeType findFirstOf(const BasicStringView& sv, SizeType pos = 0) const noexcept {
            if (sv.length_ > 0) {
                while (pos < length_) {
                    if (CTraits::find(sv.begin_, sv.length_, begin_[pos]))
                        return pos;
                    ++pos;
                }
            }
            return npos;
        }
        #if HasCpp17
        constexpr
        #endif
        SizeType findFirstNotOf(const BasicStringView& sv, SizeType pos = 0) const noexcept {
            if (sv.length_ == 0)
                return pos >= length_ ? npos : pos;
            while (pos < length_) {
                if (!CTraits::find(sv.begin_, sv.length_, begin_[pos]))
                    return pos;
                ++pos;
            }
            return npos;
        }
        #if HasCpp17
        constexpr
        #endif
        SizeType findLastOf(const BasicStringView& sv, SizeType pos = 0) const noexcept {
            if (sv.length_ and length_) {
                pos = std::min(pos, length_ - 1);
                do {
                    if (CTraits::find(sv.begin_, sv.length_, begin_[pos]))
                        return pos;
                } while (pos-- > 0);
            }
            return npos;
        }
        #if HasCpp17
        constexpr
        #endif
        SizeType findLastNotOf(const BasicStringView& sv, SizeType pos = 0) const noexcept {
            if (sv.length_ == 0)
                return pos >= length_ ? npos : pos;
            for (;pos < length_;++pos) {
                if (!CTraits::find(sv.begin_, sv.length_, begin_[pos]))
                    return pos;
            }
            return npos;
        }

        #if HasCpp20
        constexpr
        #endif
        void swap(BasicStringView& other) noexcept {
            std::swap(begin_,  other.begin_);
            std::swap(length_, other.length_);
        }
    private:
        Iterator begin_;
        SizeType length_;
    };

    template <class C>
    #if HasCpp17
    constexpr
    #endif
    bool operator==(const BasicStringView<C>& lhs, const BasicStringView<C>& rhs) noexcept {
        return lhs.compare(rhs) == 0;
    }
    template <class C>
    #if HasCpp17
    constexpr
    #endif
    bool operator!=(const BasicStringView<C>& lhs, const BasicStringView<C>& rhs) noexcept {
        return lhs.compare(rhs) != 0;
    }
    using StringView  = BasicStringView<char>;
    using WStringView = BasicStringView<wchar_t>;
}

#endif // StringViewByYX