project(day2_04_layout)

add_executable(day2_04_layout
        main.cc
        main_window.cc
        main_window.ui
)

target_link_libraries(day2_04_layout
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
