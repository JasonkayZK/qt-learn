//
// Created by jasonkay on 2024/3/6.
//
#include <QApplication>
#include "mainscene.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainScene w;
  w.show();

  return QApplication::exec();
}
