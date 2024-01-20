//
// Created by Jasonkay on 2022/5/15.
//

#ifndef MINE_SWEEPER_MAIN_GAME_WINDOW_H
#define MINE_SWEEPER_MAIN_GAME_WINDOW_H

#include "../model/game_model.h"

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainGameWindow; }
QT_END_NAMESPACE

class GameModel; // 前置声明游戏模型类

class MainGameWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit MainGameWindow(QWidget *parent = nullptr);

  ~MainGameWindow() override;

 protected:
  void paintEvent(QPaintEvent *event) override;       // 界面重绘
  void mousePressEvent(QMouseEvent *event) override;  // 鼠标控制
 private:
  Ui::MainGameWindow *ui;

  GameModel *game; // 游戏
  QTimer *timer;     // 计时器
  QLabel *timeLabel; // 计时数字

  void handleGameState(GameModel *game_model); // 处理游戏状态
 private slots:

  void onStartGameClicked();    // 开始游戏
  void onLevelChooseClicked();  // 选择游戏难度
  static void onQuitClicked();         // 退出游戏
  void updateTimer();           // 计时
};

#endif //MINE_SWEEPER_MAIN_GAME_WINDOW_H
