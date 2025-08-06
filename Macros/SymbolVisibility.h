#include "SystemNames.h"

#if WindowsOS
    #define ExportSymbol __declspec(dllexport)
    #define HideSymbol
    #define ImportSymbol __declspec(dllimport)
#else
    #define ExportSymbol __attribute__((visibility("default")))
    #define HideSymbol __attribute__((visibility("hidden")))
    #define ImportSymbol
#endif

#ifdef BuildSevenTools
    #if defined(SharedSevenTools)
        #define SevenToolsApi ExportSymbol
    #else
        #define SevenToolsApi
    #endif
#else
    #if defined(SharedSevenTools)
        #define SevenToolsApi ImportSymbol
    #else
        #define SevenToolsApi
    #endif
#endif