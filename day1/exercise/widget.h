//
// Created by jasonkay on 2024/3/2.
//

#ifndef QT_LEARN_DAY1_EXERCISE_WIDGET_H_
#define QT_LEARN_DAY1_EXERCISE_WIDGET_H_

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
 Q_OBJECT

 public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget() override;

 private slots:
  void toggleNewWindow();

 private:
  Ui::Widget *ui;

  QPushButton *toggleButton; // 按钮
  QWidget  *newWindow; // 新窗口

  bool opened = false;

  void toggleStatus() {
    this->opened = !this->opened;
  }

};

#endif //QT_LEARN_DAY1_EXERCISE_WIDGET_H_
