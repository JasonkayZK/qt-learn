//
// Created by jasonkay on 2024/3/2.
//

#ifndef QT_LEARN_DAY2_01_QMAINWINDOW_MAIN_WINDOW_H_
#define QT_LEARN_DAY2_01_QMAINWINDOW_MAIN_WINDOW_H_

#include <QMainWindow>

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

 private:
};

#endif //QT_LEARN_DAY2_01_QMAINWINDOW_MAIN_WINDOW_H_
