//
// Created by jasonkay on 2024/3/6.
//

#ifndef QT_LEARN_DAY3_01_SMALLWIDGET_SMALLWIDGET_H_
#define QT_LEARN_DAY3_01_SMALLWIDGET_SMALLWIDGET_H_

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SmallWidget; }
QT_END_NAMESPACE

class SmallWidget : public QWidget {
 Q_OBJECT

 public:
  explicit SmallWidget(QWidget *parent = nullptr);
  ~SmallWidget() override;

  //设置数字
  void setNum(int num);

  //获取数字
  int getNum();

 private:
  Ui::SmallWidget *ui;
};

#endif //QT_LEARN_DAY3_01_SMALLWIDGET_SMALLWIDGET_H_
