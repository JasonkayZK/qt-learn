//
// Created by jasonkay on 2024/3/6.
//

#ifndef QT_LEARN_DAY4_MAINSCENE_H_
#define QT_LEARN_DAY4_MAINSCENE_H_

#include <QMainWindow>
#include "chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow {
 Q_OBJECT

 public:
  explicit MainScene(QWidget *parent = nullptr);
  ~MainScene() override;

 protected:
  /// 重新paintEvent事件 画背景图
  void paintEvent(QPaintEvent *event) override;

  ChooseLevelScene *chooseScene = nullptr;

 private:
  Ui::MainScene *ui;
};

#endif //QT_LEARN_DAY4_MAINSCENE_H_
