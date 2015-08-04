#include <iostream>
#include "ChessBoard.h"
#include "ChessGame.h"
#include <stdio.h>
#include "UnitTest++.h"

int main(int argc, const char* argv[]){

    UnitTest::RunAllTests();

	printf("Hello Board\n");
	ChessGame chessGame;
    chessGame.Execute();
	return 0;//UnitTest::RunAllTests();;
}
