
#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>
#include <vector>

struct position_t{
	int x;
	int y;

	position_t(int xcord, int ycord){
        x = xcord;
        y = ycord;
	}
	position_t(){
        x = 0;
        y = 0;
	}

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
    void SetIsAvailable(bool available);

    virtual PieceType GetPieceType() = 0;
    virtual std::vector<position_t> GetValidMoves() = 0;

};
#endif // CHESSPIECE_H
