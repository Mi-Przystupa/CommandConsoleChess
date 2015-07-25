//#include <ChessPiece.h>


#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"
#include <string>

class Pawn : public ChessPiece
{
    private:
        std::vector<position_t> BlackMoves();
        std::vector<position_t> WhiteMoves();

    public:
        Pawn(int x, int y,std::string side);
        virtual ~Pawn();

        PieceType GetPieceType();
        std::vector<position_t> GetValidMoves();

};

#endif // PAWN_H
