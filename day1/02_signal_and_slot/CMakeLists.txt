project(day1_02_signal_and_slot)

add_executable(day1_02_signal_and_slot
    main.cc
    widget.cc
    widget.ui
    teacher.cc
    student.cc
)

target_link_libraries(day1_02_signal_and_slot
    ${QT_PREFIX}::Core
    ${QT_PREFIX}::Gui
    ${QT_PREFIX}::Widgets
)
