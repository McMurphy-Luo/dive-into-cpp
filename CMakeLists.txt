cmake_minimum_required(VERSION 3.5)
project(rookie C CXX)
set(CMAKE_CXX_STANDARD 11)
set(source_dir ${PROJECT_SOURCE_DIR}/src)
set(exe_output_dir ${PROJECT_BINARY_DIR}/bin)
set(lib_output_dir ${PROJECT_BINARY_DIR}/lib)
find_package(Boost REQUIRED)
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Weffc++ -g")
include_directories(${source_dir})
include_directories(${BOOST_INCLUDE_DIRS})

list(APPEND filesystem_source
        ${source_dir}/filesystem/directory.h
        ${source_dir}/filesystem/directory.cpp
        ${source_dir}/filesystem/file.h
        ${source_dir}/filesystem/file.cpp
        )

list(APPEND multiplexing_source
        ${source_dir}/multiplexing/poll.h
        ${souree_dir}/multiplexing/poll.cpp)

list(APPEND logstream_source
        ${source_dir}/logstream/log_stream.h
        ${source_dir}/logstream/cerr_log.h
        ${source_dir}/logstream/log_stream.cpp
        ${source_dir}/logstream/cerr_log.cpp
        )

list(APPEND socket_source
        ${source_dir}/socket/socket.h
        ${source_dir}/socket/socket.cpp
        ${source_dir}/socket/fd_set.h
        ${source_dir}/socket/fd_set.cpp
        )

list(APPEND miscellaneous_source
        ${source_dir}/miscellaneous/cpu_time.h
        ${source_dir}/miscellaneous/cpu_time.cpp
        ${source_dir}/miscellaneous/process_limits.cpp
        ${source_dir}/miscellaneous/process_limits.h
        ${source_dir}/miscellaneous/sigset.h
        ${source_dir}/miscellaneous/sigset.cpp
        )

list(APPEND source
        ${filesystem_source}
        ${logstream_source}
        ${socket_source}
        ${miscellaneous_source}
        )

message(STATUS ${BUILD_SHARED_LIBS})
add_library(rookie STATIC ${source})
add_executable(filesystem_test test/filesystem/main.cpp)
target_link_libraries(filesystem_test rookie)
add_executable(process_limits_test test/miscellaneous/process_limits.cpp)
target_link_libraries(process_limits_test rookie)
add_executable(cpu_time_test test/miscellaneous/cpu_time.cpp)
target_link_libraries(cpu_time_test rookie)
add_executable(socket_server_test test/socket/server.cpp)
target_link_libraries(socket_server_test rookie)
add_executable(socket_client_test test/socket/client.cpp)
target_link_libraries(socket_client_test rookie)

set_property(TARGET rookie PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${lib_output_dir})
set_property(TARGET filesystem_test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${exe_output_dir})
set_property(TARGET cpu_time_test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${exe_output_dir})
set_property(TARGET process_limits_test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${exe_output_dir})
set_property(TARGET socket_server_test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${exe_output_dir})
set_property(TARGET socket_client_test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${exe_output_dir})