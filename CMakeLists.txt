cmake_minimum_required(VERSION 3.11)

project(kmeans)

# optimization for dev environments
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# project version
set(MAJOR 0)
set(MINOR 1)
set(REMAP_VERSION ${MAJOR}.${MINOR})

# CXX and C versions
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)

# cmake modules path spec
list(APPEND CMAKE_MODULE_PATH "$ENV{CMAKE_MODULE_PATH}")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# cmake binary path spec
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# clang-tidy rules (good dev practice)
set(CMAKE_CXX_CLANG_TIDY
        clang-tidy -p pwd
        --checks=-*,readability-*,clang-analyzer-*,performance-*)

# build shared library (on)
option(BUILD_SHARED_LIBS "Build Shared Library" ON)

# project paths spec
set(PROJECT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(INCLUDE_DIR ${PROJECT_DIR}/include)
set(SRC_DIR ${PROJECT_DIR}/src)

# define project target
add_executable(kmeans
    ${SRC_DIR}/main.cpp
    )

target_include_directories(kmeans PRIVATE
    ${INCLUDE_DIR}
    ${EXT_DIR}
    )

# graph and colorize '*.csv' data before and after clustering
option(GRAPH "view graphs" ON)

if(GRAPH)
    add_custom_command(TARGET kmeans
            POST_BUILD
            COMMAND ./build/bin/kmeans
            COMMAND /bin/python3 ./scripts/graph.py
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
endif()
