#include "ChessPiece.h"

ChessPiece::ChessPiece()
{
   m_isAvailable = true;
}

ChessPiece::ChessPiece(int x, int y, char s){
    ChessPiece::SetPosition(x, y);
    m_symbol = s;
}
char ChessPiece::GetSymbol(){
    return m_symbol;
}
position_t ChessPiece::GetPosition(){
    return m_position;
}
void ChessPiece::SetPosition(int x, int y){
    m_position.x = x;
    m_position.y = y;
}

bool ChessPiece::GetIsAvailable() {
    return m_isAvailable;
}

