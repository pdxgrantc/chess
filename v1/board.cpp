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

Board::Board(int i)
{
    switch (i)
    {
    case 1:
        setupTestBoard();
        break;
    default:
        setupBoard();
        break;
    }
}

Board::~Board()
{
}

int Board::getPlayer(int i, int j)
{
    return board[i][j].player;
}

int Board::getType(int i, int j)
{
    return board[i][j].type;
}

/*
 * @brief Function to temporally move a piece to a new square.
 * It will not increment the move counter for the piece or the player/game.
 * @attention The move will not occur if the new rank and file already contains a piece. 
 * @param oi old rank
 * @param oj old file
 * @param ni new rank
 * @param nj new file
 */
void Board::tempMove(int oi, int oj, int ni, int nj) {
    // Confirm empty new square
    if (board[ni][nj].type == 0) {
        // Make move
        Piece cache = board[ni][nj];
        board[ni][nj] = board[oi][oj];
        board[oi][oj] = cache;
    }
}

void Board::printBoard()
{
    int i, j;

    // Prints the header A-H
    std::cout << " \n ";
    for (j = 0; j < 8; j++)
    {
        std::cout << "   " << printHeader[j];
    }
    cout << endl;

    for (i = 7; i > -1; i--)
    {
        std::cout << "  ---------------------------------" << std::endl;
        std::cout << (i + 1);
        for (j = 0; j < 8; j++)
        {
            std::cout << " | ";
            board[(i)][j].printPiece();
        }
        std::cout << " |" << std::endl;
    }
    std::cout << "  ---------------------------------" << std::endl;
}

void Board::setupBoard() // Default Setup for new game with white on bottom
{
    // White is on ranks 1,2
    // Black is on ranks 7,8

    // Pawns
    for (int i = 0; i < 8; i++)
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

void Board::setupTestBoard()
{
    for (int i = 0; i < 8; i++)
    {
        board[1][i].setPiece(0, 1);
        board[6][i].setPiece(1, 1);
    }

    // Test piece
    board[2][3].setPiece(1, 1);
    board[4][3].setPiece(1, 1);
    board[2][3].setPiece(1, 1);
    board[4][3].setPiece(1, 1);

    board[3][2].setPiece(1, 4);
    board[4][5].setPiece(1, 3);

    // King
    board[3][3].setPiece(0, 6);
    board[7][4].setPiece(1, 6);
    printBoard();
}

#endif
