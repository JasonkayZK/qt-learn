//
// Created by jasonkay on 2024/3/3.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  //使用添加Qt资源 ": + 前缀名 + 文件名 "
  ui->actionNew->setIcon(QIcon(":/Image/Luffy.png"));
  ui->actionOpen->setIcon(QIcon(":/Image/LuffyQ.png"));
}

MainWindow::~MainWindow() {
  delete ui;
}
