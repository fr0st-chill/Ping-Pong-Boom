cmake_minimum_required(VERSION 3.31)
project(Pong LANGUAGES CXX VERSION 1.0.0)

set(SOFTWARE_OUTPUT "Pong_${CMAKE_PROJECT_VERSION}.exe")

set(SOURCES
  main.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(Pong ${SDL2_INCLUDE_DIRS})
add_executable(${SOFTWARE_OUTPUT} ${SOURCES})

target_link_libraries(${SOFTWARE_OUTPUT} PRIVATE ${SDL2_LIBRARIES} ${SDL_TTF_LIBRARIES})
