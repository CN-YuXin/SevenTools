#if defined(_WIN32)
    #define SystemName "Windows"
    #define WindowsOS true
#elif defined(__ANDROID__)
    #define SystemName "Android"
    #define AndroidOS true
#elif defined(__linux__) or defined(linux) or defined(__gnu_linux__) or defined(__linux)
    #define SystemName "Linux"
    #define LinuxOS true
#elif defined(__APPLE__) and defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_OS_IOS
        #define SystemName "iOS"
        #define iOS true
    #elif TARGET_OS_MAC
        #define SystemName "MacOS"
        #define MacOS true
    #else
        #define SystemName "Unknown"
    #endif
#elif defined(__unix) or defined(__unix__) or defined(unix)
    #define SystemName "Unix"
    #define UnixOS true
#else
    #define SystemName "Unknown"
#endif