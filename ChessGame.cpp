#include "ChessGame.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>



ChessGame::ChessGame()
{
    //ctor
    m_currentPlayerIsBlack = false;
    m_ptrBlackPlayer = new BlackChessPlayer();
    m_ptrWhitePlayer = new WhiteChessPlayer();
    m_ptrCurrentPlayer = m_ptrWhitePlayer;

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
}

ChessGame::~ChessGame()
{
    //dtor
}

void ChessGame::GetConsoleInput(){

    position_t newposition;
    std::string coordinate;
    char pieceName;

    if(m_currentPlayerIsBlack) {
        std::cout << "It is Black's Turn" << std::endl;
    } else {
        std::cout << "It is White's Turn" << std::endl;
    }
    std::cout << "Select a piece" << std::endl;
    std::cin >> pieceName;
    DisplayRequestedPieces(pieceName);
    DisplayBoard();
    std::cout << "Which piece Do you want to move?" << std::endl;
    int index;
    std :: cin >> index;
    std::cout << "Where do you want to move the piece " << GetPieceCoordinatesString(index, pieceName) << "to?" << std::endl;
    std::cin >> coordinate;

    std::cout << coordinate << std::endl;

/*    std::cout << "We Require coordinates" << std::endl;
    std::cin >> coordinate;

    try {
        std::string xcord = coordinate.substr(1,2);
        std::string ycord = coordinate.substr(0, 1);

        newposition.x = atoi(xcord.c_str());
        newposition.y = atoi(ycord.c_str());

    } catch(std::exception e) {
        std::cout << "You messed up " << std::endl;
    }
*/

    /*
        Coordinates are backwards,
        first index corresponds to "y" axis relative to how board is set up
        probably not a huge deal, but just need to remember that coordinates are flipped for anything
        so: (x,y) refers to indexs [y][x]
    */

//    m_ptrChessBoard->MovePiece(0, 0, newposition.x,newposition.y);

}

void ChessGame::SwitchPlayer(){
    if (m_currentPlayerIsBlack){
        m_ptrCurrentPlayer = m_ptrWhitePlayer;
        m_currentPlayerIsBlack = false;
    } else {
        m_ptrCurrentPlayer = m_ptrBlackPlayer;
        m_currentPlayerIsBlack = true;
    }
}

std::string ChessGame::GetPieceCoordinatesString(int index,char pieceName){
    //@TODO: If the index is not valid, this will cause program to crash
    ChessPiece* selectedPiece = m_ptrCurrentPlayer->GetAvailableRequestedPieces(pieceName)[index];
    std::string symbol(1, selectedPiece->GetSymbol());

    std::ostringstream ss;
    ss << selectedPiece->GetPosition().x;
    std::string x(ss.str());
    std::ostringstream ss2;
    ss2 << selectedPiece->GetPosition().y;
    std::string y(ss2.str());

    return symbol + "(" + x + "," +  y + ")";
}
void ChessGame::DisplayRequestedPieces(char piece){
    std::vector<ChessPiece*> availablePieces = m_ptrCurrentPlayer->GetAvailableRequestedPieces(piece);

    if(availablePieces.size() == 0){
        std::cout << "No such pieces available" << std::endl;
    }
    int index = 0;
    for (std::vector<ChessPiece*>::iterator it = availablePieces.begin() ; it != availablePieces.end(); ++it){
        std::cout << (*it)->GetSymbol();
        DisplayCoordinates((*it)->GetPosition());
        std::cout << "[" << index++ << "]" << std::endl;

    }
}


void ChessGame::DisplayCoordinates(position_t p){
    std::cout << "(" << p.x << "," << p.y << ")";
}
void ChessGame::DisplayBoard(){
    m_ptrChessBoard->displayBoard();
}
