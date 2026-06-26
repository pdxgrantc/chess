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
    cout << isInCheck() << endl;
    // isCheckmate();

    // Is check mate
    // Take user input
    // Check if valid move
}

bool Game::isInCheck()
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
    bool isInCheck = false;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            // find other player's pieces
            if (gameBoard->getPlayer(i, j) != player_to_move)
            {
                
                // For each piece pass current king location in and check for a check condition
                switch (gameBoard->getType(i, j))
                {
                case 1: // pawn
                    isInCheck = findPawnCheck(ik, jk, i, j);
                    break;
                case 2: // knight
                    isInCheck = findKnightCheck(ik, jk, i, j);
                    break;
                case 3: // bishop
                    isInCheck = findBishopCheck(ik, jk, i, j);
                    break;
                case 4: // rook
                    isInCheck = findRookCheck(ik, jk, i, j);
                    break;
                case 5: // queen
                    isInCheck = findQueenCheck(ik, jk, i, j);
                    break;
                // case 6: // king
                //    break;
                default:
                    // blank or king
                    break;
                }
                
                if (isInCheck) {
                    return true;
                }
            }
        }
    }
    return false;
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
        //! White's turn
        // cant move down more
        if (ip == 0)
        {
            // cant move down
            return false;
        }

        // if down and left
        if (((ip - 1) == ik) && ((jp - 1) == jk))
        {
            return true;
        }

        // if down and right
        if (((ip - 1) == ik) && ((jp + 1) == jk))
        {
            return true;
        }
        // TODO en passant
    }
    else
    {
        //! Black's turn
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

/*
 * @brief takes a current players king location and checks if they are in check by an opposing knight.
 * @param ik rank of the defending king
 * @param jk file of the defending king
 * @param in rank of the attacking knight
 * @param jn file of the attacking knight
 */
bool Game::findKnightCheck(int ik, int jk, int in, int jn)
{
    // Turn doesn't matter for knights
    // up left
    if (((in + 2) == ik) && ((jn - 1) == jk))
    {
        return true;
    }
    // up right
    if (((in + 2) == ik) && ((jn + 1) == jk))
    {
        return true;
    }

    // left up
    if (((in + 1) == ik) && ((jn - 2) == jk))
    {
        return true;
    }
    // left down
    if (((in - 1) == ik) && ((jn - 2) == jk))
    {
        return true;
    }
    // down left
    if (((in - 2) == ik) && ((jn - 1) == jk))
    {
        return true;
    }
    // down right
    if (((in - 2) == ik) && ((jn + 1) == jk))
    {
        return true;
    }
    // right up
    if (((in + 1) == ik) && ((jn + 2) == jk))
    {
        return true;
    }
    // right down
    if (((in - 1) == ik) && ((jn + 2) == jk))
    {
        return true;
    }
    return false;
}

/*
 * @brief takes a current players king location and checks if they are in check by an opposing bishop.
 * @param ik rank of the defending king
 * @param jk file of the defending king
 * @param ib rank of the attacking bishop
 * @param jb file of the attacking bishop
 */
bool Game::findBishopCheck(int ik, int jk, int ib, int jb)
{
    // up left diagonal
    int i = ib, j = jb;
    while ((i < 8) && (j > -1))
    {
        // increment up and left
        i++;
        j--;

        // check if the king is here
        if ((ik == i) && (jk == j))
        {
            // king is in check
            return true;
        }

        // check for piece in new square
        int typeInSquare = gameBoard->getType(i, j);
        if (typeInSquare != 0)
        {
            // Piece is there we can break the loop
            break;
        }
    }

    // up right diagonal
    i = ib, j = jb;
    while ((i < 8) && (j < 8))
    {
        // increment up and left
        i++;
        j++;

        // check if the king is here
        if ((ik == i) && (jk == j))
        {
            // king is in
            return true;
        }

        // check for piece in new square
        int typeInSquare = gameBoard->getType(i, j);
        if (typeInSquare != 0)
        {
            // Piece is there we can break the loop
            break;
        }
    }

    // down left diagonal
    i = ib, j = jb;
    while ((i > -1) && (j > -1))
    {
        // increment up and left
        i--;
        j--;

        // check if the king is here
        if ((ik == i) && (jk == j))
        {
            // king is in
            return true;
        }

        // check for piece in new square
        int typeInSquare = gameBoard->getType(i, j);
        if (typeInSquare != 0)
        {
            // Piece is there we can break the loop
            break;
        }
    }

    // down right diagonal
    i = ib, j = jb;
    while ((i > -1) && (j < 8))
    {
        // increment up and left
        i--;
        j++;

        // check if the king is here
        if ((ik == i) && (jk == j))
        {
            // king is in
            return true;
        }

        // check for piece in new square
        int typeInSquare = gameBoard->getType(i, j);
        if (typeInSquare != 0)
        {
            // Piece is there we can break the loop
            break;
        }
    }
    return false;
}

/*
 * @brief takes a current players king location and checks if they are in check by an opposing rook.
 * @param ik rank of the defending king
 * @param jk file of the defending king
 * @param ir rank of the attacking rook
 * @param jr file of the attacking rook
 */
bool Game::findRookCheck(int ik, int jk, int ir, int jr)
{
    // up
    int i = ir, j = jr;
    while (i < 8)
    {
        // Increment
        i++;

        // check if the king is here
        if ((ik == i) && (jk == j))
        {
            // king is in
            return true;
        }

        // check for piece in new square
        int typeInSquare = gameBoard->getType(i, j);
        if (typeInSquare != 0)
        {
            // Piece is there we can break the loop
            break;
        }
    }

    // right
    i = ir, j = jr;
    while (i > -1)
    {
        // Increment
        i--;

        // check if the king is here
        if ((ik == i) && (jk == j))
        {
            // king is in
            return true;
        }

        // check for piece in new square
        int typeInSquare = gameBoard->getType(i, j);
        if (typeInSquare != 0)
        {
            // Piece is there we can break the loop
            break;
        }
    }

    // down
    i = ir, j = jr;
    while (j < 8)
    {
        // Increment
        j++;

        // check if the king is here
        if ((ik == i) && (jk == j))
        {
            // king is in
            return true;
        }

        // check for piece in new square
        int typeInSquare = gameBoard->getType(i, j);
        if (typeInSquare != 0)
        {
            // Piece is there we can break the loop
            break;
        }
    }

    // left
    i = ir, j = jr;
    while (j > -1)
    {
        // Increment
        j--;

        // check if the king is here
        if ((ik == i) && (jk == j))
        {
            // king is in
            return true;
        }

        // check for piece in new square
        int typeInSquare = gameBoard->getType(i, j);
        if (typeInSquare != 0)
        {
            // Piece is there we can break the loop
            break;
        }
    }
    return false;
}

/*
 * @brief takes a current players king location and checks if they are in check by an opposing rook.
 * @param ik rank of the defending king
 * @param jk file of the defending king
 * @param ir rank of the attacking queen
 * @param jr file of the attacking queen
 */
bool Game::findQueenCheck(int ik, int jk, int iq, int jq)
{
    if (findBishopCheck(ik, jk, iq, jq) || findRookCheck(ik, jk, iq, jq))
    {
        return true;
    }
    return false;
}

#endif
