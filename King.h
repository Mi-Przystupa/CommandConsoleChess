#ifndef KING_H
#define KING_H

#include "ChessPiece.h"


class King : public ChessPiece
{
    public:
        King(int x, int y, std::string side);
        virtual ~King();
        PieceType GetPieceType();
        std::vector<position_t> GetValidMoves();
};

#endif // KING_H
