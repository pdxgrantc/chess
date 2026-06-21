#ifndef PIECE_CPP
#define PIECE_CPP

#include <iostream>
#include <string>

#include "piece.h"

Piece::Piece()
{
    this->type = 0;
    this->player = 0;
}

/*
 * @brief Sets the player and type of piece for particular board cell.
 * @param player integer value for the player 0 is white 1 is black.
 * @param type of piece 0 being pawn through king being 6.
 */
void Piece::setPiece(int player, int type)
{
    this->type = type;
    this->player = player;
}

Piece::~Piece()
{
}

Piece &Piece::operator=(const Piece &other)
{
    // Self assignment protection
    if (this == &other)
    {
        return *this;
    }

    type = other.type;
    player = other.player;

    return *this;
}

void Piece::printPiece()
{
    std::cout << getCorrectIcon();
    return;
    if (type == 0)
    {
        std::cout << " ";
        return;
    }
    if (player == 1)
    {
        std::cout << "\033[31m" << type << "\033[0m";
    }
    else
    {
        std::cout << type;
    }
}

std::string Piece::getCorrectIcon()
{
    if (player == 0)
    {
        switch (type)
        {
        case 1:
            return u8"\u2659"; // ♙
        case 2:
            return u8"\u2658"; // ♘
        case 3:
            return u8"\u2657"; // ♗
        case 4:
            return u8"\u2656"; // ♖
        case 5:
            return u8"\u2655"; // ♕
        case 6:
            return u8"\u2654"; // ♔
        default:
            return " ";
        }
    }
    else
    {
        switch (type)
        {
        case 1:
            return u8"\u265F"; // ♟
        case 2:
            return u8"\u265E"; // ♞
        case 3:
            return u8"\u265D"; // ♝
        case 4:
            return u8"\u265C"; // ♜
        case 5:
            return u8"\u265B"; // ♛
        case 6:
            return u8"\u265A"; // ♚
        default:
            return " ";
        }
    }
}

#endif
