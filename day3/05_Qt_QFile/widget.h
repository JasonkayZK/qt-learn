//
// Created by jasonkay on 2024/3/6.
//

#ifndef QT_LEARN_DAY3_05_QT_QFILE_WIDGET_H_
#define QT_LEARN_DAY3_05_QT_QFILE_WIDGET_H_

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
 Q_OBJECT

 public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget() override;

 private:
  Ui::Widget *ui;
};

#endif //QT_LEARN_DAY3_05_QT_QFILE_WIDGET_H_
