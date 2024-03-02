//
// Created by jasonkay on 2024/3/2.
//

#ifndef QT_LEARN_DAY1_02_SIGNAL_AND_SLOT_TEACHER_H_
#define QT_LEARN_DAY1_02_SIGNAL_AND_SLOT_TEACHER_H_

#include <QObject>

class Teacher : public QObject {
 Q_OBJECT

 public:
  explicit Teacher(QObject *parent = nullptr);

 signals:
  //自定义信号  写到signals下
  //返回值是void ，只需要声明，不需要实现
  //可以有参数，可以重载
  void hungry();

  void hungry(QString foodName);

 public slots:

 private:
};

#endif //QT_LEARN_DAY1_02_SIGNAL_AND_SLOT_TEACHER_H_
