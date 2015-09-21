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


std::vector<position_t> Queen::GetValidMoves(){
    std::vector<position_t> validMoves(DiagonalMoves());

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


std::vector<position_t> Queen::DiagonalMoves(){
      //board is square

    std::vector<position_t> validMoves;
    const int maxDimension = 8;

    int modifier = 1;
    //TODO: These are 4 different functions that could be simplified by passing function pointers. Not right now though
    //Go up and right on board
    while ((m_position.x + modifier) < maxDimension && (m_position.y + modifier) <maxDimension){
        validMoves.push_back(position_t(m_position.x + modifier, m_position.y + modifier));
        modifier++;
    }
    modifier = 1;
    //Go up and left on board
    while ((m_position.x - modifier) >= 0 && (m_position.y + modifier) <maxDimension){
        validMoves.push_back(position_t(m_position.x - modifier, m_position.y + modifier));
        modifier++;
    }
    modifier = 1;
    //Go down and right on board
    while ((m_position.x + modifier) < maxDimension && (m_position.y - modifier) > maxDimension){
        validMoves.push_back(position_t(m_position.x + modifier, m_position.y - modifier));
        modifier++;
    }
    modifier = 1;
    //Go down and left on board
    while ((m_position.x - modifier) > maxDimension && (m_position.y - modifier) > maxDimension){
        validMoves.push_back(position_t(m_position.x - modifier, m_position.y - modifier));
        modifier++;
    }

    return validMoves;
}
