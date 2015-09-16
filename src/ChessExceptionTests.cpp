#include "ChessExceptionTests.h"
#include "ChessException.h"
#include "../MoveException.h"
#include "../PieceException.h"
#include "UnitTest++.h"

SUITE(Exceptions){

    TEST(ChessExceptionsThrown)
    {
        CHECK_THROW(throw ChessException("Hello"), ChessException);
        CHECK_THROW(throw MoveException(), MoveException);
        CHECK_THROW(throw PieceException(), PieceException);
    }
    TEST(MoveExceptionTest)
    {
        try{
           throw MoveException();
        } catch(MoveException e){
            CHECK_EQUAL(e.what(), "Invalid move");
        }
    }
    TEST(PieceException)
    {
        try{
            throw PieceException();
        } catch (PieceException e){
            CHECK_EQUAL(e.what(), "Cannot capture own piece");
        }
    }

}
