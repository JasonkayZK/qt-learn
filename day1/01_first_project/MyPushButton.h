//
// Created by jasonkay on 2024/3/1.
//

#ifndef QT_LEARN_DAY1_01_FIRST_PROJECT_MYPUSHBUTTON_H_
#define QT_LEARN_DAY1_01_FIRST_PROJECT_MYPUSHBUTTON_H_

#include <QPushButton>

class MyPushButton : public QPushButton {
 Q_OBJECT

 public:
  explicit MyPushButton(QWidget *parent = nullptr);

  ~MyPushButton() override;

 signals:

 public slots:

};

#endif //QT_LEARN_DAY1_01_FIRST_PROJECT_MYPUSHBUTTON_H_
