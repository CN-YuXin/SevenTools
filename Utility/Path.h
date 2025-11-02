#ifndef PathByYx
#define PathByYx

#include <SymbolVisibility.h>
#include <StringView.h>

namespace SevenToolsPrivate {
    struct PathPrivate;
}

namespace SevenTools {
    class SevenToolsApi Path {
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

        bool isDirectory() const noexcept;
        bool isFile() const noexcept;
        bool isSymLink() const noexcept;
        
        static char listSeparator() noexcept;
        static char separator() noexcept;

        ~Path();
    };
}

#endif