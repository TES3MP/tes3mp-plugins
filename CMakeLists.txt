cmake_minimum_required(VERSION 3.13)
project(tes3mp_plugins)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

set(CMAKE_CXX_STANDARD 14)

include(cmake/tes3mpPlugin.cmake)
include(cmake/GenFFI.cmake)

add_subdirectory(lua)
add_subdirectory(template)
