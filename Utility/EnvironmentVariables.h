#ifndef EnvironmentVariablesByYX
#define EnvironmentVariablesByYX

#include <functional>
#include <string>

namespace SevenTools {
    using EnvGetterType = ::std::function<::std::string(const char*)>;

    /* 为了多库协同 */
    extern EnvGetterType envGetter;

    ::std::string getEnv(const char*) noexcept;
}

#endif // EnvironmentVariablesByYX