cmake_minimum_required(VERSION 3.5)

project(hello C CXX)
set(source_dir ${PROJECT_SOURCE_DIR}/src)
set(include_dir ${source_dir}/include)
set(exe_output_dir ${PROJECT_BINARY_DIR}/bin)
set(lib_output_dir ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_CXX_FLAGS "-std=c++11 -Werror -Wall -O0")

include_directories(${include_dir})

add_executable(hello ${source_dir}/main.cc ${source_dir}/Socket.cc)