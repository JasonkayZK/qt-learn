//
// Created by jasonkay on 2024/3/9.
//

#ifndef QT_LEARN_DAY4_PLAY_SCENE_H_
#define QT_LEARN_DAY4_PLAY_SCENE_H_

#include <QMainWindow>

class PlayScene : public QMainWindow {
 Q_OBJECT
 public:
  //explicit PlayScene(QWidget *parent = 0);

  explicit PlayScene(int levelNum);

  /// 内部成员属性 记录所选的关卡
  int levelIndex;

  /// 重写paintEvent事件
  void paintEvent(QPaintEvent *) override;

 signals:
  void chooseSceneBack();
 public slots:
};

#endif //QT_LEARN_DAY4_PLAY_SCENE_H_
