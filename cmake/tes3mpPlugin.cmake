include(CMakeParseArguments)
function(tes3mp_plugin)
    find_package(TES3MP REQUIRED)
    cmake_parse_arguments(
            ARG
            ""
            "NAME"
            "SRCS;LIBS;INCL"
            ${ARGN}
    )
    add_library(${ARG_NAME} SHARED ${ARG_SRCS})
    set_target_properties(${ARG_NAME} PROPERTIES PREFIX "")
    if (WIN32)
        target_link_libraries(${ARG_NAME} ${TES3MP_LIBRARY})
    endif ()
    target_link_libraries(${ARG_NAME} ${ARG_LIBS})
    target_include_directories(${ARG_NAME} PRIVATE SYSTEM ${ARG_INCL} SYSTEM ${TES3MP_INCLUDES})
endfunction()
