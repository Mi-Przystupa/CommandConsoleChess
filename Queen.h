#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"


class Queen : public ChessPiece
{
    public:
        Queen(int x, int y, std::string side);
        ~Queen();

        PieceType GetPieceType();
};

#endif // QUEEN_H
