#include "WhiteChessPlayer.h"

#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"

WhiteChessPlayer::WhiteChessPlayer()
{
    InitializeWhitePieces();
}

WhiteChessPlayer::~WhiteChessPlayer()
{
    //dtor
}

void WhiteChessPlayer::InitializeWhitePieces(){


   for (int i = 0; i < 8; i++){
        ChessPiece* pawn = new Pawn(i,1, "White");
        m_availablePieces['p'].push_back(pawn);
   }
   for (int i = 0; i < 8; i++){
        ChessPiece* addToBoard = PieceIndex(i);
        m_availablePieces[addToBoard->GetSymbol()].push_back(addToBoard);
   }

}

ChessPiece* WhiteChessPlayer::PieceIndex(int j){
    if(j == 0 || j== 7){
        return new Rook(j, 0, "White");
    }
     if(j == 1 || j== 6){
        return new Knight(j, 0,"White");
    }
    if(j == 2 || j== 5){
        return new Bishop(j, 0, "White");
    }
    if(j == 3){
        return new Queen(j, 0,"White");
    }
    if(j == 4){
        return new King(j,0, "White");
    }
    return new Pawn(j,0, "White");
}


position_t* WhiteChessPlayer::GetAvailableMoves(int x, int y, char cell){
    return 0;
}
void WhiteChessPlayer::MoveSelectedPiece(int x, int y){

}

