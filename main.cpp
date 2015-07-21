#include <iostream>
#include "ChessBoard.h"
#include "ChessGame.h"
#include <stdio.h>

int main(int argc, const char* argv[]){
	printf("Hello Board\n");
	ChessGame chessGame;
//	for(int i = 0; i < 3; i++){
	//chessGame.GetConsoleInput();
	chessGame.DisplayBoard();
//	}
    chessGame.GetConsoleInput();
	return 0;
}
