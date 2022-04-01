project(APP)

add_definitions(-std=gnu++11)

set(HEADER_FILES AppBase.h DataReader.h TradingStrategy.h OrderManager.h MarketSimulator.h)
set(SOURCE_FILES TradingStrategy.cpp OrderManager.cpp)

add_library(APP STATIC  ${SOURCE_FILES} ${HEADER_FILE})