#include "ChessPlayer.h"

ChessPlayer::ChessPlayer()
{
    //ctor
}

ChessPlayer::~ChessPlayer()
{
    //dtor
}

std::vector<ChessPiece*> ChessPlayer::getAllPieces(){
    std::map<char,std::vector<ChessPiece*> >::iterator pieces = m_availablePieces.begin();
    std::vector<ChessPiece*> ret;
    while (pieces != m_availablePieces.end()){
        std::vector<ChessPiece*> chessPieceType = pieces->second;
        for (unsigned int i = 0; i < chessPieceType.size(); i++){
            ret.push_back(chessPieceType[i]);
        }
        pieces++;
    }
    return ret;
}
