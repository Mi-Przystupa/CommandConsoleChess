#include "..\include\EmptyPiece.h"

EmptyPiece::EmptyPiece(int x, int y )
{
    //ctor
     SetPosition(x,y);
     m_symbol = '_';
}

EmptyPiece::~EmptyPiece()
{
    //dtor
}


PieceType EmptyPiece::GetPieceType(){
    return emptycell;
}
