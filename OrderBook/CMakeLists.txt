project(OrderBook)

add_definitions(-std=gnu++11)

FIND_PACKAGE(Boost 1.66 REQUIRED program_options)
IF(${Boost_FOUND})
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

set(MY_HEADER_FILES Order.h OrderBook.h BookUpdate.h)
set(MY_SOURCE_FILES Order.cpp BookUpdate.cpp)

add_library(OrderBook STATIC ${MY_SOURCE_FILES} ${MY_HEADER_FILE})
target_link_libraries(OrderBook ${Boost_LIBRARIES})