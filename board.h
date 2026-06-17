#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "piece.h"

class Board
{
private:
    Piece board[8][8];
    void setupBoard();
    char printHeader[9] = "ABCDEFGH";

public:
    Board(/* args */);
    ~Board();
    void printBoard();
};

#include "board.cpp"

#endif
