#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"


class Rook : public ChessPiece
{
    public:
        Rook(int x, int y,std::string side);
        virtual ~Rook();
        PieceType GetPieceType();
};

#endif // ROOK_H
