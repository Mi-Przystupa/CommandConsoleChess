#ifndef WHITECHESSPLAYER_CPP_H
#define WHITECHESSPLAYER_CPP_H

#include "ChessPlayer.h"


class WhiteChessPlayer.cpp : public ChessPlayer
{
    public:
        WhiteChessPlayer.cpp();
        virtual ~WhiteChessPlayer.cpp();
        position_t* GetAvailableMoves(int x, int y,char cell);
        void MoveSelectedPiece(int x, int y);
    private:
        void InitializeWhitePieces();
        ChessPiece* PieceIndex(int j);
};

#endif // WHITECHESSPLAYER_CPP_H
