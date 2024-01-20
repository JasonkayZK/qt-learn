//
// Created by Jasonkay on 2022/5/13.
//

#include "game_model.h"

#include <ctime>
#include <cstdlib>

GameModel::GameModel() noexcept
    : mRow(kRow),
      mCol(kCol),
      totalMineNumber(kMineCount),
      timerSeconds(kTime),
      gameState(PLAYING) {

  // No specific initiation in constructor, since the function call time is uncertain.
}

GameModel::~GameModel() = default;

// Dig current block
void GameModel::digMine(int m, int n) {
  // The block is normal and not dug, we mark it dug.
  if (gameMap[m][n].valueFlag > 0 && gameMap[m][n].curState == UN_DIG) {
    gameMap[m][n].curState = DUG;
  }

  // We met empty block(value is 0), keep mining recursively
  if (gameMap[m][n].valueFlag == 0 && gameMap[m][n].curState == UN_DIG) {
    gameMap[m][n].curState = DUG;
    for (int y = -1; y <= 1; y++) {
      for (int x = -1; x <= 1; x++) {
        if (m + y >= 0 && m + y < mRow && n + x >= 0 && n + x < mCol && !(x == 0 && y == 0)) {
          digMine(m + y, n + x);
        }
      }
    }
  }

  // Game over when we met bomb
  if (gameMap[m][n].valueFlag == -1) {
    gameState = OVER;
    gameMap[m][n].curState = BOMB;
  }

  // Check current frame for game
  checkGame();
}

// Mark current block
void GameModel::markMine(int m, int n) {
  // If the mark is wrong, it is recorded as a wrong mark,
  // and the drawing distinction is made at the end of the ui layer game
  // Notice: if a block is marked twice, it will return to the un-dig state
  if (gameMap[m][n].curState == UN_DIG) {
    if (gameMap[m][n].valueFlag == -1) {
      gameMap[m][n].curState = MARKED;
    } else {
      gameState = FAULT;
      gameMap[m][n].curState = WRONG_BOMB;
    }
    // Mining the right mine will reduce curMineNumber by 1
    curMineNumber--;
  } else if (gameMap[m][n].curState == MARKED || gameMap[m][n].curState == WRONG_BOMB) {
    gameMap[m][n].curState = UN_DIG;
    gameState = PLAYING;
    // Recover the mine number
    curMineNumber++;
  }

  // Check current frame for game
  checkGame();
}

// Create a new game
void GameModel::createGame(int row, int col, int mineCount, GameLevel level) {
  // Clear the old game
  gameMap.clear();

  // Set new game parameters
  mRow = row;
  mCol = col;
  totalMineNumber = mineCount;
  curMineNumber = mineCount;
  gameState = PLAYING;
  gameLevel = level;
  timerSeconds = 0;

  // Initialize all blocks
  for (int i = 0; i < mRow; i++) {
    std::vector<MineBlock> lineBlocks;
    for (int j = 0; j < mCol; j++) {
      MineBlock mineBlock{};
      mineBlock.curState = UN_DIG; // All default state is un-dig
      mineBlock.valueFlag = 0;     // All default value is 0
      lineBlocks.push_back(mineBlock);
    }
    gameMap.push_back(lineBlocks);
  }

  // Randomly generate the bombs
  srand((unsigned int) time(nullptr));
  int k = totalMineNumber;
  while (k > 0) {
    // Set bombs & avoid overlap
    int pRow = rand() % mRow;
    int pCol = rand() % mCol;
    if (gameMap[pRow][pCol].valueFlag != -1) {
      gameMap[pRow][pCol].valueFlag = -1;
      k--;
    }
    // We need to generate again, when overlap
  }

  // Calculate the value of each block
  for (int i = 0; i < mRow; i++) {
    for (int j = 0; j < mCol; j++) {
      // The numbers of the surrounding eight squares (excluding yourself, within the map range),
      // are superimposed according to the number of mines
      // Notice: the condition is that this block is not a bomb
      if (gameMap[i][j].valueFlag != -1) {
        for (int y = -1; y <= 1; y++) {
          for (int x = -1; x <= 1; x++) {
            if (i + y >= 0 && i + y < mRow && j + x >= 0 && j + x < mCol &&
                gameMap[i + y][j + x].valueFlag == -1 && !(x == 0 && y == 0)) {
              // block number + 1
              gameMap[i][j].valueFlag++;
            }
          }
        }
      }
    }
  }
}

// Use current parameter to restart game
void GameModel::restartGame() {
  createGame(mRow, mCol, totalMineNumber, gameLevel);
}

// Check current frame for game
void GameModel::checkGame() {
  // Show all the bomb, when game over
  if (gameState == OVER) {
    // reveal all bombs
    for (int i = 0; i < mRow; i++) {
      for (int j = 0; j < mCol; j++) {
        if (gameMap[i][j].valueFlag == -1) {
          gameMap[i][j].curState = BOMB;
        }
      }
    }
    return;
  }

  if (gameState != FAULT) {
    for (int i = 0; i < mRow; i++) {
      for (int j = 0; j < mCol; j++) {
        if (gameMap[i][j].curState == UN_DIG) {
          gameState = PLAYING;
          return;
        }
      }
    }
    // All bombs marked and all block dug
    gameState = WIN;
  }
}
