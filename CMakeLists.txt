cmake_minimum_required(VERSION 3.20)
project(Game_Life)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Game_Life main.cpp)

target_link_libraries(Game_Life sfml-graphics sfml-audio)