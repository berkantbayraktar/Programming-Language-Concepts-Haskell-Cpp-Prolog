#include"Game.h"
#include <algorithm>
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
    /*
    * Game ended at turn 13. All barbarians dead. Knight victory.
   * Game ended at turn 121. All knights dead. Barbarian victory.
   * Game ended at turn 52. Chest captured. Barbarian victory.
   * Game ended at turn 215. Maximum turn number reached. Knight victory.
   * */
    int numberOfBarbarians = 0, numberOfKnights = 0 ;
    bool isCaptured = false;

    for(std::vector<Player*>::iterator it  = players.begin() ; it != players.end() ; it++){
        if((*it)->getCoord() == board.getChestCoordinates())
            isCaptured = true;

        if((*it)->getTeam() == BARBARIANS)
            numberOfBarbarians++;
        else if((*it)->getTeam() == KNIGHTS)
            numberOfKnights++;
    }

    if(numberOfBarbarians == 0){
        std::cout  << "Game ended at turn " << this->turnNumber << ". All barbarians dead. Knight victory." << std::endl;
        return true;
    }
    else if (numberOfKnights == 0){
        std::cout  << "Game ended at turn " << this->turnNumber << ". All knights dead. Barbarian victory." << std::endl;
        return true;
    }

    else if (isCaptured){
        std::cout  << "Game ended at turn " << this->turnNumber << ". Chest captured. Barbarian victory." << std::endl;
        return true;
    }
    else if (turnNumber == maxTurnNumber){
        std::cout  << "Game ended at turn " << this->turnNumber << ". Maximum turn number reached. Knight victory." << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    

}

void Game::playTurn(){
    std::sort(players.begin(), players.end(), [](Player  *pl,Player *pr) {
    return (pl->getBoardID() > pr->getBoardID()) ;
});
    // "Turn 13 has started."
    std::cout << "Turn " << turnNumber << " has started." <<std::endl;
    
    for(std::vector<Player*>::iterator it  = players.begin() ; it != players.end() ; it++){
            this->playTurnForPlayer(*it);
        }

}

Goal Game::playTurnForPlayer(Player* player){
    //IMPLEMENT
}