#ifndef CAPTUREEXCEPTION_H
#define CAPTUREEXCEPTION_H

#include "include/ChessException.h"
#include<string>

class CaptureException : public ChessException
{
    public:
        CaptureException();
};

#endif // CAPTUREEXCEPTION_H
