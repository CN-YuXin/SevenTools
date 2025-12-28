#include <EnvironmentVariables.h>
#include <SystemNames.h>
#include <Path.h>
#if WindowsOS
#include <windows.h>
#include <algorithm>
#include <shlobj.h>
#include <cctype>
#else
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#endif

namespace SevenToolsPrivate {
    using namespace SevenTools;
    struct PathPrivate {
        // use UTF-8
        ::std::string path;
        #if WindowsOS
        // use UTF-16 for Windows
        ::std::wstring pathUtf16;
        #endif
        PathPrivate() = default;
        PathPrivate(const PathPrivate&) = default;
        PathPrivate(PathPrivate&&) = default;
        #if WindowsOS
        PathPrivate(StringView sv): path(sv.data(), sv.size()), pathUtf16(Utf8ToUtf16())
        #else
        PathPrivate(StringView sv): path(sv.data(), sv.size())
        #endif
        {
            #if WindowsOS
            ::std::replace(path.begin(), path.end(), '/', '\\');
            #endif
        }

        PathPrivate& operator=(const PathPrivate& other) {
            path = other.path;
            #if WindowsOS
            pathUtf16 = other.pathUtf16;
            #endif
            return *this;
        }
        PathPrivate& operator=(PathPrivate&& other) {
            path = std::move(other.path);
            #if WindowsOS
            pathUtf16 = std::move(other.pathUtf16);
            #endif
            return *this;
        }
        PathPrivate& operator=(StringView sv) {
            path.assign(sv.data(), sv.size());
            #if WindowsOS
            ::std::replace(path.begin(), path.end(), '/', '\\');
            pathUtf16 = Utf8ToUtf16();
            #endif
            return *this;
        }

        #if WindowsOS
        // for winapi, and sb windows
        ::std::wstring Utf8ToUtf16() {
            if (path.empty())
                return L"";
            int buffSize = MultiByteToWideChar(CP_UTF8, 0, path.data(), path.size(), nullptr, 0);
            if (buffSize == 0)
                return {};
            ::std::wstring utf16;
            utf16.resize(buffSize);
            MultiByteToWideChar(CP_UTF8, 0, path.data(), path.size(), utf16.data(), utf16.size());
            return utf16;
        }
        #endif
    };
}
// TODO: 添加额外函数，例如获取程序的路径，获取存放数据的路径
using namespace SevenToolsPrivate;
namespace SevenTools {
    Path::Path(): pimpl_(new PathPrivate) {
    }
    #if WindowsOS
    Path::Path(WStringView sv): pimpl_(new PathPrivate) {
        pimpl_->pathUtf16.assign(sv.data(), sv.size());
        int buffSize = WideCharToMultiByte(CP_UTF8, 0, sv.data(), sv.size(), nullptr, 0, NULL, NULL);
        if (buffSize == 0)
            return;
        pimpl_->path.resize(buffSize);
        WideCharToMultiByte(CP_UTF8, 0, sv.data(), sv.size(), pimpl_->path.data(), buffSize, NULL, NULL);
    }
    #endif
    Path::Path(const Path& p): pimpl_(new PathPrivate(*p.pimpl_)) {
    }
    Path::Path(Path&& p): pimpl_(new PathPrivate(std::move(*p.pimpl_))) {
    }
    Path::Path(StringView sv): pimpl_(new PathPrivate(sv)) {
    }

    Path& Path::operator=(const Path& other) {
        *pimpl_ = *other.pimpl_;
        return *this;
    }
    Path& Path::operator=(Path&& other) {
        *pimpl_ = std::move(*other.pimpl_);
        return *this;
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
        #if WindowsOS
        return GetFileAttributesW(pimpl_->pathUtf16.c_str()) != INVALID_FILE_ATTRIBUTES;
        #else
        struct stat t;
        return lstat(c_str(), &t) == 0;
        #endif
    }
    bool Path::isAbsolute() const noexcept {
        #if WindowsOS
        return (pimpl_->pathUtf16.size() >= 3
                and ::std::isalpha(pimpl_->pathUtf16[0])
                and pimpl_->pathUtf16[1] == L':'
                and pimpl_->pathUtf16[2] == L'\\')
            or (pimpl_->pathUtf16.size() >= 2
                and pimpl_->pathUtf16[0] == L'\\'
                and pimpl_->pathUtf16[1] == L'\\');
        #else
        return pimpl_->path.empty() ? false : pimpl_->path[0] == '/';
        #endif
    }
    bool Path::isRelative() const noexcept {
        return !isAbsolute();
    }
    void Path::clean() noexcept {
    }

    bool Path::isDirectory() const noexcept {
        #if WindowsOS
        DWORD attr = GetFileAttributesW(pimpl_->pathUtf16.c_str());
        if (attr == INVALID_FILE_ATTRIBUTES)
            return false;
        return attr & FILE_ATTRIBUTE_DIRECTORY;
        #else
        struct stat t;
        if (lstat(c_str(), &t))
            return false;
        return S_ISDIR(t.st_mode);
        #endif
    }
    bool Path::isFile() const noexcept {
        return !isDirectory();
    }
    bool Path::isSymLink() const noexcept {
        #if WindowsOS
        // sb Windows cnmcnmcnmcnmcnmcnm
        if (!exists())
            return false;
        HANDLE le = CreateFileW(
            pimpl_->pathUtf16.c_str(),
            GENERIC_READ,
            FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
            nullptr,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OPEN_REPARSE_POINT,
            nullptr
        );
        if (le == INVALID_HANDLE_VALUE) {
            CloseHandle(le);
            return false;
        }
        FILE_ATTRIBUTE_TAG_INFO info;
        if (!GetFileInformationByHandleEx(le, FileAttributeTagInfo, &info, sizeof(info))) {
            CloseHandle(le);
            return false;
        }
        CloseHandle(le);
        return info.FileAttributes & FILE_ATTRIBUTE_REPARSE_POINT ?
            info.ReparseTag == IO_REPARSE_TAG_SYMLINK :
            false;
        #else
        struct stat t;
        if (lstat(c_str(), &t))
            return false;
        return S_ISLNK(t.st_mode);
        #endif
    }

    // some static functions
    char Path::listSeparator() noexcept {
        #if WindowsOS
        return ';';
        #else
        return ':';
        #endif
    }
    char Path::separator() noexcept {
        #if WindowsOS
        return '\\';
        #else
        return '/';
        #endif
    }
    Path Path::homePath() noexcept {
        #if WindowsOS
        ::std::string str = envGetter("USERPROFILE");
        if (!str.empty())
            return {str};
        // TODO: get home dir by win API
        PWSTR path;
        if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &path))) {
            Path p(path);
            CoTaskMemFree(path);
            return p;
        }
        return {};
        #else
        ::std::string str = envGetter("HOME");
        if (!str.empty())
            return {str};
        uid_t uid = getuid();
        passwd pw, *r;
        size_t size = sysconf(_SC_GETPW_R_SIZE_MAX);
        char* buffer = new char[size != -1 ? size : 1024];
        while (getpwuid_r(uid, &pw, buffer, size, &r) != 0) {
            if (size >= 4096) {
                delete [] buffer;
                return {};
            }
            delete [] buffer;
            size = size * 2 - size / 2;
            buffer = new char[size];
        }
        delete [] buffer;
        return {StringView(pw.pw_dir)};
        #endif
    }

    Path::~Path() {
        delete pimpl_;
    }
}