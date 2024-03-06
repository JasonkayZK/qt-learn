//
// Created by jasonkay on 2024/3/6.
//

#ifndef QT_LEARN_DAY3_02_QTEVENT_WIDGET_H_
#define QT_LEARN_DAY3_02_QTEVENT_WIDGET_H_

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
 Q_OBJECT

 public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget() override;

  /// 重写定时器的事件
  void timerEvent(QTimerEvent *) override;

  int id1; /// 定时器1的唯一标示
  int id2; /// 定时器2的唯一标示

  /// 重写事件过滤器的事件
  bool eventFilter(QObject *, QEvent *) override;

 private:
  Ui::Widget *ui;
};

#endif //QT_LEARN_DAY3_02_QTEVENT_WIDGET_H_
