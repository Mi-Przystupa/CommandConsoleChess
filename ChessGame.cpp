#include "ChessGame.h"
#include <iostream>
#include <string>
#include <stdlib.h>

ChessGame::ChessGame()
{
    //ctor
    m_ptrBlackPlayer = new BlackChessPlayer();
    m_ptrWhitePlayer = new WhiteChessPlayer();


    std::vector<ChessPiece*> allPieces;// = new std::vector<ChessPiece*>();

    std::vector<ChessPiece*> playersPieces = m_ptrBlackPlayer->getAllPieces();
    for (unsigned int i = 0; i < playersPieces.size(); i++){
        allPieces.push_back(playersPieces[i]);
    }
    playersPieces = m_ptrWhitePlayer->getAllPieces();
    for (unsigned int i = 0; i < playersPieces.size(); i++){
        allPieces.push_back(playersPieces[i]);
    }
    m_ptrChessBoard = new ChessBoard(allPieces);
    m_ptrCurrentPlayer = 0;
}

ChessGame::~ChessGame()
{
    //dtor
}

void ChessGame::GetConsoleInput(){

    position_t newposition;
    std::string coordinate;
    std::string pieceName;

    std::cout << "Select a piece" << std::endl;
    std::cin >> pieceName;

    std::cout << "We Require coordinates" << std::endl;
    std::cin >> coordinate;

    try {
        std::string xcord = coordinate.substr(1,2);
        std::string ycord = coordinate.substr(0, 1);

        newposition.x = atoi(xcord.c_str());
        newposition.y = atoi(ycord.c_str());

    } catch(std::exception e) {
        std::cout << "You messed up " << std::endl;
    }

    /*
        Coordinates are backwards,
        first index corresponds to "y" axis relative to how board is set up
        probably not a huge deal, but just need to remember that coordinates are flipped for anything
        so: (x,y) refers to indexs [y][x]
    */

    m_ptrChessBoard->MovePiece(0, 0, newposition.x,newposition.y);

}

void ChessGame::SwitchPlayer(){
    m_ptrCurrentPlayer = m_ptrBlackPlayer;
}
void ChessGame::DisplaySelectPieceMoves(){
//    ChessPiece* currentPiece = m_ptrCurrentPlayer->SelectPiece(m_coordinates.x, m_coordinates.y);
}
void ChessGame::DisplayBoard(){
    m_ptrChessBoard->displayBoard();
}
