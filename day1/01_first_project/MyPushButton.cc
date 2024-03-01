//
// Created by jasonkay on 2024/3/1.
//

#include <QDebug>
#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent) {
  qDebug() << "我的按钮类构造调用";
}

MyPushButton::~MyPushButton() {
  qDebug() << "我的按钮类析构";
}
