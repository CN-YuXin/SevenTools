#include <SystemNames.h>
#include <algorithm>
#include <Path.h>

#if WindowsOS
#include <windows.h>
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

namespace SevenToolsPrivate {
    using namespace SevenTools;
    struct PathPrivate {
        ::std::string path;
        PathPrivate() = default;
        PathPrivate(const PathPrivate&) = default;
        PathPrivate(PathPrivate&&) = default;
        PathPrivate(StringView sv): path(sv.data(), sv.size()) {
            #if WindowsOS
            ::std::replace(path.begin(), path.end(), '/', '\\');
            #else
            ::std::replace(path.begin(), path.end(), '\\', '/');
            #endif
        }
    };
}
using namespace SevenToolsPrivate;
namespace SevenTools {
    Path::Path(): pimpl_(new PathPrivate) {
    }
    Path::Path(const Path& p): pimpl_(new PathPrivate(*p.pimpl_)) {
    }
    Path::Path(Path&& p): pimpl_(new PathPrivate(std::move(*p.pimpl_))) {
    }
    Path::Path(StringView sv): pimpl_(new PathPrivate(sv)) {
    }

    const char* Path::c_str() const noexcept {
        return pimpl_->path.c_str();
    }
    ::std::string Path::toString() const {
        return pimpl_->path;
    }
    bool Path::empty() const noexcept {
        return pimpl_->path.empty();
    }

    bool Path::exists() const noexcept {
        #if UnknownOS
        return false;
        #elif WindowsOS
        return GetFileAttributesA(c_str()) != INVALID_FILE_ATTRIBUTES;
        #else
        struct stat t;
        return lstat(c_str(), &t) == 0;
        #endif
    }

    char Path::listSeparator() noexcept {
        #if WindowsOS
        return ';';
        #else
        return ':';
        #endif
    }

    Path::~Path() {
        delete pimpl_;
    }
}