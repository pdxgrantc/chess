#include <iostream>
#include "game.h"

int main() {
    Game *chess = new Game(1);

    cout << endl;

    chess->gameLoop();

    delete chess;
    return 0;
}

/*
Valid Move
1. Is in check/checkmate
User input

*/