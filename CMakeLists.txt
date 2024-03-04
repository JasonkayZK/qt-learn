cmake_minimum_required(VERSION 3.22)
project(qt_learn)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_PREFIX Qt6)

# os check
if (CMAKE_HOST_WIN32)
    message("WinOS Config")
    set(WINDOWS 1)
    set(QT_CMAKE_PREFIX_PATH "E:/qt/qt-6.6.1/6.6.1/msvc2019_64")
elseif (CMAKE_HOST_APPLE)
    message("MacOS Config")
    set(MACOS 1)
    set(QT_CMAKE_PREFIX_PATH "/Users/zk/Qt/6.6.1/macos/lib/cmake")
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()

set(CMAKE_PREFIX_PATH ${QT_CMAKE_PREFIX_PATH})
find_package(${QT_PREFIX} COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_subdirectory(day0)
add_subdirectory(day1)
add_subdirectory(day2)
add_subdirectory(day3)
