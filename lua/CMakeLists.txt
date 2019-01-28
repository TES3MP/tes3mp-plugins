project(PluginLua C)

find_package(LuaJit REQUIRED)

set(PROJECT_NAME pluginlua)

tes3mp_plugin(NAME ${PROJECT_NAME}
        SRCS lua.c
        LIBS ${LuaJit_LIBRARIES} ${LIBFFI_LIBRARIES}
        INCL ${LuaJit_INCLUDE_DIRS} ${LIBFFI_INCLUDE_DIR}
        )

file(GLOB FUNC_HDRS "${TES3MP_INCLUDES}/Functions/*.h")

set(EXCLUDE_API Public Timer CACHE INTERNAL "")

target_genffi(TARGET ${PROJECT_NAME}
        EXTENSION "lua"
        OUTPUT_DIR "Functions"
        NAMESPACE "tes3mpApi" MODULE "tes3mp"
        HEADERS ${FUNC_HDRS}
        EXCLUDE_FILES ${EXCLUDE_API}
        )

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/api.lua ${CMAKE_CURRENT_BINARY_DIR}
        )
