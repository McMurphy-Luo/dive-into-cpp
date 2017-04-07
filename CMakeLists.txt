cmake_minimum_required(VERSION 3.5)

project(hello C CXX)
set(source_dir ${PROJECT_SOURCE_DIR}/src)
set(include_dir ${source_dir}/include)
set(exe_output_dir ${PROJECT_BINARY_DIR}/bin)
set(lib_output_dir ${PROJECT_BINARY_DIR}/lib)
find_package(Boost REQUIRED)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++17 -Werror -Wall -O0")


include_directories(${include_dir})
include_directories(${BOOST_INCLUDE_DIRS})
list(APPEND source
        ${source_dir}/main.cpp
        ${source_dir}/Socket.cpp
        ${source_dir}/LogStream.cpp
        ${source_dir}/CErrorLog.cpp
        ${include_dir}/Socket.h
        ${include_dir}/LogStream.h
        ${include_dir}/CErrorLog.h
        )

add_executable(hello ${source})
set_property(TARGET hello PROPERTY RUNTIME_OUTPUT_DIRECTORY ${exe_output_dir})
