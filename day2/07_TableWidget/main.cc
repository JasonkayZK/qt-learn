//
// Created by jasonkay on 2024/3/3.
//

#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Widget w;
  w.show();

  return QApplication::exec();
}
