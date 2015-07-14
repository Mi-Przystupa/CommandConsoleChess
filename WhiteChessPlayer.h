#ifndef WHITECHESSPLAYER_H
#define WHITECHESSPLAYER_H

#include "ChessPlayer.h"


class WhiteChessPlayer : public ChessPlayer
{
    public:
        WhiteChessPlayer();
        virtual ~WhiteChessPlayer();
        position_t* GetAvailableMoves(int x, int y,char cell);
        void MoveSelectedPiece(int x, int y);
    private:
        void InitializeWhitePieces();
        ChessPiece* PieceIndex(int j);
 };

#endif // WHITECHESSPLAYER_H
