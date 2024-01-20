//
// Created by Jasonkay on 2022/5/13.
//

#ifndef MINE_SWEEPER_CONSTS_H
#define MINE_SWEEPER_CONSTS_H

// Game status
enum GameState {
  // not finish
  PLAYING,
  // wrong mark
  FAULT,
  // lose
  OVER,
  // win
  WIN
};

// Game level
enum GameLevel {
  BASIC,
  MEDIUM,
  HARD
};

// Default param for MineSweeper game
const int kRow = 15;
const int kCol = 20;
const int kMineCount = 50;
const int kTime = 0;

#endif //MINE_SWEEPER_CONSTS_H
