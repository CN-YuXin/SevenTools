#ifndef EnvironmentVariablesByYX
#define EnvironmentVariablesByYX

#include <SymbolVisibility.h>
#include <functional>
#include <string>

namespace SevenTools {
    using EnvGetterType = ::std::function<::std::string(const char*)>;

    /* 为了多库协同 */
    SevenToolsApi extern EnvGetterType envGetter;

    SevenToolsApi ::std::string getEnv(const char*) noexcept;
}

#endif // EnvironmentVariablesByYX