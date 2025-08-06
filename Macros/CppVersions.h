#if __cplusplus >= 201103L
    #define HasCpp11 true
#else
    #define HasCpp11 false
#endif

#if __cplusplus >= 201402L
    #define HasCpp14 true
#else
    #define HasCpp14 false
#endif

#if __cplusplus >= 201703L
    #define HasCpp17 true
#else
    #define HasCpp17 false
#endif

#if __cplusplus >= 202002L
    #define HasCpp20 true
#else
    #define HasCpp20 false
#endif

#if __cplusplus >= 202302L
    #define HasCpp23 true
#else
    #define HasCpp23 false
#endif