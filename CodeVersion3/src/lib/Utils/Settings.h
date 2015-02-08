#ifndef __FAARAY_SETTINGS_H__
#define __FAARAY_SETTINGS_H__

#if defined _WIN32 || defined __CYGWIN__
    typedef unsigned __int32 uint32_t;
    #ifdef FAARAY_BUILDING_DLL
        #ifdef __GNUC__
            #define FAARAY_DLL_PUBLIC __attribute__ ((dllexport))
        #else
            #define FAARAY_DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #else
        #ifdef __GNUC__
            #define FAARAY_DLL_PUBLIC __attribute__ ((dllimport))
        #else
            #define FAARAY_DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #endif
    #define DLL_LOCAL
#else
    #if __GNUC__ >= 4
        #define FAARAY_DLL_PUBLIC __attribute__ ((visibility ("default")))
        #define FAARAY_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
    #else
        #define FAARAY_DLL_PUBLIC
        #define FAARAY_DLL_LOCAL
    #endif
#endif


#endif

