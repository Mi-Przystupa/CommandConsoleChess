#ifndef BLACKCHESSPLAYER_H
#define BLACKCHESSPLAYER_H

#include "ChessPlayer.h"
//#include "ChessPiece.h"
#include <vector>


class BlackChessPlayer : public ChessPlayer
{
    public:
        BlackChessPlayer();
        virtual ~BlackChessPlayer();

        position_t* GetAvailableMoves(int x, int y,char cell);
        void MoveSelectedPiece(int x, int y);
    private:
        void InitializeBlackPieces();
        ChessPiece* PieceIndex(int j);
};

#endif // BLACKCHESSPLAYER_H
