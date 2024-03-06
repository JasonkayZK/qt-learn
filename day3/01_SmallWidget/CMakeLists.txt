project(day3_01_small_widget)

add_executable(day3_01_small_widget
        main.cc
        widget.cpp
        widget.ui
        smallwidget.cpp
        smallwidget.ui
)

target_link_libraries(day3_01_small_widget
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
