cmake_minimum_required(VERSION 3.9)
project(untitled3 C)

set(CMAKE_C_STANDARD 99)


find_package(PkgConfig REQUIRED)
pkg_check_modules(x11 REQUIRED x11)

include_directories(${x11_INCLUDE_DIRS})
link_directories(${x11_LIBRARY_DIRS})


add_definitions(${x11_CFLAGS_OTHER})


add_executable(untitled3 chap1.c connect.c connect.h size_hints.c size_hints.h wm_hints.c wm_hints.h window.c window.h)

target_link_libraries(untitled3 ${x11_LIBRARIES})