#include "Bishop.h"

Bishop::Bishop(int x, int y, std::string side)
{
    //ctor
    SetPosition(x,y);
    m_symbol = side == "Black" ? 'B' : 'b';
}

Bishop::~Bishop()
{
    //dtor
}

PieceType Bishop::GetPieceType(){
    return bishop;
}
