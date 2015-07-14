//#include <ChessPiece.h>


#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"
#include <string>

class Pawn : public ChessPiece
{
    public:
        Pawn(int x, int y,std::string side);
        virtual ~Pawn();

        PieceType GetPieceType();

};

#endif // PAWN_H
