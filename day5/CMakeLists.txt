# Day-5
project(day5)

add_executable(FlipCoin
        main.cc
        mainscene.cc
        mainscene.ui
        res.qrc
        mypushbutton.cc
        chooselevelscene.cc
        play_scene.cc
        config.cc
)

target_link_libraries(FlipCoin
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
