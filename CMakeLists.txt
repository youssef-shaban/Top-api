cmake_minimum_required(VERSION 3.20)
project(TopAPI)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

add_executable(TopAPI ${SOURCE_FILES})

include_directories(API_lib)
add_subdirectory(API_lib)

target_link_libraries(TopAPI API_lib)
add_subdirectory(Catch_tests)
