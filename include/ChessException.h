#ifndef CHESSEXCEPTION_H
#define CHESSEXCEPTION_H

#include<stdexcept>
#include<string>


class ChessException : public std::runtime_error
{
    public:
        ChessException(std::string message);
        virtual ~ChessException();
    protected:
    private:
};

#endif // CHESSEXCEPTION_H
