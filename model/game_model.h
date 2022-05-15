//
// Created by Jasonkay on 2022/5/13.
//

#ifndef MINE_SWEEPER_GAME_MODEL_H
#define MINE_SWEEPER_GAME_MODEL_H

#include "consts.h"
#include "mine_block.h"

#include <vector>

class GameModel {

public:
    GameModel() noexcept;

    virtual ~GameModel();

    void digMine(int m, int n); //挖雷, m是行， n是列

    void markMine(int m, int n); // 标记雷

    void createGame(int row = kRow, int col = kCol, int mineCount = kMineCount, GameLevel level = MEDIUM); // 初始化游戏

    void restartGame();  // 按当前参数重新开始游戏

    void checkGame(); // 检查游戏输赢

public:
    std::vector<std::vector<MineBlock>> gameMap; // 游戏地图
    int mRow; // 地图行数
    int mCol; // 地图列数
    int totalMineNumber; // 雷数
    int curMineNumber;   // 当前雷数（仅用于显示）
    int timerSeconds; // 计时（秒）


    GameState gameState; // 当前游戏状态
    GameLevel gameLevel; // 当前游戏难度
};

#endif //MINE_SWEEPER_GAME_MODEL_H
