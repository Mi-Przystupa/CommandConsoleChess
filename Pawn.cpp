#include "Pawn.h"

Pawn::Pawn(int x, int y,std::string side)//, string side)
{
    SetPosition(x,y);
    m_symbol = "Black" == side ? 'P' : 'p';
    //ctor
}

Pawn::~Pawn()
{
    //dtor
}

PieceType Pawn::GetPieceType(){
    return pawn;
}

std::vector<position_t> Pawn::GetValidMoves(){
    //Black Moves, else white
    if(std::isupper(m_symbol)){
        return this->BlackMoves();
    } else {
        return this->WhiteMoves();
    }

}

 std::vector<position_t> Pawn::BlackMoves(){
    std::vector<position_t> validMoves;

    //board is square
    const int maxDimension = 8;

    const int modifier = 1;

    //Hasn't Moved Yet, so Can advance 2 squares
    if(m_position.y == 6){
        validMoves.push_back(position_t(m_position.x, m_position.y - 1));
        validMoves.push_back(position_t(m_position.x, m_position.y - 2));
    } else {
        validMoves.push_back(position_t(m_position.x, m_position.y - 1));
    }

    //Move left diagonally
    if(m_position.x - modifier >= 0 && 0 <= m_position.y - 1 ){
        validMoves.push_back(position_t(m_position.x - 1, m_position.y - 1));
    }
    //Move Right diagonally
    if(m_position.x + modifier < maxDimension && 0 <= m_position.y - 1){
        validMoves.push_back(position_t(m_position.x + 1, m_position.y - 1));
    }

    return validMoves;
 }
 std::vector<position_t> Pawn::WhiteMoves(){
    std::vector<position_t> validMoves;

    //board is square
    const int maxDimension = 8;

    const int modifier = 1;

    //Hasn't Moved Yet, so Can advance 2 squares
    if(m_position.y == 1){
        validMoves.push_back(position_t(m_position.x, m_position.y + 1));
        validMoves.push_back(position_t(m_position.x, m_position.y + 2));
    } else {
        validMoves.push_back(position_t(m_position.x, m_position.y + 1));
    }

    //Move left diagonally
    if(m_position.x - modifier >= 0 && m_position.y + 1 < maxDimension ){
        validMoves.push_back(position_t(m_position.x - 1, m_position.y + 1));
    }
    //Move Right diagonally
    if(m_position.x + modifier < 8 && m_position.y + 1 < maxDimension ){
        validMoves.push_back(position_t(m_position.x + 1, m_position.y + 1));
    }

    return validMoves;
 }
