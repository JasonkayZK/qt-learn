//
// Created by jasonkay on 2024/3/2.
//

#ifndef QT_LEARN_DAY1_02_SIGNAL_AND_SLOT_WIDGET_H_
#define QT_LEARN_DAY1_02_SIGNAL_AND_SLOT_WIDGET_H_

#include <QWidget>
#include "student.h"
#include "teacher.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
 Q_OBJECT

 public:
  explicit Widget(QWidget *parent = nullptr);

  ~Widget() override;

 private:
  Ui::Widget *ui;

  Teacher *t;
  Student *s;

  void classIsOver();
};

#endif //QT_LEARN_DAY1_02_SIGNAL_AND_SLOT_WIDGET_H_
