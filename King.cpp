#include "King.h"

King::King(int x, int y, std::string side)
{
    SetPosition(x,y);
    m_symbol = side == "Black" ? '?' : '+';
    //ctor
}

King::~King()
{
    //dtor
}

PieceType King::GetPieceType() {
    return king;
}

std::vector<position_t> King::GetValidMoves(){
    std::vector<position_t> validMoves;




    return validMoves;
}
