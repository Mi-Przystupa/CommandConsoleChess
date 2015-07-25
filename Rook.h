#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"


class Rook : public ChessPiece
{
    public:
        Rook(int x, int y,std::string side);
        virtual ~Rook();
        PieceType GetPieceType();
        std::vector<position_t> GetValidMoves();
};

#endif // ROOK_H
