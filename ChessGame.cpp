#include "ChessGame.h"
#include <iostream>

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

    position_t original;
    position_t newposition;
    std::cout << "We Require coordinates" << std::endl;
    std::cout << "X coordinate" << std::endl;
    std::cin >> original.x;
    std::cout << "Y coordinate" << std::endl;
    std::cin >> original.y;

    std::cout << "X coordinate" << std::endl;
    std::cin >> newposition.x;
    std::cout << "Y coordinate" << std::endl;
    std::cin >> newposition.y;

    /*
        Coordinates are backwards,
        first index corresponds to "y" axis relative to how board is set up
        probably not a huge deal, but just need to remember that coordinates are flipped for anything
        so: (x,y) refers to indexs [y][x]
    */

    m_ptrChessBoard->MovePiece(original.x, original.y, newposition.x,newposition.y);

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
