#include "ChessException.h"

ChessException::ChessException(std::string message): std::runtime_error(message)
{
    //ctor
}

ChessException::~ChessException()
{
    //dtor
}
