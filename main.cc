#include "view_model/main_game_window.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainGameWindow w;
    w.show();
    return QApplication::exec();
}
