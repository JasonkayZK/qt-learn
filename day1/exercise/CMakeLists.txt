project(day1_exercise)

add_executable(day1_exercise
        main.cc
        widget.cpp
        widget.ui
)

target_link_libraries(day1_exercise
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
