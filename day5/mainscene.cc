//
// Created by jasonkay on 2024/3/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainScene.h" resolved

#include "mainscene.h"
#include "ui_MainScene.h"
#include "config.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSoundEffect>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainScene) {
  ui->setupUi(this);

  /// 配置主场景
  // 设置固定大小
  setFixedSize(MAIN_WIDTH, MAIN_HEIGHT);
  // 设置图标
  setWindowIcon(QIcon(":/res/Coin0001.png"));
  // 设置标题
  setWindowTitle("翻金币主场景");

  /// 退出按钮实现
  connect(ui->actionQuit, &QAction::triggered, [=]() {
    this->close();
  });

  /// 设置背景音乐
  auto *gameSound = new QSoundEffect(this);
  gameSound->setSource(QUrl::fromLocalFile(":/res/myDouDZ.wav"));
  gameSound->play();
  /// 开始按钮音效
  auto *startSound = new QSoundEffect(this);
  startSound->setSource(QUrl::fromLocalFile(":/res/ConFlipSound.wav"));

  /// 开始按钮
  auto *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
  startBtn->setParent(this);
  startBtn->move(int(this->width() * 0.5 - startBtn->width() * 0.5), int(this->height() * 0.7));

  connect(startBtn, &MyPushButton::clicked, [=]() {
    qDebug() << "点击了开始按钮";
    startSound->play();

    // 做弹起特效
    startBtn->zoom1();
    startBtn->zoom2();

    // 延时进入到选择关卡场景中
    QTimer::singleShot(500, this, [=]() {
      // 设置窗口固定
      chooseScene->setGeometry(this->geometry());
      // 自身隐藏
      this->hide();
      // 显示选择关卡场景
      chooseScene->show();
    });
  });

  /// 实例化选择关卡场景
  chooseScene = new ChooseLevelScene;

  /// 监听选择关卡的返回按钮的信号
  connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=]() {
    // 设置固定窗口
    this->setGeometry(chooseScene->geometry());
    chooseScene->hide(); // 将选择关卡场景 隐藏掉
    this->show(); // 重新显示主场景
  });
}

void MainScene::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QPixmap pix;
  pix.load(":/res/PlayLevelSceneBg.png");
  painter.drawPixmap(0, 0, this->width(), this->height(), pix);

  /// 画背景上图标
  pix.load(":/res/Title.png");
  pix = pix.scaled(int(pix.width() * 0.5), int(pix.height() * 0.5));
  painter.drawPixmap(10, 30, pix);
}

MainScene::~MainScene() {
  delete ui;
}
