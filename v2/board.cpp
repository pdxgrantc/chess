#ifndef BOARD_CPP
#define BOARD_CPP

#include <iostream>

#include "board.h"
#include "piece.h"

using namespace std;

Board::Board(/* args */)
{
    // allocate board

    setupBoard();
}

Board::~Board() {
    
}

void Board::setupBoard() {}

#endif
