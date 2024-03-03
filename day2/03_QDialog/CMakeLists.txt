project(day2_03_q_dialog)

add_executable(day2_03_q_dialog
        main.cc
        main_window.cc
        main_window.ui
)

target_link_libraries(day2_03_q_dialog
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
