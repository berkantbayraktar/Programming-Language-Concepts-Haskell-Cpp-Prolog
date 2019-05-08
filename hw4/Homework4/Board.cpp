#include"Board.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Board::Board(uint _size, std::vector<Player*>* _players, Coordinate chest): size(_size), players(_players), chest(chest){
}

Board::~Board(){
    std::cout<< "~Board()" << std::endl;
}

bool Board::isCoordinateInBoard(const Coordinate& c){
    return ((c.x >= 0 && c.x < size) && (c.y >= 0 && c.y < size));
}

bool Board::isPlayerOnCoordinate(const Coordinate& c){
    for(std::vector<Player*>::iterator it  = players->begin() ; it != players->end() ; it++){
        if((*it)->getCoord() == c)
            return true; 
    }
    return false;
}

Player* Board::operator [](const Coordinate& c){
    for(std::vector<Player*>::iterator it  = players->begin() ; it != players->end() ; it++){
        if((*it)->getCoord() == c)
            return *it; 
    }
    return NULL;
}

Coordinate Board::getChestCoordinates(){
    return chest;
}

void Board::printBoardwithID(){
    for(int j = 0 ; j < size ; j++){
        for(int i = 0 ; i < size ; i++){
            Coordinate temp = Coordinate(i,j);
            if(this->getChestCoordinates() == temp){
                std::cout << "Ch ";
            }
            else if((*this)[temp] == NULL){
                std::cout << "__ ";
            }
            else{
                std::cout << (*this)[temp]->getBoardID() << " " ;
            }
        }
        std::cout << std::endl;
    }
}

void Board::printBoardwithClass(){
    
    for(int j = 0 ; j < size ; j++){
        for(int i = 0 ; i < size ; i++){
            Coordinate temp = Coordinate(i,j);
            if(this->getChestCoordinates() == temp){
                std::cout << "Ch ";
            }
            else if((*this)[temp] == NULL){
                std::cout << "__ ";
            }
            else{
                std::cout << (*this)[temp]->getClassAbbreviation() << " ";
            }
        }
        std::cout << std::endl;
    }
}