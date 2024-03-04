project(day2_06_tree_widget)

add_executable(day2_06_tree_widget
        main.cc
        widget.cpp
        widget.ui
)

target_link_libraries(day2_06_tree_widget
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
