project(day2_01_q_main_window)

add_executable(day2_01_q_main_window
        main.cc
        main_window.cpp
)

target_link_libraries(day2_01_q_main_window
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
