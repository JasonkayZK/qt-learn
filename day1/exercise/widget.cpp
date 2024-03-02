//
// Created by jasonkay on 2024/3/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Widget.h" resolved

#include <QPushButton>
#include <QDebug>
#include "widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  // 创建一个Button
  this->toggleButton = new QPushButton("打开", this);
  this->toggleButton->move(150, 150);

  this->newWindow = nullptr;

  // 第三个参数是 this（接受者是本身），可以省略！
  connect(this->toggleButton, &QPushButton::clicked, this, &Widget::toggleNewWindow);
}

Widget::~Widget() {
  delete ui;
}

void Widget::toggleNewWindow() {
  this->toggleStatus();
  // 打开新窗口
  if (this->opened) {
    newWindow = new QWidget(); // 创建新窗口
    newWindow->setGeometry(100, 100, 200, 200); // 设置新窗口位置和大小
    newWindow->show(); // 显示新窗口
    qDebug() << "创建窗口成功！";
    this->toggleButton->setText("关闭"); // 修改按钮文本
  } else {
    if (newWindow) {
      delete newWindow; // 关闭新窗口
      newWindow = nullptr; // 重置新窗口对象为空指针
      qDebug() << "关闭窗口成功！";
    }
    this->toggleButton->setText("打开");
  }
}
