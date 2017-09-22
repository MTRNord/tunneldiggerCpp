cmake_minimum_required(VERSION 3.7)
project(tunneldigger_broker)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp hooks.cpp hooks.h broker.cpp broker.h)
add_executable(tunneldigger_broker ${SOURCE_FILES})

install (TARGETS tunneldigger_broker
        RUNTIME DESTINATION bin)
