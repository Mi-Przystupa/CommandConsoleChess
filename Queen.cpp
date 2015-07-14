#include "Queen.h"

Queen::Queen(int x, int y, std::string side)
{
    SetPosition(x,y);
    m_symbol = "Black" == side ? 'Q' : 'q';
}

Queen::~Queen()
{
    //dtor
}

PieceType Queen::GetPieceType(){
    return queen;
}
