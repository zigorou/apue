cmake_minimum_required (VERSION 2.6)
project (apue)

include_directories("${PROJECT_SOURCE_DIR}/lib")
include_directories("${PROJECT_SOURCE_DIR}/include")
add_subdirectory(lib)
add_subdirectory(include)
add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)


