#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"


class Knight : public ChessPiece
{
    public:
        Knight(int x, int y, std::string side);
        virtual ~Knight();
        PieceType GetPieceType();
        std::vector<position_t> GetValidMoves();
};

#endif // KNIGHT_H
