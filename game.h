#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
private:
    int player_to_move;
    int turn;

    Board gameBoard;

public:
    Game();
    ~Game();
};

#include "game.cpp"

#endif
