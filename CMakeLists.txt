cmake_minimum_required(VERSION 3.0)

project(ants VERSION 1.0.0.1)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif(UNIX)

if("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
    add_definitions(-D_DEBUG)
endif("${CMAKE_BUILD_TYPE}" MATCHES "Debug")

OPTION(ANT_TEST "ANT Test" OFF)
if(ANT_TEST)
    add_definitions(-D_ANT_TEST)
endif(ANT_TEST)

MESSAGE("=== PROJECT_VERSION:              ${PROJECT_VERSION}")
MESSAGE("=== CMAKE_CXX_COMPILER_VERSION:   ${CMAKE_CXX_COMPILER_VERSION}")
MESSAGE("=== CMAKE_SOURCE_DIR:             ${CMAKE_SOURCE_DIR}")
MESSAGE("=== CMAKE_CXX_FLAGS:              ${CMAKE_CXX_FLAGS}")
MESSAGE("=== Build type:                   ${CMAKE_BUILD_TYPE}")
MESSAGE("=== ANT Test:                     ${ANT_TEST}")

include_directories("${CMAKE_SOURCE_DIR}/src")

add_subdirectory("${CMAKE_SOURCE_DIR}/src")
