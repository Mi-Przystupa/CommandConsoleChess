#ifndef EMPTYPIECE_H
#define EMPTYPIECE_H

#include "..\ChessPiece.h"


class EmptyPiece : public ChessPiece
{
    public:
        EmptyPiece(int x, int y );
        virtual ~EmptyPiece();
        PieceType GetPieceType();
        std::vector<position_t> GetValidMoves();
};

#endif // EMPTYPIECE_H
