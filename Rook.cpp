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

std::vector<position_t> Rook::GetValidMoves(){
    std::vector<position_t> validMoves;

    int const maxDimension = 8;


    for (int i = 0; i < maxDimension ; i++){
            if (i == m_position.y){
                continue;
            }
            validMoves.push_back(position_t(m_position.x, i));
    }

    for (int i = 0; i < maxDimension ; i++){
        if (i == m_position.x){
            continue;
        }
        validMoves.push_back(position_t(i, m_position.y));
    }

    return validMoves;
}
