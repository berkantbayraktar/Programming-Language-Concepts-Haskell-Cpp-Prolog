#include"Game.h"
#include "Archer.h"
#include "Fighter.h"
#include "Priest.h"
#include "Tank.h"
#include "Scout.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Game::Game(uint maxTurnNumber, uint boardSize, Coordinate chest): maxTurnNumber(maxTurnNumber), turnNumber(0), board(Board(boardSize,&players ,chest)){
    players = std::vector<Player*>();
    // Board b = Board(boardSize,&players ,chest); !!!!!!!!!!!!!!!
    // this->board = b;
}

Game::~Game(){
    std::cout<< "~Game()" << std::endl;
}

void Game::addPlayer(int id, int x, int y, Team team, std::string c ){
    Player *p;
    
    if(c== "ARCHER"){
        p = new Archer(id,x,y,team);
    }
    else if( c== "FIGHTER"){
        p = new Fighter(id,x,y,team);
    }
    else if (c== "PRIEST"){
        p = new Priest(id,x,y,team);
    }
    else if (c == "SCOUT"){
        p = new Scout(id,x,y,team);
    }
    else if (c == "TANK"){
        p = new Tank(id,x,y,team);
    }
    
    players.push_back(p);
}

bool Game::isGameEnded(){
    //IMPLEMENT
}

void Game::playTurn(){
    //IMPLEMENT
}

Goal Game::playTurnForPlayer(Player* player){
    //IMPLEMENT
}