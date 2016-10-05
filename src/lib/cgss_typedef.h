#ifndef KAWASHIMA_KSTYPEDEF_H
#define KAWASHIMA_KSTYPEDEF_H

#if defined(_WIN32) || defined(__CYGWIN__) || defined(__MINGW__)
#ifdef LIBCGSS_BUILDING_DLL
#ifdef __GNUC__
#define DLL_PUBLIC __attribute__ ((dllexport))
#else
#define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#endif
#else
#ifdef __GNUC__
#define DLL_PUBLIC __attribute__ ((dllimport))
#else
#define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#endif
#endif
#define DLL_LOCAL
#else
#if __GNUC__ >= 4
#define DLL_PUBLIC __attribute__ ((visibility ("default")))
#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define DLL_PUBLIC
#define DLL_LOCAL
#endif
#endif

#define EXTERN_C extern "C"
#define STDCALL __stdcall

#define KS_API EXTERN_C DLL_PUBLIC STDCALL

typedef signed long long int64;
typedef unsigned long long uint64;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed short int16;
typedef unsigned short uint16;
typedef signed char int8;
typedef unsigned char uint8;

typedef uint32 ubool;

#ifndef TRUE
#define TRUE ((ubool)1)
#endif
#ifndef FALSE
#define FALSE ((ubool)0)
#endif

#ifdef _MSC_VER
#define DECL_CGSS_API(ret_type, name, params) EXTERN_C DLL_PUBLIC ret_type STDCALL name params
#else
#define DECL_CGSS_API(ret_type, name, params) EXTERN_C DLL_PUBLIC STDCALL ret_type name params
#endif
#define CGSS_API_TYPE(ret_type) EXTERN_C ret_type STDCALL

#endif //KAWASHIMA_COMMON_H