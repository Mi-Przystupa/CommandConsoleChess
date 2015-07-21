#include "ChessBoard.h"
#include <cctype>
#include <stdio.h>
#include <vector>
#include "include/EmptyPiece.h"

ChessBoard::ChessBoard()
{
    //ctor
    m_board = IntializeBoard();//cpp

}

ChessBoard::ChessBoard(std::vector<ChessPiece*> putOnboard){
    //ChessBoard();
    m_board = IntializeBoard();
    std::vector<ChessPiece*>::iterator iterator = putOnboard.begin();

    while (iterator != putOnboard.end()){
        position_t coordinates = (*iterator)->GetPosition();
        m_board[coordinates.y][coordinates.x] = *iterator;
        iterator++;
    }
}

ChessBoard::~ChessBoard()
{
    //dtor
    delete m_board;
}

ChessPiece*** ChessBoard::IntializeBoard(){
	ChessPiece*** board = new ChessPiece**[boardHeight];

	for(int h = 0; h < boardHeight; h++){
		board[h] = new ChessPiece*[boardWidth];
	}

	for (int h = 0; h < boardHeight; h++){
		for(int w = 0; w < boardWidth;w++){
			board[h][w] = new EmptyPiece(h,w);
		}
	}
	return board;
}
void ChessBoard::MovePiece(int xs, int ys, int xnew, int ynew){
	m_board[xnew][ynew] = m_board[xs][ys];
}
ChessPiece*** ChessBoard::GetBoard(){
	return m_board;
}

void ChessBoard::displayBoard(){
    for (int i = 0; i < boardHeight;i++){
        for(int j = 0; j < boardWidth; j++){
            printf("%c", m_board[i][j]->GetSymbol());
        }
        printf("\n");
	}
}

char ChessBoard::getCell(int x, int y){
    return m_board[x][y]->GetSymbol();
}
