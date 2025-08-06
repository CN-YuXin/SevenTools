#if !defined(__clang__) && defined(__GNUC__)
    #define CompilerName "gcc"
    #define UsingGCC true
    #define UsingClang false
    #define UsingMSVC false
#elif  defined(__clang__)
    #define CompilerName "clang"
    #define UsingGCC false
    #define UsingClang true
    #define UsingMSVC false
#elif defined(_MSC_VER)
    #define CompilerName "MSVC"
    #define UsingGCC false
    #define UsingClang false
    #define UsingMSVC true
#else
    #define CompilerName "Unknown"
    #define UsingGCC false
    #define UsingClang false
    #define UsingMSVC false
#endif