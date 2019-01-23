# FindLibFFI
#
#  LIBFFI_FOUND - system has LibFFI
#  LIBFFI_INCLUDE_DIRS - the LibFFI include directories
#  LIBFFI_LIBRARIES - Link these to use LibFFI

if (NOT WIN32)
    find_package(PkgConfig QUIET)
    pkg_check_modules(PC_LIBFFI QUIET libffi)
endif ()

find_path(LIBFFI_INCLUDE_DIR ffi.h
        HINTS 
		${PC_LIBFFI_INCLUDEDIR}
		${PC_LIBFFI_INCLUDE_DIRS}
		$ENV{LIBFFI_HOME}/include
        )

find_library(LIBFFI_LIBRARIES NAMES ffi libffi
        HINTS 
		${PC_LIBFFI_LIBDIR}
		${PC_LIBFFI_LIBRARY_DIRS}
		$ENV{LIBFFI_HOME}/lib
        )
		
mark_as_advanced(LIBFFI_INCLUDE_DIR LIBFFI_LIBRARIES)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibFFI DEFAULT_MSG
        LIBFFI_LIBRARIES LIBFFI_INCLUDE_DIR
        )