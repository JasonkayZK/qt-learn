//
// Created by jasonkay on 2024/3/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SmallWidget.h" resolved

#include "smallwidget.h"
#include "ui_SmallWidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::SmallWidget) {
  ui->setupUi(this);

  /// QSpinBox移动 QSlider跟着移动

  void (QSpinBox::* spSignal )(int) = &QSpinBox::valueChanged;
  connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);

  /// QSlider滑动  QSpinBox数字跟着改变
  connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

SmallWidget::~SmallWidget() {
  delete ui;
}

void SmallWidget::setNum(int num) {
  ui->spinBox->setValue(num);
}

int SmallWidget::getNum() {
  return ui->spinBox->value();
}
