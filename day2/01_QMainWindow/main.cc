#include <QApplication> /// 包含一个应用程序类的头文件
#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return QApplication::exec();
}
