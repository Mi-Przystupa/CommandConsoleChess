#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
#include "ChessPiece.h"
const int boardWidth = 8;
const int boardHeight = boardWidth;


class ChessBoard
{
    public:
        ChessBoard();
        ChessBoard(std::vector<ChessPiece*> putOnboard);
        virtual ~ChessBoard();
        bool MovePiece(int xs, int ys, int xnew, int ynew);
        void DisplayBoard();
        ChessPiece*** GetBoard();
        char getCell(int x, int y);

        bool IsValidMove(ChessPiece* piece, int x, int y);
        bool AreSameColor(char p1, char p2);
        bool IsPathClear(ChessPiece* piece, int x, int y);
        bool CaptureAllowable(ChessPiece* piece,int x,int y);
        bool IsMoveAvailable(ChessPiece* piece, position_t newpos);
    private:
        ChessPiece*** m_board;
        ChessPiece*** IntializeBoard();
        bool IsAdjacentSquare(position_t p1, position_t p2);
};

#endif // CHESSBOARD_H
