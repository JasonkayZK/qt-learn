//
// Created by jasonkay on 2024/3/3.
//

#include <QApplication>
#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return QApplication::exec();
}
