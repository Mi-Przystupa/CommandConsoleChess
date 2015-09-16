#include "ChessBoard.h"
#include <cctype>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "include/EmptyPiece.h"
#include "PieceException.h"
#include "MoveException.h"
#include "PathException.h"
#include "CaptureException.h"

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
bool ChessBoard::MovePiece(int xs, int ys, int xnew, int ynew) {
    ChessPiece* pieceMoving = m_board[ys][xs];
    bool pieceMoved = false;

    if (IsValidMove(pieceMoving, xnew, ynew)){

        ChessPiece* newSquare = m_board[ynew][xnew];
        m_board[ynew][xnew]  = m_board[ys][xs];
        //Piece Moved to new square
        m_board[ynew][xnew]->SetPosition(xnew,ynew);

        if(newSquare->GetSymbol() != '_' ){
            newSquare->SetIsAvailable(false);
            m_board[ys][xs] = new EmptyPiece(ys, xs);
        } else{
            newSquare->SetPosition(xs, ys);
            m_board[ys][xs] = newSquare;
        }
        pieceMoved = true;
    }
    return pieceMoved;
}

bool ChessBoard::IsValidMove(ChessPiece* piece, int x, int y){
    bool ret = true;
    try {
        if (!IsMoveAvailable(piece, position_t(x,y))){
            throw MoveException();
        }
        //If both pieces on same side, move is invalid
        if(AreSameColor(m_board[y][x]->GetSymbol(),piece->GetSymbol())){
            throw PieceException();
        }

        if (!IsPathClear(piece,x,y)) {
            throw PathException();
        }

        if(!CaptureAllowable(piece,x, y)){
            throw CaptureException();
        }
    } catch (ChessException e) {
        std::cout << e.what() << std::endl;
        ret = false;
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

bool ChessBoard::AreSameColor(char p1, char p2){
    if (p1 == '_' || p2 == '_'){
        return false; // one of the squares is empty
    }
    bool bothBlack = std::isupper(p1) && std::isupper(p2);
    bool bothWhite = !std::isupper(p1) && !std::isupper(p2);

    return bothBlack || bothWhite;
}

//Requirement: The x,y coordinates have been established to be a valid move for the piece
//TODO: Add a check so this no longer is the case
bool ChessBoard::IsPathClear(ChessPiece* piece, int x, int y){
    //Knights don't have a limit
    if (piece->GetSymbol() == 'k' ||piece->GetSymbol() == 'K' ){
        return true;
    }
    //We weren't moving
    if(piece->GetPosition().x == x && piece->GetPosition().y == y){
        return false;
    }
    //If the difference is just 1 square, is fine
    if (IsAdjacentSquare(piece->GetPosition(), position_t(x,y))){
        return true;
    }
    //At this point we've established move is at least 2 squares away in some direction
    bool isPathClear = true;
    int modifier = 1;
    position_t piecePos(piece->GetPosition());
    int xmodified = piecePos.x;
    int ymodified = piecePos.y;

    while(xmodified != x || ymodified != y){
        xmodified = piecePos.x;
        ymodified = piecePos.y;

        if (piecePos.x == x && piecePos.y != y){
            ymodified = piecePos.y + (y - piecePos.y > 0 ? modifier : -1 * modifier);
        } else if (piecePos.x != x && piecePos.y ==y){
            xmodified = piecePos.x + (x - piecePos.x > 0 ? modifier : -1 * modifier);
        } else {
            xmodified = piecePos.x + (x - piecePos.x > 0 ? modifier : -1 * modifier);
            ymodified = piecePos.y + (y - piecePos.y > 0 ? modifier : -1 * modifier);
        }

        if(m_board[ymodified][xmodified]->GetSymbol() !='_'){
            isPathClear = false;
        }
        modifier++;
    }
    return isPathClear;
}
//Required Is already established x,y is one of the valid moves && not on same side
bool ChessBoard::CaptureAllowable(ChessPiece* piece,int x,int y){
    /*
    If piece is pawn && move is diagnollay, then valid only if square is not
    */
    //Return true, because no special rules needed
    if (std::toupper(piece->GetSymbol()) != 'P')
        return true;


    //Is a diagonal move so is valid for pawn
    if (piece->GetPosition().x - x != 0 && m_board[y][x]->GetSymbol() != '_' ){
        return true;
    } else if (piece->GetPosition().x - x == 0 && m_board[y][x]->GetSymbol() == '_'){
        return true; //Mean's pawn is moving forward
    }
    //Else is an invalid capture
    return false;
}

bool ChessBoard::IsAdjacentSquare(position_t p1, position_t p2){
    bool adjacentX = p2.x - p1.x <=1 && p2.x - p1.x >= -1;
    bool adjacentY = p2.y - p1.y <=1 && p2.y - p1.y >= -1;
    return adjacentX && adjacentY;
}

bool ChessBoard::IsMoveAvailable(ChessPiece* piece, position_t newpos){
    bool ret = false;
    std::vector<position_t> validMoves(piece->GetValidMoves());
    for (std::vector<position_t>::iterator i = validMoves.begin(); i != validMoves.end(); i++ ){
        if((*i) == newpos){
            ret = true;
            break;
        }
    }

    return ret;
}
