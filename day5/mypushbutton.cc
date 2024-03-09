//
// Created by jasonkay on 2024/3/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyPushButton.h" resolved

#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation> // 动画
#include <utility>

MyPushButton::MyPushButton(const QString &normalImg, QString pressImg) {
  this->normalImgPath = normalImg;
  this->pressImgPath = std::move(pressImg);

  QPixmap pix;
  bool ret = pix.load(normalImg);
  if (!ret) {
    qDebug() << "图片加载失败";
    return;
  }

  /// 设置图片固定大小
  this->setFixedSize(pix.width(), pix.height());
  /// 设置不规则图片样式
  this->setStyleSheet("QPushButton{border:0px;}");
  /// 设置图标
  this->setIcon(pix);
  /// 设置图标大小
  this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyPushButton::zoom1() {
  /// 创建动态对象
  auto *animation = new QPropertyAnimation(this, "geometry");
  // 设置动画时间间隔
  animation->setDuration(200);
  // 起始位置
  animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
  // 结束位置
  animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
  // 设置弹跳曲线
  animation->setEasingCurve(QEasingCurve::OutBounce);
  // 执行动画
  animation->start();
}

void MyPushButton::zoom2() {
  /// 创建动态对象
  auto *animation = new QPropertyAnimation(this, "geometry");
  // 设置动画时间间隔
  animation->setDuration(200);
  // 起始位置
  animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
  // 结束位置
  animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
  // 设置弹跳曲线
  animation->setEasingCurve(QEasingCurve::OutBounce);
  // 执行动画
  animation->start();
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e) {
  /// 传入的按下图片不为空 说明需要有按下状态，切换图片
  if (this->pressImgPath != "") {
    QPixmap pix;
    bool ret = pix.load(this->pressImgPath);
    if (!ret) {
      qDebug() << "图片加载失败";
      return;
    }

    // 设置图片固定大小
    this->setFixedSize(pix.width(), pix.height());
    // 设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    // 设置图标
    this->setIcon(pix);
    // 设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
  }
  /// 让父类执行其他内容
  QPushButton::mouseReleaseEvent(e);
}

void MyPushButton::mousePressEvent(QMouseEvent *e) {
  /// 传入的按下图片不为空 说明需要有按下状态，切换成初始图片
  if (this->pressImgPath != "") {
    QPixmap pix;
    bool ret = pix.load(this->normalImgPath);
    if (!ret) {
      qDebug() << "图片加载失败";
      return;
    }

    // 设置图片固定大小
    this->setFixedSize(pix.width(), pix.height());
    // 设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    // 设置图标
    this->setIcon(pix);
    // 设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
  }

  /// 让父类执行其他内容
  QPushButton::mousePressEvent(e);
}
