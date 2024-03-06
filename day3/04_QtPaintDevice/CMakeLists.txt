project(day3_04_qt_paint_device)

add_executable(day3_04_qt_paint_device
        main.cc
        res.qrc
        widget.cpp
        widget.ui
)

target_link_libraries(day3_04_qt_paint_device
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
