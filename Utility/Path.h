#ifndef PathByYx
#define PathByYx

#include <SymbolVisibility.h>
#include <StringView.h>

namespace SevenToolsPrivate {
    struct PathPrivate;
}

namespace SevenTools {
    // 仅文件系统上的文件路径，不支持 URL 类路径
    class SevenToolsApi Path {
        SevenToolsPrivate::PathPrivate* pimpl_;
        #if WindowsOS
        Path(WStringView sv);
        #endif
    public:
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
        bool isAbsolute() const noexcept;
        bool isRelative() const noexcept;
        void clean() noexcept;

        bool isDirectory() const noexcept;
        bool isFile() const noexcept;
        bool isSymLink() const noexcept;
        
        SevenToolsApi static char listSeparator() noexcept;
        SevenToolsApi static char separator() noexcept;
        SevenToolsApi static Path homePath() noexcept;

        ~Path();
    };
}

#endif