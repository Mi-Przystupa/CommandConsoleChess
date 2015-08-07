#include "RookTestSuite.h"
#include "../Rook.h"
#include "UnitTest++.h"
#include <vector>
#include "../ChessPiece.h"


class RookFixture
{
public:
    Rook* ptr_WhiteRook;
    Rook* ptr_BlackRook;

    RookFixture(){
        ptr_WhiteRook = new Rook(0, 0, "White");
        ptr_BlackRook= new Rook(0,7, "Black");
    }
    ~RookFixture(){
         delete ptr_WhiteRook;
         delete ptr_BlackRook;
    }
};


SUITE(RookTests){

    TEST_FIXTURE(RookFixture, TestPieceSymbol){
        CHECK_EQUAL(ptr_BlackRook->GetSymbol(), 'R');
        CHECK_EQUAL(ptr_WhiteRook->GetSymbol(), 'r');
    }

    TEST_FIXTURE(RookFixture, TestValidMoves){
        //From Initial Coordinate
        //Check Following are InValidVector
        position_t initPsn(ptr_BlackRook->GetPosition());
        CHECK_EQUAL(initPsn.x, 0);
        CHECK_EQUAL(initPsn.y, 7);
        std::vector<position_t> initPsnValid(ptr_BlackRook->GetValidMoves());
        std::vector<position_t> initPsnCheck;
        //0,0
        initPsnCheck.push_back(position_t(initPsn.x, initPsn.y - 7));
        //7,7
        initPsnCheck.push_back(position_t(initPsn.x + 7, initPsn.y));
        //0,4
        initPsnCheck.push_back(position_t(initPsn.x, initPsn.y - 3));
        //4,7
        initPsnCheck.push_back(position_t(initPsn.x + 4, initPsn.y));

        bool containsAll = false;
        for(int i = 0; i < initPsnCheck.size(); i++){
            containsAll = false;
            for (int j = 0; j < initPsnValid.size(); j++)
            {
                if(initPsnCheck[i] == initPsnValid[j]){
                    containsAll = true;
                }
            }
            if(!containsAll){
                break;
            }
        }
        CHECK(containsAll);

        //Check Following Are not in valid vector
        std::vector<position_t> invalidPsn;
        //Initial coordinates shouldn't be in it.
        invalidPsn.push_back(position_t(initPsn.x, initPsn.y));
        //No diagonal (1,6)
        invalidPsn.push_back(position_t(initPsn.x + 1, initPsn.y - 1 ));
        //Random one
        invalidPsn.push_back(position_t(3,3));

        bool doesNotContain = true; // Assume it does not contain
        for (int i = 0; i < initPsnValid.size(); i++){
            doesNotContain = true;
            for (int j = 0; j < invalidPsn.size(); j++){
                if(initPsnValid[i] == invalidPsn[j]){
                    doesNotContain = false;
                }
            }
            if(!doesNotContain){
                break;
            }
        }

        CHECK(doesNotContain);


        //Move Piece to middle of Board
        ptr_BlackRook->SetPosition(4,5);
        position_t movedPsn(ptr_BlackRook->GetPosition());
        CHECK_EQUAL(movedPsn.x, 4);
        CHECK_EQUAL(movedPsn.y, 5);
        std::vector<position_t> newPsnValid(ptr_BlackRook->GetValidMoves());
        std::vector<position_t> newPsnCheck;
        //4,7
        newPsnCheck.push_back(position_t(movedPsn.x, movedPsn.y + 2));
        //0,5
        newPsnCheck.push_back(position_t(movedPsn.x - 4, movedPsn.y));
        //4,3
        newPsnCheck.push_back(position_t(movedPsn.x, movedPsn.y - 2 ));
        //5,5
        newPsnCheck.push_back(position_t(movedPsn.x + 1, movedPsn.y));

        containsAll = false;
        for(int i = 0; i < newPsnCheck.size(); i++){
            containsAll = false;
            for (int j = 0; j < newPsnValid.size(); j++)
            {
                if(newPsnCheck[i] == newPsnValid[j]){
                    containsAll = true;
                }
            }
            if(!containsAll){
                break;
            }
        }
        CHECK(containsAll);


    }

}

