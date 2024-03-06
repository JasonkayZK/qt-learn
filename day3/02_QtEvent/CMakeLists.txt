project(day3_02_qt_event)

add_executable(day3_02_qt_event
        main.cc
        widget.cpp
        widget.ui
        my_label.cpp
        my_label.h
)

target_link_libraries(day3_02_qt_event
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
