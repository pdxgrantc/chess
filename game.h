#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
private:
    int player_to_move;
    int turn;

    Board *gameBoard;
    void isInCheck();
    // Specific piece check finding functions
    bool findPawnCheck(int, int, int, int);
    bool findKnightCheck(int, int, int, int);
    bool findBishopCheck(int, int, int, int);
    bool findRookCheck(int, int, int, int);
    bool findQueenCheck(int, int, int, int);
    bool findKingCheck(int, int, int, int);

public:
    Game();
    Game(int);
    ~Game();
    void gameLoop();
};

#include "game.cpp"

#endif
