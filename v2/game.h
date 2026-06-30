#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
private:
    int player_to_move;
    int turn;

    Board *gameBoard;
    bool isInCheck(int, int);
    // Specific piece check finding functions
    std::pair<int, int> findKing();
    

    bool findPawnCheck(int, int, int, int);
    bool findKnightCheck(int, int, int, int);
    bool findBishopCheck(int, int, int, int);
    bool findRookCheck(int, int, int, int);
    bool findQueenCheck(int, int, int, int);
    bool isCheckmate(int, int);

public:
    Game();
    ~Game();
    void startGame();
};

#endif
