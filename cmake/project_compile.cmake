target_compile_definitions(cgss PRIVATE __CGSS_BUILDING_DLL__)
target_compile_definitions(hcacc PRIVATE __COMPILE_WITH_CGSS_KEYS=1)
target_compile_definitions(hcaenc_obsolete PRIVATE __COMPILE_WITH_CGSS_KEYS=1)
target_compile_definitions(hca2wav PRIVATE __COMPILE_WITH_CGSS_KEYS=1)
target_compile_definitions(acb2wavs PRIVATE __COMPILE_WITH_CGSS_KEYS=1)
target_compile_definitions(acb2hcas PRIVATE __COMPILE_WITH_CGSS_KEYS=1)

# http://stackoverflow.com/questions/10046114/in-cmake-how-can-i-test-if-the-compiler-is-clang
if (MINGW OR CYGWIN)
    # using GCC
    # http://stackoverflow.com/questions/10369513/dll-linking-via-windows-cgo-gcc-ld-gives-undefined-reference-to-function-e
    # http://www.willus.com/mingw/yongweiwu_stdcall.html
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,--enable-stdcall-fixup,--add-stdcall-alias")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-constexpr,-Wl,--enable-stdcall-fixup,--add-stdcall-alias")
    # https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html
    #set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -s)
    #set(CMAKE_STATIC_LINKER_FLAGS ${CMAKE_STATIC_LINKER_FLAGS} -s)
    #set(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} -s)
    #set(CMAKE_MODULE_LINKER_FLAGS ${CMAKE_MODULE_LINKER_FLAGS} -s)
elseif (MSVC)
    # http://stackoverflow.com/questions/34659795/cmake-how-to-add-a-def-file-which-is-not-a-module-definition-file
    # http://stackoverflow.com/questions/18786690/cmake-for-def-and-nodefaultlib
    set_target_properties(cgss
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
else ()
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-constexpr -Wno-c++11-narrowing")
endif ()
