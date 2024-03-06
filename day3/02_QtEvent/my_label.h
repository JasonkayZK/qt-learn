//
// Created by jasonkay on 2024/3/6.
//

#ifndef QT_LEARN_DAY3_02_QTEVENT_MY_LABEL_H_
#define QT_LEARN_DAY3_02_QTEVENT_MY_LABEL_H_

#include <QLabel>

class MyLabel : public QLabel {
 Q_OBJECT

 public:
  explicit MyLabel(QWidget *parent = nullptr);

  /// 鼠标进入事件
  void enterEvent(QEvent *event);

  /// 鼠标离开事件
  void leaveEvent(QEvent *) override;

  /// 鼠标按下
  void mousePressEvent(QMouseEvent *ev) override;

  /// 鼠标释放
  void mouseReleaseEvent(QMouseEvent *ev) override;

  /// 鼠标移动
  void mouseMoveEvent(QMouseEvent *ev) override;

  /// 通过event事件分发器 拦截 鼠标按下事件
  bool event(QEvent *e) override;

 signals:

 public slots:
};

#endif //QT_LEARN_DAY3_02_QTEVENT_MY_LABEL_H_
