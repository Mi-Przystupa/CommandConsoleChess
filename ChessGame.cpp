#include "ChessGame.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "PieceException.h"
#include "MoveException.h"


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

void ChessGame::WipeConsole(){
    //TODO: This can be way more clever;
    for (int i = 0; i < 2; i++){
        std::cout << std::endl;
    }

}

void ChessGame::Execute(){
    bool isGameOver = false;

    while (!isGameOver){
        WipeConsole();
        std::cout << std::endl;
        DisplayCurrentPlayer();
        std::cout << std::endl;
        DisplayBoard();
        if(GetConsoleInput()){
            SwitchPlayer();
        }
    }
}
//TODO: almost all my error handling is done with conditional booleans, this should be changed to exceptions perhaps??
bool ChessGame::GetConsoleInput(){

    position_t newposition;
    std::string coordinate;
    char pieceName;

    std::cout << "Select a piece or pass with g" << std::endl;
    std::cin >> pieceName;
    if(pieceName == 'g')
        return true;
    bool validInput = DisplayRequestedPieces(pieceName);

    if (validInput) {
        std::cout << "Which one do you want to move?" << std::endl;
        unsigned int index;
        std :: cin >> index;
        //This will cause a boundary error

        ChessPiece* selectedPiece;
        std::vector<ChessPiece*> availableRequestedPieces(m_ptrCurrentPlayer->GetAvailableRequestedPieces(pieceName));
        if(availableRequestedPieces.size() > index){
            selectedPiece = availableRequestedPieces[index];
            validInput = true;
            std::cout << "Where do you want to move the piece " << GetPieceCoordinatesString(index, pieceName) << " to? (e.g. 3,4) " << std::endl;
            std::cin >> coordinate;

            try {
                //the format must be "x,y" so is of length 3
                std::string xcord = coordinate.substr(0,2);
                std::string ycord = coordinate.substr(2, 4);
                newposition.x = atoi(xcord.c_str());
                newposition.y = atoi(ycord.c_str());
            } catch(std::exception e) {
                std::cout << "Invalid format, please use following: \"x,y\""<< std::endl;
            }
            /*
                Coordinates are backwards,
                first index corresponds to "y" axis relative to how board is set up
                probably not a huge deal, but just need to remember that coordinates are flipped for anything
                so: (x,y) refers to indexs [y][x]
            */
            validInput = m_ptrChessBoard->MovePiece(selectedPiece->GetPosition().x, selectedPiece->GetPosition().y, newposition.x,newposition.y);
            } else {
            std::cout << "Please pick from available pieces" << std::endl;
            validInput = false;
        }

    }

    return validInput;
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

void ChessGame::DisplayCurrentPlayer(){
    if (m_currentPlayerIsBlack){
        std::cout << "Blacks's Turn" << std::endl;
    } else {
        std::cout << "White's Turn" << std::endl;
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
bool ChessGame::DisplayRequestedPieces(char piece){
    bool pieceAvailable = true;
    std::vector<ChessPiece*> availablePieces = m_ptrCurrentPlayer->GetAvailableRequestedPieces(piece);
    if(availablePieces.size() == 0){
        std::cout << "No such pieces available" << std::endl;
        pieceAvailable = false;
    }
    int index = 0;

    //TODO; The if statement isn't correct, if last element is even will have , at the end-
    for (std::vector<ChessPiece*>::iterator it = availablePieces.begin() ; it != availablePieces.end(); ++it){
        std::cout << (*it)->GetSymbol();
        DisplayCoordinates((*it)->GetPosition());
        std::cout << "[" << index++ << "]";

        if(index % 2){
            std::cout << ", ";
        } else{
            std::cout << std::endl;
        }

    }

    std::cout<<std::endl;

    return pieceAvailable;
}


void ChessGame::DisplayCoordinates(position_t p){
    std::cout << "(" << p.x << "," << p.y << ")";
}
void ChessGame::DisplayBoard(){
    m_ptrChessBoard->DisplayBoard();
}


ChessBoard* ChessGame::GetChessBoard(){
    return m_ptrChessBoard;
}
