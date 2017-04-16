cmake_minimum_required(VERSION 3.5)
project(hello C CXX)
set(CMAKE_CXX_STANDARD 11)
set(source_dir ${PROJECT_SOURCE_DIR}/src)
set(exe_output_dir ${PROJECT_BINARY_DIR}/bin)
set(lib_output_dir ${PROJECT_BINARY_DIR}/lib)
find_package(Boost REQUIRED)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -O0")
include_directories(${source_dir})
include_directories(${BOOST_INCLUDE_DIRS})
list(APPEND filesystem_source
        ${source_dir}/filesystem/Directory.h
        ${source_dir}/filesystem/Directory.cpp
        ${source_dir}/filesystem/File.h
        ${source_dir}/filesystem/File.cpp
        )
list(APPEND logstream_source
        ${source_dir}/logstream/LogStream.h
        ${source_dir}/logstream/CErrorLog.h
        ${source_dir}/logstream/LogStream.cpp
        ${source_dir}/logstream/CErrorLog.cpp
        )
list(APPEND socket_source
        ${source_dir}/socket/Socket.h
        ${source_dir}/socket/Socket.cpp
        )
list(APPEND source
        ${filesystem_source}
        ${logstream_source}
        ${socket_source}
        )

add_executable(filesystem_test ${source} test/filesystem/main.cpp)
set_property(TARGET filesystem_test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${exe_output_dir})