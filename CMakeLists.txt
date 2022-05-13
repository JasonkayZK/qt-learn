cmake_minimum_required(VERSION 3.22)
project(qt_learn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/lib")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(main main.cc)
target_link_libraries(main
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
