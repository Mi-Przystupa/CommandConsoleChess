
#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>

struct position_t{
	int x;
	int y;
};

enum PieceType {
    pawn,
    rook,
    knight,
    bishop,
    king,
    queen,
    emptycell
};

class ChessPiece
{
protected:
    ChessPiece();
    ChessPiece(int x, int y, char s);
	position_t m_position;
	char m_symbol;
	bool m_isAvailable;

public:
	char GetSymbol();
    position_t GetPosition();
    void SetPosition(int x, int y);
    bool GetIsAvailable();

    virtual PieceType GetPieceType() = 0;

};
#endif // CHESSPIECE_H
