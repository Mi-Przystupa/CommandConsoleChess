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
