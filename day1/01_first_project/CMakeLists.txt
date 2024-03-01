project(day1_01_first_project)

add_executable(day1_01_first_project
    main.cc
    MyWidget.cc
    MyPushButton.cc
)

target_link_libraries(day1_01_first_project
    ${QT_PREFIX}::Core
    ${QT_PREFIX}::Gui
    ${QT_PREFIX}::Widgets
)
