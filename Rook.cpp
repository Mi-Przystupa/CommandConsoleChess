#include "Rook.h"

Rook::Rook(int x, int y,std::string side)
{
    SetPosition(x, y);
    m_symbol = side == "Black" ? 'R' : 'r';
}

Rook::~Rook()
{
    //dtor
}

PieceType Rook::GetPieceType(){
    return rook;
}
