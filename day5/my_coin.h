#ifndef QT_LEARN_DAY5_MY_COIN_H_
#define QT_LEARN_DAY5_MY_COIN_H_

#include <QTimer>
#include <QPushButton>

/// 金币类，用于显示关卡的金币
class MyCoin : public QPushButton {
 Q_OBJECT

 public:
  explicit MyCoin(const QString& btnImg);

  int posX; // x坐标
  int posY; // y坐标
  bool flag; // 正反标志
  bool isAnimation = false;

  int min = 1; // 图片为金币
  int max = 8; // 图片为银币

  bool notPress = false; // false = 能按，true = 不能按

  void changeFlag(int ms); // 改变标志

  QTimer *timer1; // 正面 -> 反面
  QTimer *timer2; // 反面 -> 正面

  void mousePressEvent(QMouseEvent *e) override;

 signals:

 public slots:

};

#endif //QT_LEARN_DAY5_MY_COIN_H_
