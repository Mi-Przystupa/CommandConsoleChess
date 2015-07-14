#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"


class Bishop : public ChessPiece
{
    public:
        Bishop(int x, int y, std::string side);
        virtual ~Bishop();
        PieceType GetPieceType();
};

#endif // BISHOP_H
