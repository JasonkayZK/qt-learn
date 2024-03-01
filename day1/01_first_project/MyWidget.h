//
// Created by jasonkay on 2024/3/1.
//

#ifndef QT_LEARN_DAY1_01_FIRST_PROJECT_MYWIDGET_H_
#define QT_LEARN_DAY1_01_FIRST_PROJECT_MYWIDGET_H_

#include <QWidget> /// 包含头文件 QWidget 窗口类

class MyWidget : public QWidget {
 Q_OBJECT /// Q_OBJECT宏，允许类中使用信号和槽的机制

 public:
  explicit MyWidget(QWidget *parent = nullptr); /// 构造函数
  ~MyWidget() override; /// 析构函数
};

#endif //QT_LEARN_DAY1_01_FIRST_PROJECT_MYWIDGET_H_
