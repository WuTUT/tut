cmake_minimum_required(VERSION 3.16)
project(TUT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
# add fmt.cmake in cmake
include(fmt)



add_executable(TUT main.cpp include/tut/log.cpp include/tut/log.h include/tut/singleton.h include/tut/sink.cpp include/tut/sink.h include/tut/log_common.cpp include/tut/log_common.h include/tut/log_formatter.cpp include/tut/log_formatter.h include/tut/log_msg.cpp include/tut/log_msg.h include/tut/util.cpp include/tut/util.h)
target_link_libraries(TUT PRIVATE fmt::fmt)
target_include_directories(TUT PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(TUT PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ext/fmt/include)