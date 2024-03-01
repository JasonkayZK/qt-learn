# Day-0 hello-world
project(day0)

add_executable(day0 main.cc)
target_link_libraries(day0
    ${QT_PREFIX}::Core
    ${QT_PREFIX}::Gui
    ${QT_PREFIX}::Widgets
)
