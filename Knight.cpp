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

std::vector<position_t> Knight::GetValidMoves(){
    std::vector<position_t> validMoves;

    //TODO: this constant should be in one file accessed by all
    int maxDimension = 8;

    //Going left
    if(m_position.x - 2 >= 0){
        if(m_position.y + 1 < maxDimension){
            validMoves.push_back(position_t(m_position.x - 2, m_position.y + 1));
        }
        if(m_position.y - 1 >= 0){
            validMoves.push_back(position_t(m_position.x - 2, m_position.y - 1));
        }
    }
    //Going Right
    if(m_position.x + 2 < maxDimension){
        if(m_position.y + 1 < maxDimension){
            validMoves.push_back(position_t(m_position.x + 2, m_position.y + 1));
        }
        if(m_position.y - 1 >= 0){
            validMoves.push_back(position_t(m_position.x + 2, m_position.y - 1));
        }
    }
    //Going up
    if(m_position.y - 2 >= 0){
        if(m_position.x + 1 < maxDimension){
            validMoves.push_back(position_t(m_position.x + 1, m_position.y - 2));
        }
        if(m_position.x - 1 >= 0){
            validMoves.push_back(position_t(m_position.x - 1, m_position.y - 2));
        }
    }
    //Going down
    if(m_position.y + 2 >= 0){
        if(m_position.x + 1 < maxDimension){
            validMoves.push_back(position_t(m_position.x + 1, m_position.y + 2));
        }
        if(m_position.x - 1 >= 0){
            validMoves.push_back(position_t(m_position.x - 1, m_position.y + 2));
        }
    }
    return validMoves;
}
