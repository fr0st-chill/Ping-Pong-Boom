cmake_minimum_required(VERSION 3.31)
project(Pong LANGUAGES CXX VERSION 1.0.0)

set(SOFTWARE_OUTPUT "Pong_${CMAKE_PROJECT_VERSION}.exe")

set(SOURCES
  main.cpp
)

set(CMAKE_BUILD_TYPE "$ENV{CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
add_executable(${SOFTWARE_OUTPUT} ${SOURCES})

# TODO: Check if this helps compile time
# TODO: Add a require for the SDL 2 library
# TODO: Add library exception catching
target_link_libraries(${SOFTWARE_OUTPUT} PRIVATE SDL2)


