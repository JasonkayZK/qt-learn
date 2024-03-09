//
// Created by jasonkay on 2024/3/9.
//

#ifndef QT_LEARN_DAY4_PLAY_SCENE_H_
#define QT_LEARN_DAY4_PLAY_SCENE_H_

#include <QMainWindow>
#include "my_coin.h"

class PlayScene : public QMainWindow {
 Q_OBJECT
 public:
  explicit PlayScene(int levelNum);

  /// 内部成员属性 记录所选的关卡
  int levelIndex;

  bool isWin;

  /// 重写paintEvent事件
  void paintEvent(QPaintEvent *) override;

  int gameArray[4][4]{};

  MyCoin *coinBtn[4][4]{};

 signals:
  /// 用于返回 选择关卡场景 的信号函数
  void chooseSceneBack();
 public slots:
};

#endif //QT_LEARN_DAY4_PLAY_SCENE_H_
