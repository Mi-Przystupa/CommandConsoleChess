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

bool King::InBoundaries(int p){
    return p >= 0 && p < 8;
}

std::vector<position_t> King::GetValidMoves(){
    std::vector<position_t> validMoves;


    if ( InBoundaries(m_position.x  + 1)){
        validMoves.push_back(position_t(m_position.x + 1,m_position.y));

        if (  InBoundaries(m_position.y + 1)){
            validMoves.push_back(position_t(m_position.x + 1,m_position.y + 1 ));
        }
        if ( InBoundaries(m_position.y - 1)){
            validMoves.push_back(position_t(m_position.x + 1,m_position.y - 1 ));
        }
    }

    if ( InBoundaries(m_position.x - 1) ){
        validMoves.push_back(position_t(m_position.x - 1,m_position.y ));

        if ( InBoundaries(m_position.y  - 1)){
            validMoves.push_back(position_t(m_position.x - 1,m_position.y - 1 ));
        }
        if ( InBoundaries(m_position.y + 1)){
            validMoves.push_back(position_t(m_position.x - 1,m_position.y + 1 ));
        }

    }
    if ( InBoundaries(m_position.y + 1)){
        validMoves.push_back(position_t(m_position.x,m_position.y + 1 ));
    }
    if ( InBoundaries(m_position.y - 1)){
        validMoves.push_back(position_t(m_position.x,m_position.y - 1 ));
    }

    return validMoves;
}
