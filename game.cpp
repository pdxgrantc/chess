#ifndef GAME_CPP
#define GAME_CPP

#include <iostream>

using namespace std;

#include "game.h"

Game::Game()
{
    this->player_to_move = 0;
    this->turn = 0;

    gameBoard = new Board;
}

Game::Game(int i)
{
    this->player_to_move = 0;
    this->turn = 0;

    gameBoard = new Board(1);
}

Game::~Game()
{
    delete gameBoard;
}

void Game::gameLoop()
{
    cout << "Starting game. Player " << (this->player_to_move + 1) << "'s turn." << endl;

    // Is my player in check
    isInCheck();
    // isCheckmate();

    // Is check mate
    // Take user input
    // Check if valid move
}

void Game::isInCheck()
{
    // for across game and only for current player

    int ik, jk; // Variables to store where current player has their king

    int i, j;
    // FInd Current player king
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            // Loop through all board indexes
            if ((gameBoard->getPlayer(i, j) == this->player_to_move) && (gameBoard->getType(i, j) == 6))
            {
                // Save current player's king location
                ik = i;
                jk = j;
            }
        }
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            // find other player's pieces
            if (gameBoard->getPlayer(i, j) != player_to_move)
            {
                bool isInCheck = false;
                // For each piece pass current king location in and check for a check condition
                switch (gameBoard->getType(i, j))
                {
                case 1: // pawn
                    isInCheck = findPawnCheck(ik, jk, i, j);
                    break;
                case 2: // knight
                    break;
                case 3: // bishop
                    break;
                case 4: // rook
                    break;
                case 5: // queen
                    break;
                // case 6: // king
                //    break;
                default:
                    // blank or king
                    break;
                }
            }
        }
    }
}

/*
 * @brief takes a current players king location and checks if they are in check by an opposing pawn.
 * @param ik rank of the defending king
 * @param jk file of the defending king
 * @param ip rank of the attacking pawn
 * @param jp file of the attacking pawn
 */
bool Game::findPawnCheck(int ik, int jk, int ip, int jp)
{
    if (player_to_move == 0)
    {
        // White's turn
        // cant move down more
        if (ip == 0)
        {
            // cant move down
            return false;
        }

        // if down and left
        if (((ip - 1) == ik) && ((jp - 1) == jk))
        {
            cout << "Checking pawn location IP: " << ip << ", JP: " << jp << endl;
            return true;
        }

        // if down and right
        if (((ip - 1) == ik) && ((jp + 1) == jk))
        {
            cout << "Checking pawn location IP: " << ip << ", JP: " << jp << endl;
            return true;
        }
        // TODO en passant
    }
    else
    {
        // Black's turn
        if (ip == 7)
        {
            // cant move up
            return false;
        }

        // if up and left
        if (((ip + 1) == ik) && ((jp - 1) == jk))
        {
            return true;
        }

        // if up and right
        if (((ip + 1) == ik) && ((jp + 1) == jk))
        {
            return true;
        }
        // TODO en passant
    }
    return false;
}

#endif
