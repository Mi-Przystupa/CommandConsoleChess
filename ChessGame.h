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
        bool m_currentPlayerIsBlack;

        void DisplayRequestedPieces(char piece);
        void DisplayCoordinates(position_t p);
        std::string GetPieceCoordinatesString(int index,char pieceName);
};

#endif // CHESSGAME_H
