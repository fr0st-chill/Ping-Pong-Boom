cmake_minimum_required(VERSION 3.31)
project(Pong LANGUAGES CXX VERSION 1.0.0)

set(SOFTWARE_OUTPUT "Pong_${CMAKE_PROJECT_VERSION}.exe")

set(SOURCES
  main.cpp
)

add_executable(${SOFTWARE_OUTPUT} ${SOURCES})

target_link_libraries(${SOFTWARE_OUTPUT} PRIVATE SDL2)


