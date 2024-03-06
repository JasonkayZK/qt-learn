project(day3_03_qt_painter)

add_executable(day3_03_qt_painter
        main.cc
        res.qrc
        widget.cpp
        widget.ui
)

target_link_libraries(day3_03_qt_painter
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
