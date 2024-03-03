project(day2_code)

add_executable(day2_01_q_main_window
        main.cc
        main_window.cpp
        main_window.h
        main_window.ui
)

target_link_libraries(day2_01_q_main_window
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
