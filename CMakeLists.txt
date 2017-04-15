cmake_minimum_required(VERSION 3.5)

project(hello C CXX)
set(source_dir ${PROJECT_SOURCE_DIR}/src)
set(exe_output_dir ${PROJECT_BINARY_DIR}/bin)
set(lib_output_dir ${PROJECT_BINARY_DIR}/lib)
find_package(Boost REQUIRED)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++11 -Werror -Wall -O0")


include_directories(${source_dir})
include_directories(${BOOST_INCLUDE_DIRS})
list(APPEND source
        ${source_dir}/filesystem/Directory.h
        ${source_dir}/filesystem/Directory.cpp
        ${source_dir}/logstream/LogStream.h
        ${source_dir}/logstream/CErrorLog.h
        ${source_dir}/logstream/LogStream.cpp
        ${source_dir}/logstream/CErrorLog.cpp
        ${source_dir}/socket/Socket.h
        ${source_dir}/socket/Socket.cpp
        )

add_executable(filesystem_test ${source} test/filesystem/main.cpp)
set_property(TARGET filesystem_test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${exe_output_dir})