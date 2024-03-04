project(day2_07_table_widget)

add_executable(day2_07_table_widget
        main.cc
        widget.cpp
        widget.ui
)

target_link_libraries(day2_07_table_widget
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
