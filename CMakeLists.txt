cmake_minimum_required(VERSION 3.15)
project(Course_Project)

set(CMAKE_CXX_STANDARD 14)

#FIND_PACKAGE(Boost 1.66 REQUIRED date_time program_options thread filesystem system unit_test_framework)
#IF(${Boost_FOUND})
#    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
#ENDIF()

add_executable(Course_Project main.cpp)
include_directories(OrderBook)
include_directories(APP)
add_subdirectory(OrderBook)
add_subdirectory(APP)
add_subdirectory(MyTest)

target_link_libraries(Course_Project OrderBook APP)