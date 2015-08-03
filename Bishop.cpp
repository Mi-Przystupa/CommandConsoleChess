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

std::vector<position_t> Bishop::GetValidMoves() {
    std::vector<position_t> validMoves;


    //board is square
    const int maxDimension = 8;
    //Up is defined as going to 0, Down as going to maxDimension

    int modifier = 1;
    //TODO: These are 4 different functions that could be simplified by passing funciton pointers. Not right now though
    //Go down and right on board
    while ((m_position.x + modifier) < maxDimension && (m_position.y + modifier) < maxDimension){
        validMoves.push_back(position_t(m_position.x + modifier, m_position.y + modifier));
        modifier++;
    }

    modifier = 1;
    //Go down and left on board
    while ((m_position.x - modifier) >= 0 && (m_position.y + modifier) < maxDimension){
        validMoves.push_back(position_t(m_position.x - modifier, m_position.y + modifier));
        modifier++;
    }

    modifier = 1;
    //Go up and right on board
    while ((m_position.x + modifier) < maxDimension && (m_position.y - modifier) >=  0 ){
        validMoves.push_back(position_t(m_position.x + modifier, m_position.y - modifier));
        modifier++;
    }
    modifier = 1;
    //Go up and left on board
    while ((m_position.x - modifier) >= 0 && (m_position.y - modifier) >= 0 ){
        validMoves.push_back(position_t(m_position.x - modifier, m_position.y - modifier));
        modifier++;
    }

    return validMoves;
}
