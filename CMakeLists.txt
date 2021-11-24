cmake_minimum_required(VERSION 3.20)
project(stl)

set(CMAKE_CXX_STANDARD 11)
include_directories(test/lib lib/def lib/except lib)

find_package(GTEST REQUIRED)
add_executable(stl main.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})

