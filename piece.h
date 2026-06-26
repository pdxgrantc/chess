#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>

class Piece
{
private:
    std::string getCorrectIcon();

public:
    int type; // 0 = no piece, 1 = pawn, 2=knight, 3=bishop, 4=rook, 5=queen, 6=king
    int player;
    int moves; // number of moves this piece has made, used for en pasant

    Piece();
    void setPiece(int player, int type);
    void printPiece();
};

#include "piece.cpp"

#endif
