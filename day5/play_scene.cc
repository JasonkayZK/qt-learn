//
// Created by jasonkay on 2024/3/9.
//

#include "play_scene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include "config.h"
#include "dataconfig.h"
#include <QTimer>
#include <QLabel>
#include <QSoundEffect>
#include <QPropertyAnimation>

PlayScene::PlayScene(int levelNum) {
  QString str = QString("关卡 %1").arg(levelNum);
  qDebug() << "进入到了：" << str;
  this->levelIndex = levelNum;

  /// 初始化游戏场景
  // 设置固定大小
  this->setFixedSize(MAIN_WIDTH, MAIN_HEIGHT);
  // 设置图标
  this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
  // 设置标题
  this->setWindowTitle(str);
  // 创建菜单栏
  QMenuBar *bar = menuBar();
  setMenuBar(bar);
  // 创建开始菜单
  QMenu *startMenu = bar->addMenu("开始");
  // 创建退出 菜单项
  QAction *quitAction = startMenu->addAction("退出");
  // 点击退出 实现退出游戏
  connect(quitAction, &QAction::triggered, [=]() {
    this->close();
  });

  /// 翻金币音效
  auto *flipSound = new QSoundEffect(this);
  flipSound->setSource(QUrl::fromLocalFile(":/res/ConFlipSound.wav"));
  /// 胜利按钮音效
  auto *winSound = new QSoundEffect(this);
  winSound->setSource(QUrl::fromLocalFile(":/res/LevelWinSound.wav"));
  /// 返回按钮音效
  auto *backSound = new QSoundEffect(this);
  backSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));

  /// 返回按钮
  auto *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
  backBtn->setParent(this);
  backBtn->move(this->width() - backBtn->width() - 20, this->height() - backBtn->height() - 20);
  /// 点击返回
  connect(backBtn, &MyPushButton::clicked, [=]() {
    qDebug() << "翻金币场景中：点击了返回按钮";
    backSound->play();
    QTimer::singleShot(500, this, [=]() {
      emit this->chooseSceneBack();
    });
  });

  /// 显示当前关卡数
  auto *levelLabel = new QLabel;
  levelLabel->setParent(this);
  QFont font;
  font.setFamily("华文新魏");
  font.setPointSize(26);
  QString str1 = QString("Level: %1").arg(this->levelIndex);
  // 将字体设置到标签控件中
  levelLabel->setFont(font);
  levelLabel->setText(str1);
  levelLabel->setGeometry(30, this->height() - 50, 120, 50);

  /// 加载并创建硬币数据
  dataConfig config;
  /// 临时存储金币数组
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
    }
  }

  /// 胜利时候显示的图片（结束时从窗口外飘入）
  auto *winLabel = new QLabel;
  QPixmap tmpPix;
  tmpPix.load(":/res/LevelCompletedDialogBg.png");
  winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
  winLabel->setPixmap(tmpPix);
  winLabel->setParent(this);
  winLabel->move(int((this->width() - tmpPix.width()) * 0.5), -tmpPix.height());

  /// 金币背景图案
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      QPixmap pix = QPixmap(":/res/BoardNode.png");
      auto *label = new QLabel;
      label->setScaledContents(true);
      label->setGeometry(0, 0, int(pix.width() * 1.2), int(pix.height() * 1.2));

      label->setPixmap(pix);
      label->setParent(this);
      label->move(40 + i * 60, 200 + j * 60);

      QString img = this->gameArray[i][j] == 1 ? ":/res/Coin0001.png" : ":/res/Coin0008.png";
      auto *coin = new MyCoin(img);
      coin->setParent(label);

      /// 给金币属性赋值
      coin->posX = i;
      coin->posY = j;
      coin->flag = this->gameArray[i][j]; /// 1正面 0反面
      coin->notPress = false;

      coinBtn[i][j] = coin;

      /// 点击金币，进行反转
      connect(coin, &MyCoin::clicked, [=]() {

        /// 点击的过程中，默认为赢，防止恶意卡bug，在点击的同时点其他按钮
        for (int l = 0; l < 4; l++) {
          for (int m = 0; m < 4; m++) {
            this->isWin = true;
          }
        }
        flipSound->play();
        coin->changeFlag(36);

        /// 点击金币之后，需要更新一下数组，如果存的是正面，点击后是反面
        this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

        /// 反转周围的金币
        // 上
        if (coin->posY - 1 >= 0) {
          coinBtn[coin->posX][coin->posY - 1]->changeFlag(50);
          this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 0 ? 1 : 0;
        }
        // 下
        if (coin->posY + 1 <= 3) {
          coinBtn[coin->posX][coin->posY + 1]->changeFlag(50);
          this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 0 ? 1 : 0;
        }
        // 左
        if (coin->posX - 1 >= 0) {
          coinBtn[coin->posX - 1][coin->posY]->changeFlag(50);
          this->gameArray[coin->posX - 1][coin->posY] = this->gameArray[coin->posX - 1][coin->posY] == 0 ? 1 : 0;
        }
        // 右
        if (coin->posX + 1 <= 3) {
          coinBtn[coin->posX + 1][coin->posY]->changeFlag(50);
          this->gameArray[coin->posX + 1][coin->posY] = this->gameArray[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
        }
        /// 翻完金币，默认还未胜利，继续判断
        for (int l = 0; l < 4; l++) {
          for (int m = 0; m < 4; m++) {
            this->isWin = true;
          }
        }

        this->isWin = true;
        // 判断是否有银币，如果有说明游戏还没胜利
        for (auto &l : this->coinBtn) {
          for (auto &m : l) {
            if (!m->flag) {
              this->isWin = false;
              break;
            }
          }
        }
        /// 没有银币了，那么游戏胜利！
        if (this->isWin) {
          winSound->play();
          qDebug() << "游戏胜利！";
          /// 禁用按钮
          for (auto &l : this->coinBtn) {
            for (auto &m : l) {
              m->notPress = true;
            }
          }

          auto *ani = new QPropertyAnimation(winLabel, "geometry");
          ani->setDuration(1000);
          ani->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
          ani->setEndValue(QRect(winLabel->x(), winLabel->y() + 360, winLabel->width(), winLabel->height()));
          ani->setEasingCurve(QEasingCurve::OutBounce);
          ani->start();
          winLabel->raise(); /// 将图片显示在最顶层，如果没有，图片将显示在最底层
        }
      });
    }
  }
}

void PlayScene::paintEvent(QPaintEvent *) {
  /// 创建背景
  QPainter painter(this);
  QPixmap pix;
  pix.load(":/res/PlayLevelSceneBg.png");
  painter.drawPixmap(0, 0, this->width(), this->height(), pix);

  /// 加载标题
  pix.load(":/res/Title.png");
  pix = pix.scaled(int(pix.width() * 0.5), int(pix.height() * 0.5));
  painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
