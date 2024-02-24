cmake_minimum_required(
    VERSION 3.19
)

project(
    DataStructures
    VERSION     1.1.0
    DESCRIPTION "Algorithms and Data Structures"
    LANGUAGES   CXX
)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(complexities)

add_subdirectory(libds)

add_subdirectory(tests)

add_subdirectory(cli)
