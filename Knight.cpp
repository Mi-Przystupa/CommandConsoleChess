#include "Knight.h"

Knight::Knight(int x, int y, std::string side)
{
    //ctor
    SetPosition(x,y);
    m_symbol = side == "Black" ? 'K' : 'k';
}

Knight::~Knight()
{
    //dtor
}

PieceType Knight::GetPieceType(){
    return knight;
}
