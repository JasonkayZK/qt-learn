//
// Created by jasonkay on 2024/3/9.
//

#ifndef QT_LEARN_DAY4_CHOOSELEVELSCENE_H_
#define QT_LEARN_DAY4_CHOOSELEVELSCENE_H_

#include <QMainWindow>
#include "play_scene.h"

/// 选择关卡类
class ChooseLevelScene : public QMainWindow {
 Q_OBJECT

 public:
  explicit ChooseLevelScene(QWidget *parent = nullptr);

 protected:
  ///重写绘图事件
  void paintEvent(QPaintEvent *event) override;

  /// 游戏场景对象指针
  PlayScene *play = nullptr;

 private:

 signals:
  /// 写一个自定义信号，告诉主场景  点击了返回
  void chooseSceneBack();

 public slots:

};

#endif //QT_LEARN_DAY4_CHOOSELEVELSCENE_H_
