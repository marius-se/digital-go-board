cmake_minimum_required(VERSION 3.17)
project(digital_go_board)

set(CMAKE_CXX_STANDARD 17)

add_executable(digital_go_board main.cpp InputDevice.cpp InputDevice.h Renderer/Renderer.cpp Coordinate.cpp Goban.cpp #[[Renderer/EPaperRenderer.cpp]] Renderer/TerminalRenderer.cpp)
