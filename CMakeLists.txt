cmake_minimum_required(VERSION 3.22)
project(mine-sweeper)

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

add_executable(main main.cc
        model/consts.h model/game_model.cc model/game_model.h model/mine_block.h
        view_model/main_game_window.cc view_model/main_game_window.h view_model/main_game_window.ui)

target_link_libraries(main
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

add_subdirectory(${PROJECT_SOURCE_DIR}/model)
add_subdirectory(${PROJECT_SOURCE_DIR}/view_model)
