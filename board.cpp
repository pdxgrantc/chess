#ifndef BOARD_CPP
#define BOARD_CPP

#include <iostream>

#include "board.h"
#include "piece.h"

Board::Board(/* args */)
{
    // allocate board

    setupBoard();
}

Board::~Board()
{
}

void Board::printBoard()
{
    int i;
    std::cout << std::endl << " ";
    for (i = 0; i < 8; i++)
    {
        std::cout << "   " << printHeader[i];
    }
    std::cout << "  " ;
    std::cout << std::endl;
    for (i = 8; i > 0; i--)
    {

        std::cout << "  ---------------------------------" << std::endl;
        std::cout << (i);
        for (int j = 0; j < 8; j++)
        {
            std::cout << " | "; 
            board[(i - 1)][j].printPiece();
        }
        std::cout << " |" << std::endl;
    }
    std::cout << "  ---------------------------------" << std::endl;
}

void Board::setupBoard()
{
    int i, j;
    // player 1
    for (i = 0; i < 8; i++)
    {
        board[1][i].setPiece(0, 1);
        board[6][i].setPiece(1, 1);
    }
    // Rooks
    board[0][0].setPiece(0, 4);
    board[0][7].setPiece(0, 4);
    board[7][0].setPiece(1, 4);
    board[7][7].setPiece(1, 4);
    // Knights
    board[0][1].setPiece(0, 2);
    board[0][6].setPiece(0, 2);
    board[7][1].setPiece(1, 2);
    board[7][6].setPiece(1, 2);
    // Bishops
    board[0][2].setPiece(0, 3);
    board[0][5].setPiece(0, 3);
    board[7][2].setPiece(1, 3);
    board[7][5].setPiece(1, 3);
    // Queens
    board[0][3].setPiece(0, 5);
    board[7][3].setPiece(1, 5);
    // King
    board[0][4].setPiece(0, 6);
    board[7][4].setPiece(1, 6);

    printBoard();
}

#endif
