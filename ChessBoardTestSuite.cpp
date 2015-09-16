#include "ChessBoardTestSuite.h"
#include "ChessGame.h"
#include "ChessBoard.h"
#include "UnitTest++.h"
#include "include/EmptyPiece.h"
#include "Queen.h"
class ChessBoardFixture {
    public:
        ChessBoard* ptr_ChessBoard;
        ChessGame* ptr_ChessGame;
        ChessBoardFixture(){
            ptr_ChessGame = new ChessGame();
            ptr_ChessBoard = ptr_ChessGame->GetChessBoard();
        }
        ~ChessBoardFixture(){
            delete ptr_ChessGame;
            delete ptr_ChessBoard;
        }
};
SUITE(ChessBoardSuite)
{

    TEST_FIXTURE(ChessBoardFixture, MovingPiecesTesting)
    {
        ChessPiece*** ptr_Board = ptr_ChessBoard->GetBoard();

        ChessPiece* ptr_WhitePawnMoving = ptr_Board[1][2]; //(2,1)
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_WhitePawnMoving, position_t(1,2)));
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_WhitePawnMoving, position_t(2,2)));
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_WhitePawnMoving, position_t(3,2)));

        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_WhitePawnMoving, position_t(5,5))); //arbitrary
        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_WhitePawnMoving,position_t(8,8))); //not even board
        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_WhitePawnMoving, position_t(2,1))); //Orginal square

        ChessPiece* ptr_BlackPawnMoving = ptr_Board[6][2]; //(2, 6)
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_BlackPawnMoving, position_t(1,5)));
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_BlackPawnMoving, position_t(2,5)));
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_BlackPawnMoving, position_t(3,5)));

        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_BlackPawnMoving, position_t(2,6)));
        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_BlackPawnMoving, position_t(5,4)));
        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_BlackPawnMoving, position_t(10,6)));


        ChessPiece* ptr_WhiteQueen = ptr_Board[0][3];// (3,0)
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_WhiteQueen, position_t(7, 4)));
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_WhiteQueen, position_t(3, 7)));
        CHECK(ptr_ChessBoard->IsMoveAvailable(ptr_WhiteQueen, position_t(6,0)));


        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_WhiteQueen, position_t(6, 2)));
        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_WhiteQueen, position_t(8, 0)));
        CHECK(!ptr_ChessBoard->IsMoveAvailable(ptr_WhiteQueen, position_t(7,5)));

    }
    TEST_FIXTURE(ChessBoardFixture, PiecesColorTesting)
    {
        CHECK(ptr_ChessBoard->AreSameColor('P','K'));
        CHECK(ptr_ChessBoard->AreSameColor('p','q'));

        CHECK(!ptr_ChessBoard->AreSameColor('_','_'));
        CHECK(!ptr_ChessBoard->AreSameColor('k','_'));

        CHECK(!ptr_ChessBoard->AreSameColor('r','K'));
        CHECK(!ptr_ChessBoard->AreSameColor('p','K'));
    }

    TEST_FIXTURE(ChessBoardFixture, ClearPathTesting)
    {

        ChessPiece*** ptr_Board = ptr_ChessBoard->GetBoard();
        ChessPiece* ptr_WhiteKnight = ptr_Board[0][1]; //(1,0)
        ChessPiece* ptr_WhiteQueen = ptr_Board[0][3]; //(3,0)
        ChessPiece* ptr_WhitePawn = ptr_Board[1][2]; //(2,1)
        //CHECK(ptr_ChessBoard->IsPathClear(ChessPiece* piece, int x, int y));


        //Adjacent Case
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhitePawn, 2, 2));
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen, 4, 0));
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen, 2, 0));
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen, 3, 1));
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen, 4, 1));
        //Knight Case
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteKnight, 2,2));
        //Moving horizontally blocked
        CHECK(!ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,3, 5));
        CHECK(!ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,6, 0));

        //Move Vertically
        CHECK(!ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,3, 4));

        //Moving diagonally blocked
        CHECK(!ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,5, 2));
        CHECK(!ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,1, 2));

        //Clear White pieces
        const int BOARDWIDTH = 8;
        for(int i = 0; i < BOARDWIDTH; i++){
            ptr_Board[1][i] = new EmptyPiece(i,1); //Clear pawns from board
            if(i != 3){
                ptr_Board[0][i] = new EmptyPiece(i,0);//Clear back of board
            }
        }
        //Moving horizontal clear
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,3, 5));
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,6, 0));
        //Move Vertically clear
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,3, 4));
        //Checking that black pieces still matter
        CHECK(!ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,3, 7));

        //Moving diagonally clear
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,5, 2));
        CHECK(ptr_ChessBoard->IsPathClear(ptr_WhiteQueen,1, 2));

    }

    TEST_FIXTURE(ChessBoardFixture, CapturingTesting)
    {
        ChessPiece*** ptr_Board = ptr_ChessBoard->GetBoard();

        ChessPiece* ptr_BlackPawn = ptr_Board[6][2]; //(2,6)
        ChessPiece* ptr_WhitePawn = ptr_Board[1][2]; //(2,1)
        ChessPiece* ptr_BlackPiece = ptr_Board[7][5];
        ChessPiece* ptr_WhitePiece = ptr_Board[0][4];

        //CaptureAllowable(ChessPiece* piece,int x,int y)
        //Any other piece
        CHECK(ptr_ChessBoard->CaptureAllowable(ptr_BlackPiece, 3, 6));
        CHECK(ptr_ChessBoard->CaptureAllowable(ptr_WhitePiece, 3, 9));
        //Pawn Case
        //Nothing to take
        CHECK(!ptr_ChessBoard->CaptureAllowable(ptr_BlackPawn,1,5));
        CHECK(!ptr_ChessBoard->CaptureAllowable(ptr_BlackPawn,3,5));
        CHECK(!ptr_ChessBoard->CaptureAllowable(ptr_WhitePawn,1,2));
        CHECK(!ptr_ChessBoard->CaptureAllowable(ptr_WhitePawn,3,2));

        //Just moving forward
        CHECK(ptr_ChessBoard->CaptureAllowable(ptr_WhitePawn,2,2));
        CHECK(ptr_ChessBoard->CaptureAllowable(ptr_BlackPawn,2,5));

        //Pawn blocked case
        ptr_Board[5][1] = new Queen(1,5,"Black");
        ptr_Board[5][3] = new Queen(3,5,"Black");
        ptr_Board[2][1] = new Queen(1,2,"Black");
        ptr_Board[2][3] = new Queen(3,2,"Black");
        ptr_Board[2][2] = new Queen(1,5,"Black");
        ptr_Board[5][2] = new Queen(1,5,"Black");


        //Allowed to take
        CHECK(ptr_ChessBoard->CaptureAllowable(ptr_BlackPawn,1,5));
        CHECK(ptr_ChessBoard->CaptureAllowable(ptr_BlackPawn,3,5));
        CHECK(ptr_ChessBoard->CaptureAllowable(ptr_WhitePawn,1,2));
        CHECK(ptr_ChessBoard->CaptureAllowable(ptr_WhitePawn,3,2));

        //blocked moving forward
        CHECK(!ptr_ChessBoard->CaptureAllowable(ptr_WhitePawn,2,2));
        CHECK(!ptr_ChessBoard->CaptureAllowable(ptr_BlackPawn,2,5));
    }


}
