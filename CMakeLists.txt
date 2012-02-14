cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(UED-ng)

add_subdirectory(src)
add_subdirectory(test)

add_executable(ued2 main.cxx)

set_target_properties(ued2 PROPERTIES COMPILE_FLAGS "-std=c++0x")

target_link_libraries(ued2 Core)

