#ifndef PathByYx
#define PathByYx

#include <StringView.h>

namespace SevenToolsPrivate {
    struct PathPrivate;
}

namespace SevenTools {
    class Path {
        SevenToolsPrivate::PathPrivate* pimpl_;
        Path();
        Path(const Path&);
        Path(Path&&);
        Path(StringView sv);

        Path& operator=(const Path&);
        Path& operator=(Path&&);

        const char* c_str() const noexcept;
        ::std::string toString() const;
        bool empty() const noexcept;

        bool exists() const noexcept;
        
        static char listSeparator() noexcept;

        ~Path();
    };
}

#endif