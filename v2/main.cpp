#include <iostream>
#include "game.h"

using namespace std;

int main() {
    Game *chess = new Game();

    chess->startGame();

    delete chess;
    return 0;
}

/*
Valid Move
1. Is in check/checkmate
User input

*/