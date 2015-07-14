#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "ChessBoard.h"
#include "ChessPlayer.h"
#include "BlackChessPlayer.h"
#include "WhiteChessPlayer.h"

class ChessGame
{
    public:
        ChessGame();
        virtual ~ChessGame();

        void GetConsoleInput();
        void DisplaySelectPieceMoves();
        void DisplayBoard();
        void SwitchPlayer();
    private:
        BlackChessPlayer* m_ptrBlackPlayer;
        WhiteChessPlayer* m_ptrWhitePlayer;
        ChessBoard* m_ptrChessBoard;
        ChessPlayer* m_ptrCurrentPlayer;
        position_t m_coordinates;

};

#endif // CHESSGAME_H
