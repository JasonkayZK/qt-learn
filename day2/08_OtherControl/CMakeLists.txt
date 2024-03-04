project(day2_08_other_control)

add_executable(day2_08_other_control
        main.cc
        res.qrc
        widget.cpp
        widget.ui
)

target_link_libraries(day2_08_other_control
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
