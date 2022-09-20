#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libtcod::libtcod" for configuration "Debug"
set_property(TARGET libtcod::libtcod APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libtcod::libtcod PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C;CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/libtcod.a"
  )

list(APPEND _cmake_import_check_targets libtcod::libtcod )
list(APPEND _cmake_import_check_files_for_libtcod::libtcod "${_IMPORT_PREFIX}/debug/lib/libtcod.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
