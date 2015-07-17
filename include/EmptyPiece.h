#ifndef EMPTYPIECE_H
#define EMPTYPIECE_H

#include "..\ChessPiece.h"


class EmptyPiece : public ChessPiece
{
    public:
        EmptyPiece(int x, int y );
        virtual ~EmptyPiece();
        PieceType GetPieceType();
};

#endif // EMPTYPIECE_H
