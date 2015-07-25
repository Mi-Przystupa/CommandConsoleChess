#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"


class Queen : public ChessPiece
{
    public:
        Queen(int x, int y, std::string side);
        ~Queen();

        PieceType GetPieceType();
        std::vector<position_t> GetValidMoves();
        std::vector<position_t> DiagonalMoves();
};

#endif // QUEEN_H
