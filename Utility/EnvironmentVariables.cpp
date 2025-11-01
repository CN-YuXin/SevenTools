#include <EnvironmentVariables.h>
#include <SystemNames.h>
#include <mutex>

namespace SevenTools {
    ::std::string getEnv(const char* key) noexcept {
        static ::std::mutex mtx;
        ::std::lock_guard<::std::mutex> lg(mtx);
        
        const char* const value = ::std::getenv(key);
        if (value)
            return value;
        return "";
    }

    EnvGetterType envGetter = getEnv;
}