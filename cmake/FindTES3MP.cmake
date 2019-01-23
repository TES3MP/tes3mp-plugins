if (WIN32)
    find_library(TES3MP_LIBRARY_RELEASE NAMES newNative newNative.dll
            PATHS
            ENV LD_LIBRARY_PATH
            ENV LIBRARY_PATH
            /usr/lib64
            /usr/lib
            /usr/local/lib64
            /usr/local/lib
            /opt/local/lib
            $ENV{TES3MP_ROOT}/lib
            $ENV{TES3MP_ROOT}/lib/Release
            )

    find_library(TES3MP_LIBRARY_DEBUG NAMES newNative newNative.dll
            PATHS
            HINTS
            ENV LD_LIBRARY_PATH
            ENV LIBRARY_PATH
            /usr/lib64
            /usr/lib
            /usr/local/lib64
            /usr/local/lib
            /opt/local/lib
            $ENV{TES3MP_ROOT}/lib
            $ENV{TES3MP_ROOT}/lib/Debug
            )
endif ()

find_path(TES3MP_INCLUDES api.h
        ENV CPATH
        /usr/include
        /usr/local/include
        /opt/local/include
        $ENV{TES3MP_ROOT}/include
        )

if (TES3MP_INCLUDES)
    if (WIN32 AND NOT TES3MP_LIBRARY_RELEASE)
        set(TES3MP_FOUND FALSE)
    else ()
        set(TES3MP_FOUND TRUE)
    endif ()
endif ()

if (TES3MP_FOUND)
    if (WIN32)
        if (CMAKE_CONFIGURATION_TYPES OR CMAKE_BUILD_TYPE)
            set(TES3MP_LIBRARY optimized ${TES3MP_LIBRARY_RELEASE} debug ${TES3MP_LIBRARY_DEBUG})
        else ()
            # if there are no configuration types and CMAKE_BUILD_TYPE has no value
            # then just use the release libraries
            SET(TES3MP_LIBRARY ${TES3MP_LIBRARY_RELEASE})
        endif ()
    endif ()
    if (NOT TES3MP_FIND_QUIETLY)
        if (WIN32)
            message(STATUS "Found TES3MP_LIBRARY_RELEASE: ${TES3MP_LIBRARY_RELEASE}")
        endif ()
        message(STATUS "Found TES3MP_INCLUDES: ${TES3MP_INCLUDES}")
    endif ()
else ()
    if (TES3MP_FIND_REQUIRED)
        message(FATAL_ERROR "Could not find TES3MP API")
    endif ()
endif ()
