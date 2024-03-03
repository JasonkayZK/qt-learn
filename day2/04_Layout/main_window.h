//
// Created by jasonkay on 2024/3/3.
//

#ifndef QT_LEARN_DAY2_02_QTSOURCE_MAIN_WINDOW_H_
#define QT_LEARN_DAY2_02_QTSOURCE_MAIN_WINDOW_H_

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

 private:
  Ui::MainWindow *ui;
};

#endif //QT_LEARN_DAY2_02_QTSOURCE_MAIN_WINDOW_H_
