project(day3_05_qt_file)

add_executable(day3_05_qt_file
        main.cc
        widget.cpp
        widget.ui
)

target_link_libraries(day3_05_qt_file
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
