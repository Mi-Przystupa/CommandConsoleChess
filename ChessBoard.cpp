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
//TODO: Should be passing in complext data
bool ChessBoard::MovePiece(int xs, int ys, int xnew, int ynew){
    ChessPiece* pieceMoving = m_board[ys][xs];
    bool pieceMoved = false;

    if (IsValidMove(pieceMoving, xnew, ynew)){

        ChessPiece* newSquare = m_board[ynew][xnew];
        m_board[ynew][xnew]  = m_board[ys][xs];
        //Piece Moved to new square
        m_board[ynew][xnew]->SetPosition(xnew,ynew);

        if(newSquare->GetSymbol() != '_'){
            newSquare->SetIsAvailable(false);
            m_board[ys][xs] = new EmptyPiece(ys, xs);
        } else{
            newSquare->SetPosition(xs, ys);
            m_board[ys][xs] = newSquare;
        }
        pieceMoved = true;
    } else {
        printf("Error, Invalid Move\n");
    }
    return pieceMoved;
}

bool ChessBoard::IsValidMove(ChessPiece* piece, int x, int y){

    bool ret = false;

    //TODO: This is definitely a helper function
    std::vector<position_t> validMoves(piece->GetValidMoves());
    for (std::vector<position_t>::iterator i = validMoves.begin(); i != validMoves.end(); i++ ){
        if((*i).x == x && (*i).y == y){
            ret = true;
            break;
        }
    }

    ChessPiece* occupiedSquare = m_board[y][x];
    if(ret && occupiedSquare->GetSymbol() != '_' ){
        //TODO: Helper Function: determine if pieces are on different sides URGENT!! DEAL WITH ME
        //if both pieces are of same type, it is an invalid move
        ret = !((std::isupper(piece->GetSymbol()) && std::isupper(occupiedSquare->GetSymbol()))
                 ||
                (!std::isupper(piece->GetSymbol()) && !std::isupper(occupiedSquare->GetSymbol())));

    }


    return ret;
}


ChessPiece*** ChessBoard::GetBoard(){
	return m_board;
}

void ChessBoard::DisplayBoard(){
    printf(" ");
    for (int i = 0; i < boardHeight; i++){
        printf("%d", i);
    }
    printf("\n");
    for (int i = 0; i < boardHeight;i++){
        printf("%d", i);
        for(int j = 0; j < boardWidth; j++){
            printf("%c", m_board[i][j]->GetSymbol());
        }
        printf("\n");
	}
}

char ChessBoard::getCell(int x, int y){
    return m_board[x][y]->GetSymbol();
}
