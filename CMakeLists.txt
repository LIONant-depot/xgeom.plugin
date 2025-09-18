cmake_minimum_required(VERSION 3.10)
project(xgeom_compiler LANGUAGES C CXX)
set(TARGET_PROJECT "xgeom_compiler")
set(COMPONENT_REGISTRY "")


# disable strict string conformance. AMD compresator requires it!
if(MSVC)
  add_compile_options(/Zc:strictStrings-)
endif()

include(FetchContent)
FetchContent_Declare(
  xcmake_tools
  GIT_REPOSITORY https://github.com/LIONant-depot/xcmake_tools.git
  GIT_TAG main
  GIT_SHALLOW TRUE
  SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/xcmake_tools"
)
FetchContent_MakeAvailable(xcmake_tools)
include(${CMAKE_BINARY_DIR}/_deps/xcmake_tools/Common.cmake)

add_executable(${TARGET_PROJECT}
  "source/Compiler/main.cpp"
)

source_group("Geom_Compiler" FILES
  "source/Compiler/main.cpp"
)

add_subdirectory("build/dependency" "${CMAKE_CURRENT_BINARY_DIR}/xgeom_compiler")

ProcessComponents()