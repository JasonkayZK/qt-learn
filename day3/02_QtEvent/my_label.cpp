//
// Created by jasonkay on 2024/3/6.
//

#include "my_label.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent) {
  /// 设置鼠标追踪状态
  setMouseTracking(true);
}

/// 鼠标进入事件
void MyLabel::enterEvent(QEvent *event) {
//   qDebug() << "鼠标进入了";
}

/// 鼠标离开事件
void MyLabel::leaveEvent(QEvent *) {
  // qDebug() << "鼠标离开了";
}

/// 鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev) {

  /// 当鼠标左键按下  提示信息
//    if( ev->button() ==  Qt::LeftButton)
//    {
  QString str =
      QString("鼠标按下了 x = %1   y = %2  globalX = %3 globalY = %4 ").arg(ev->pos().x()).arg(ev->pos().y()).arg(ev->globalPosition().x()).arg(
          ev->globalPosition().y());
  qDebug() << str;
//    }
}

//鼠标释放
void MyLabel::mouseReleaseEvent(QMouseEvent *ev) {

//    if( ev->button() ==  Qt::LeftButton)
//    {
  QString str =
      QString("鼠标释放了 x = %1   y = %2  globalX = %3 globalY = %4 ").arg(ev->pos().x()).arg(ev->pos().y()).arg(ev->globalPosition().x()).arg(
          ev->globalPosition().y());

  qDebug() << str;
//    }

}

//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
  if (ev->buttons() & Qt::LeftButton) {
    QString str =
        QString("鼠标移动了 x = %1   y = %2  globalX = %3 globalY = %4 ").arg(ev->pos().x()).arg(ev->pos().y()).arg(ev->globalPosition().x()).arg(
            ev->globalPosition().y());

    qDebug() << str;
  }
}

bool MyLabel::event(QEvent *e) {
  //如果是鼠标按下 ，在event事件分发中做拦截操作
  if (e->type() == QEvent::MouseButtonPress) {
    auto *ev = dynamic_cast<QMouseEvent *>(e);
    QString str =
        QString("Event函数中：：鼠标按下了 x = %1   y = %2  globalX = %3 globalY = %4 ").arg(ev->pos().x()).arg(ev->pos().y()).arg(
            ev->globalPosition().x()).arg(
            ev->globalPosition().y());
    qDebug() << str;

    return true; //true代表用户自己处理这个事件，不向下分发
  }


  //其他事件 交给父类处理  默认处理
  return QLabel::event(e);
}
