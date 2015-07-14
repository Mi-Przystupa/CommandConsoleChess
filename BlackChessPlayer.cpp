#include "BlackChessPlayer.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"

BlackChessPlayer::BlackChessPlayer()
{
    InitializeBlackPieces();
}

BlackChessPlayer::~BlackChessPlayer()
{
    //dtor
}

void BlackChessPlayer::InitializeBlackPieces(){


   for (int i = 0; i < 8; i++){
        ChessPiece* pawn = new Pawn(i,6, "Black");
        m_availablePieces['P'].push_back(pawn);
   }
   for (int i = 0; i < 8; i++){
        ChessPiece* addToBoard = PieceIndex(i);
        m_availablePieces[addToBoard->GetSymbol()].push_back(addToBoard);
   }

}

ChessPiece* BlackChessPlayer::PieceIndex(int j){
    if(j == 0 || j== 7){
        return new Rook(j, 7, "Black");
    }
     if(j == 1 || j== 6){
        return new Knight(j, 7,"Black");
    }
    if(j == 2 || j== 5){
        return new Bishop(j, 7, "Black");
    }
    if(j == 3){
        return new Queen(j, 7,"Black");
    }
    if(j == 4){
        return new King(j,7, "Black");
    }
    return new Pawn(j,7, "Black");
}


position_t* BlackChessPlayer::GetAvailableMoves(int x, int y, char cell){
    return 0;
}
void BlackChessPlayer::MoveSelectedPiece(int x, int y){

}

