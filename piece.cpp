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
    { // white
        switch (type)
        {
        case 1:
            return " ";
            break;
        case 2:
            return " ";
            break;
        case 3:
            return " ";
            break;
        case 4:
            return " ";
            break;
        case 5:
            return " ";
            break;
        case 6:
            return "\u265A";
            break;
        default:
            return " ";
            break;
        }
    }else {
        switch (type)
        {
        case 1:
            return " ";
            break;
        case 2:
            return " ";
            break;
        case 3:
            return " ";
            break;
        case 4:
            return " ";
            break;
        case 5:
            return " ";
            break;
        case 6:
            return "b";
            return "\u2654";
            break;
        default:
            return " ";
            break;
        }
    }
}

#endif
