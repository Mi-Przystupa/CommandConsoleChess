#ifndef MOVEEXCEPTION_H
#define MOVEEXCEPTION_H

#include "include/ChessException.h"
#include<string>


class MoveException : public ChessException
{
    public:
        MoveException();
 //       virtual ~MoveException();
};

#endif // MOVEEXCEPTION_H
