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
        void MovePiece(int xs, int ys, int xnew, int ynew);
        void displayBoard();
        ChessPiece*** GetBoard();
        char getCell(int x, int y);

    private:
        ChessPiece*** m_board;
        ChessPiece*** IntializeBoard();

};

#endif // CHESSBOARD_H
