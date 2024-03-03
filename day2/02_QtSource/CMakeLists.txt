project(day2_02_qt_source)

add_executable(day2_02_qt_source
        main.cc
        res.qrc
        main_window.cpp
        main_window.ui
)

target_link_libraries(day2_02_qt_source
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
