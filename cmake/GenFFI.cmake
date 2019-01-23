set (GENFFI_EXE genffi CACHE FILEPATH "Path to GenFFI executable")

include(CMakeParseArguments)

macro(target_genffi)
    cmake_parse_arguments(
            ARG
            ""
            "TARGET;OUTPUT_DIR;NAMESPACE;MODULE;EXTENSION"
            "EXCLUDE_FILES;HEADERS"
            ${ARGN}
    )

    if (EXISTS ${GENFFI_EXE})
        foreach (file ${ARG_HEADERS})
            get_filename_component(ITEM ${file} NAME)
            get_filename_component(ITEM_WE ${file} NAME_WE)

            if (NOT ${ITEM_WE} IN_LIST ARG_EXCLUDE_FILES)
                add_custom_command(TARGET ${ARG_TARGET} POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E make_directory ${ARG_OUTPUT_DIR}
                        COMMAND ${GENFFI_EXE} ${file} ${ARG_OUTPUT_DIR}/${ITEM_WE}.${ARG_EXTENSION} ${ARG_NAMESPACE} ${ARG_MODULE}
                        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                        )
            endif ()
        endforeach ()
    else ()
        message(STATUS "GenFFI not found. Skipping FFI generation process.")
    endif ()
endmacro()

