#include "PawnTestSuite.h"
#include "../Pawn.h"
#include "UnitTest++.h"
#include <vector>
#include "../ChessPiece.h"


class PawnFixture
{
public:
    Pawn* ptr_WhitePawn;
    Pawn* ptr_BlackPawn;

    PawnFixture(){
        ptr_WhitePawn = new Pawn(1, 1, "White");
        ptr_BlackPawn = new Pawn(1,6, "Black");
    }
    ~PawnFixture(){
         delete ptr_WhitePawn;
         delete ptr_BlackPawn;
    }
};


SUITE(PawnSuite)
{
    TEST_FIXTURE(PawnFixture, IsWhitePawn)
    {
        CHECK_EQUAL(ptr_WhitePawn->GetSymbol(), 'p');
    }
    TEST_FIXTURE(PawnFixture, IsBlackPawn)
    {
        CHECK_EQUAL(ptr_BlackPawn->GetSymbol(), 'P');
    }
    TEST_FIXTURE(PawnFixture, GetValidBlackMoves){
        position_t initPosn(ptr_BlackPawn->GetPosition());
        //Initial Available Moves
        std::vector<position_t> shouldBeAvailable;
        shouldBeAvailable.push_back(position_t(initPosn.x, initPosn.y - 1));
        shouldBeAvailable.push_back(position_t(initPosn.x, initPosn.y - 2));
        shouldBeAvailable.push_back(position_t(initPosn.x - 1, initPosn.y - 1));
        shouldBeAvailable.push_back(position_t(initPosn.x + 1, initPosn.y - 1));

        std::vector<position_t> validBlackMoves(ptr_BlackPawn->GetValidMoves());
        CHECK_EQUAL(validBlackMoves.size(), shouldBeAvailable.size());

        bool vectorsAreSame = true; //just to initialize it
        for (unsigned int i = 0; i < shouldBeAvailable.size(); i++){
            vectorsAreSame = false;
            for(unsigned int j = 0; j < validBlackMoves.size(); j++){
                if(shouldBeAvailable[i] == validBlackMoves[j] && shouldBeAvailable[i] == validBlackMoves[j]){
                    vectorsAreSame = true;
                }
            }
            if(!vectorsAreSame){
                break;
            }
        }
        CHECK(vectorsAreSame);

        ptr_BlackPawn->SetPosition(initPosn.x, initPosn.y - 1);
        position_t newPosn(ptr_BlackPawn->GetPosition());

        CHECK(initPosn.x == newPosn.x && initPosn.y > newPosn.y );
        //Move Available Once Moved
        validBlackMoves.clear();

        std::vector<position_t>::iterator it = ptr_BlackPawn->GetValidMoves().begin();
        validBlackMoves.assign(it, ptr_BlackPawn->GetValidMoves().end());
        shouldBeAvailable.clear();
        shouldBeAvailable.push_back(position_t(newPosn.x, newPosn.y - 1));
        shouldBeAvailable.push_back(position_t(newPosn.x - 1, newPosn.y - 1));
        shouldBeAvailable.push_back(position_t(newPosn.x + 1, newPosn.y - 1));

        CHECK_EQUAL(validBlackMoves.size(), shouldBeAvailable.size());

        vectorsAreSame = true; //just to initialize it
        for (unsigned int i = 0; i < shouldBeAvailable.size(); i++){
            vectorsAreSame = false;
            for(unsigned int j = 0; j < validBlackMoves.size(); j++){
                if(shouldBeAvailable[i] == validBlackMoves[j] && shouldBeAvailable[i] == validBlackMoves[j]){
                    vectorsAreSame = true;
                }
            }
            if(!vectorsAreSame){
                break;
            }
        }
        CHECK(vectorsAreSame);


    }
    TEST_FIXTURE(PawnFixture, GetValidWhiteMoves){
        position_t initPosn(ptr_WhitePawn->GetPosition());
        //Initial Available Moves
        std::vector<position_t> shouldBeAvailable;
        shouldBeAvailable.push_back(position_t(initPosn.x, initPosn.y + 1));
        shouldBeAvailable.push_back(position_t(initPosn.x, initPosn.y + 2));
        shouldBeAvailable.push_back(position_t(initPosn.x - 1, initPosn.y + 1));
        shouldBeAvailable.push_back(position_t(initPosn.x + 1, initPosn.y + 1));

        std::vector<position_t> validWhiteMoves(ptr_WhitePawn->GetValidMoves());
        CHECK_EQUAL(validWhiteMoves.size(), shouldBeAvailable.size());

        bool vectorsAreSame = true; //just to initialize it
        for (unsigned int i = 0; i < shouldBeAvailable.size(); i++){
            vectorsAreSame = false;
            for(unsigned int j = 0; j < validWhiteMoves.size(); j++){
                if(shouldBeAvailable[i] == validWhiteMoves[j] && shouldBeAvailable[i] == validWhiteMoves[j]){
                    vectorsAreSame = true;
                }
            }
            if(!vectorsAreSame){
                break;
            }
        }
        CHECK(vectorsAreSame);

        ptr_WhitePawn->SetPosition(initPosn.x, initPosn.y + 1);
        position_t newPosn(ptr_WhitePawn->GetPosition());

        CHECK(initPosn.x == newPosn.x && initPosn.y < newPosn.y );
        //Move Available Once Moved
        validWhiteMoves.clear();

        std::vector<position_t>::iterator it = ptr_WhitePawn->GetValidMoves().begin();
        validWhiteMoves.assign(it, ptr_WhitePawn->GetValidMoves().end());
        shouldBeAvailable.clear();
        shouldBeAvailable.push_back(position_t(newPosn.x, newPosn.y + 1));
        shouldBeAvailable.push_back(position_t(newPosn.x - 1, newPosn.y + 1));
        shouldBeAvailable.push_back(position_t(newPosn.x + 1, newPosn.y + 1));

        CHECK_EQUAL(validWhiteMoves.size(), shouldBeAvailable.size());

        vectorsAreSame = true; //just to initialize it
        for (unsigned int i = 0; i < shouldBeAvailable.size(); i++){
            vectorsAreSame = false;
            for(unsigned int j = 0; j < validWhiteMoves.size(); j++){
                if(shouldBeAvailable[i] == validWhiteMoves[j] && shouldBeAvailable[i] == validWhiteMoves[j]){
                    vectorsAreSame = true;
                }
            }
            if(!vectorsAreSame){
                break;
            }
        }
        CHECK(vectorsAreSame);
    }

}
