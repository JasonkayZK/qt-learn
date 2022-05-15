//
// Created by Jasonkay on 2022/5/13.
//

#ifndef MINE_SWEEPER_MINE_BLOCK_H
#define MINE_SWEEPER_MINE_BLOCK_H

// The status of the block
enum BlockState {
    UN_DIG,
    DUG,
    MARKED,
    BOMB,
    WRONG_BOMB
};

// One block in MineSweeper
struct MineBlock {
    BlockState curState; // current status to BlockState
    int valueFlag; // the number of the block (0~8), -1 means the bomb
};

#endif //MINE_SWEEPER_MINE_BLOCK_H
