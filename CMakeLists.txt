cmake_minimum_required(VERSION 3.0)

project(boiler_tests)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_subdirectory(../boiler/ libboiler)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Make test executable
set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests boiler Catch)
