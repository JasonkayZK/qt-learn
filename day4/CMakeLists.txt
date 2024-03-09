# Day-4
project(day4)

add_executable(FlipCoin_day4
        main.cc
        mainscene.cc
        mainscene.ui
        res.qrc
        mypushbutton.cc
        chooselevelscene.cc
        play_scene.cc
        config.cc
)

target_link_libraries(FlipCoin_day4
        ${QT_PREFIX}::Core
        ${QT_PREFIX}::Gui
        ${QT_PREFIX}::Widgets
)
