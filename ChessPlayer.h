#ifndef CHESSPLAYER_H
#define CHESSPLAYER_H

#include "ChessPiece.h"
#include <map>
#include <vector>

class ChessPlayer
{
    public:
        ChessPlayer();
        virtual ~ChessPlayer();
        virtual position_t* GetAvailableMoves(int x, int y, char cell) = 0;
        virtual void MoveSelectedPiece(int x, int y) = 0;
        virtual std::vector<ChessPiece*> getAllPieces();
        virtual std::vector<ChessPiece*> GetAvailableRequestedPieces(char piece);
    protected:
        std::map<char, std::vector<ChessPiece*> > m_availablePieces;

};

#endif // CHESSPLAYER_H
