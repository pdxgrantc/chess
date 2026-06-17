#ifndef PIECE_CPP
#define PIECE_CPP

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

#endif
