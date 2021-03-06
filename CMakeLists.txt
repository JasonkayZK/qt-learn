cmake_minimum_required(VERSION 3.22)
project(qt_learn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# os check
if (CMAKE_HOST_WIN32)
    message("WinOS Config")
    set(WINDOWS 1)
    set(QT_PREFIX Qt5)
elseif (CMAKE_HOST_APPLE)
    message("MacOS Config")
    set(MACOS 1)
    set(QT_PREFIX Qt)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()

if (MACOS)
    set(CMAKE_PREFIX_PATH "/opt/homebrew/lib")
    find_package(Qt6 COMPONENTS
            Core
            Gui
            Widgets
            REQUIRED)
elseif (WINDOWS)
    set(CMAKE_PREFIX_PATH "E:/qt/qt-5.14.2/5.14.2/msvc2017_64")
    find_package(Qt5 COMPONENTS
            Core
            Gui
            Widgets
            REQUIRED)
endif ()

add_executable(main main.cc)
target_link_libraries(main
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
        )
