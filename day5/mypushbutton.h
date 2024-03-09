//
// Created by jasonkay on 2024/3/9.
//

#ifndef QT_LEARN_DAY4_MYPUSHBUTTON_H_
#define QT_LEARN_DAY4_MYPUSHBUTTON_H_

#include <QPushButton>

class MyPushButton : public QPushButton {
 Q_OBJECT

 public:
  /// 构造函数 参数1  正常显示的图片路径   参数2 按下后显示的图片路径
  explicit MyPushButton(const QString &normalImg, QString pressImg = "");

  /// 弹跳特效
  void zoom1(); // 向下跳
  void zoom2(); // 向上跳

 signals:

 public slots:

 protected:
  /// 成员属性 保存用户传入的默认显示路径 以及按下后显示的图片路径
  // 正常显示的图片路径
  QString normalImgPath;
  // 按压时的图片路径
  QString pressImgPath;

  /// 重写按钮 按下 和 释放事件
  void mousePressEvent(QMouseEvent *e) override;

  void mouseReleaseEvent(QMouseEvent *e) override;
};

#endif //QT_LEARN_DAY4_MYPUSHBUTTON_H_
