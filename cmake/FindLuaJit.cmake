# Once found, defines:
#  LuaJit_FOUND
#  LuaJit_INCLUDE_DIRS
#  LuaJit_LIBRARIES

include(LibFindMacros)

libfind_pkg_detect(LuaJit luajit
        FIND_PATH luajit.h
			HINTS $ENV{LuaJit_HOME}/include
			PATH_SUFFIXES luajit-2.1
        FIND_LIBRARY NAMES luajit-5.1 luajit lua51
			HINTS $ENV{LuaJit_HOME}/lib
        )
libfind_process(LuaJit)

