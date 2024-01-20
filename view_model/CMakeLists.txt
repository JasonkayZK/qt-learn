cmake_minimum_required(VERSION 3.22)
project(view_model)

if (MACOS)
  qt_wrap_ui(UI_HEADERS main_game_window.ui)
elseif (WINDOWS)
  qt5_wrap_ui(UI_HEADERS main_game_window.ui)
endif ()
