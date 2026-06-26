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

    void setupTestBoard();
public:
    Board(/* args */);
    Board(int i);
    ~Board();
    void tempMove(int, int, int, int);
    void printBoard();
    int getPlayer(int, int);
    int getType(int, int);
};

#include "board.cpp"

#endif
