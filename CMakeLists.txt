cmake_minimum_required(VERSION 3.16.3)
project(digital-go-board)

set(CMAKE_CXX_STANDARD 17)

add_library(bcm2835 STATIC IMPORTED)
set_property(TARGET bcm2835 PROPERTY
        IMPORTED_LOCATION "/usr/local/lib/libbcm2835.a")

add_library(EPD_IT8951 STATIC libs/IT8951/e-Paper/EPD_IT8951.c)
add_library(GUIPaint STATIC libs/IT8951/GUI/GUI_Paint.c)
add_library(DEV_Config STATIC libs/IT8951/Config/DEV_Config.c)
target_link_libraries(DEV_Config PRIVATE bcm2835)

add_library(BCM2835Connection STATIC Renderer/EPaper/BCM2835Connection.cpp)
target_link_libraries(BCM2835Connection PRIVATE DEV_Config)

add_library(Renderer STATIC Renderer/Renderer.cpp)
add_library(TerminalRenderer STATIC Renderer/TerminalRenderer.cpp)
add_library(EPaperRenderer STATIC Renderer/EPaperRenderer.cpp)
target_link_libraries(EPaperRenderer PRIVATE BCM2835Connection EPD_IT8951 GUIPaint)

add_library(Coordinate STATIC Coordinate.cpp)
add_library(Goban STATIC Goban.cpp)
add_library(InputDevice STATIC InputDevice.cpp)

add_executable(digital-go-board main.cpp)
target_link_libraries(digital-go-board Renderer EPaperRenderer TerminalRenderer Coordinate Goban InputDevice)