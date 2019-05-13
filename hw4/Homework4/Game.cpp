#include"Game.h"
#include <algorithm>
#include <limits.h>
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
    for(int i = 0 ; i < players.size() ; i++){
	    delete players.at(i);
	    players.at(i) = NULL;
    }
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
        if((*it)->getCoord() == board.getChestCoordinates() && ((*it)->getTeam() == BARBARIANS) )
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
    if(turnNumber <= maxTurnNumber && maxTurnNumber >= 1){
        std::sort(players.begin(), players.end(), [](Player  *pl,Player *pr) {
    return (pl->getBoardID() < pr->getBoardID()) ;
});
    turnNumber++;
    // "Turn 13 has started."
    std::cout << "Turn " << turnNumber << " has started." <<std::endl;
    
    for(int i = 0 ; i < players.size() ; i++){
        int bef = players.size();
        playTurnForPlayer(players.at(i));
        int aft = players.size();
        if(aft + 1 == bef)
            i--;
    }
        
    
    
    }
}

Goal Game::playTurnForPlayer(Player* player){
    if(player->getHP() <= 0){
        std::cout << "Player " << player->getBoardID() << " has died." << std::endl;
        int index;
        for(int i = 0; i < players.size() ; i++){
            if(players.at(i)->getBoardID() == player->getBoardID()){
                index = i;
            }
        }
        Player *temp = players.at(index);
        players.erase(players.begin()+ index);
        delete temp;
        temp = NULL;
        return NO_GOAL;
    }
    
    for(Goal goal : player->getGoalPriorityList()){
        if(goal == ATTACK){
            for(std::vector<Player*>::iterator it = players.begin() ; it != players.end() ; it++){
                for(Coordinate attackableCoordinate : player->getAttackableCoordinates()){
                    if((*it)->getCoord() == attackableCoordinate  && (*it)->getTeam() != player->getTeam()){
                        player->attack(*it);
                        return ATTACK;
                    }
                        
                }
            }
            
        }
        else if(goal == HEAL){
            bool isHealed = false;
            for(std::vector<Player*>::iterator it = players.begin() ; it != players.end() ; it++){
                for(Coordinate healableCoordinate : player->getHealableCoordinates()){
                    if((*it)->getCoord() == healableCoordinate  && (*it)->getTeam() == player->getTeam()){
                        player->heal(*it);
                        isHealed = true;
                    }
                }
            }
            if(isHealed)
                return HEAL;
        }

        else if (goal == TO_ALLY){
            std::vector<Player*> allyList = std::vector<Player*> ();    // create an emptly list holds enemies

            for(std::vector<Player*> :: iterator it = players.begin(); it != players.end(); it++){  // push all enemy in the Game into the list
                if((*it)->getTeam() == player->getTeam() && (*it)->getBoardID() != player->getBoardID() )
                    allyList.push_back(*it);       
            }
            if(allyList.size() == 0)
                continue;

            std::sort(allyList.begin(),allyList.end(),[player](Player* l, Player *r){ // sort the list to be lower manhattan distance Player at the front.
                
                return ( (player->getCoord()- l->getCoord()) < (player->getCoord() - r->getCoord()) );
            });

            int min = player->getCoord() - allyList.at(0)->getCoord(); int index = -1 ;
            for(int i = 0 ; i < player->getMoveableCoordinates().size() ; i++){
                if(getBoard()->isCoordinateInBoard(player->getMoveableCoordinates().at(i)) && !getBoard()->isPlayerOnCoordinate(player->getMoveableCoordinates().at(i))){
                    if((player->getMoveableCoordinates().at(i) - allyList.at(0)->getCoord() ) < min ){
                        min = (player->getMoveableCoordinates().at(i) - allyList.at(0)->getCoord() );
                        index = i;
                    }
                }
            }
            if(index != -1) {
                player->movePlayerToCoordinate(player->getMoveableCoordinates().at(index));
                return TO_ALLY;
            }

        }
        else if (goal == TO_ENEMY){
            std::vector<Player*> enemyList = std::vector<Player*> ();    // create an emptly list holds enemies

            for(std::vector<Player*> :: iterator it = players.begin(); it != players.end(); it++){  // push all enemy in the Game into the list
                if((*it)->getTeam() != player->getTeam())
                    enemyList.push_back(*it);
            }

            if(enemyList.size() == 0)
                continue;

            std::sort(enemyList.begin(),enemyList.end(),[player](Player* l, Player *r){ // sort the list to be lower manhattan distance Player at the front.
                
                return ( (player->getCoord()- l->getCoord()) < (player->getCoord() - r->getCoord()) );
            });	

            int min = player->getCoord() - enemyList.at(0)->getCoord() ; int index = -1 ;
            for(int i = 0 ; i < player->getMoveableCoordinates().size() ; i++){
                if(getBoard()->isCoordinateInBoard(player->getMoveableCoordinates().at(i)) && !getBoard()->isPlayerOnCoordinate(player->getMoveableCoordinates().at(i))){
                    if((player->getMoveableCoordinates().at(i) - enemyList.at(0)->getCoord() ) < min ){
                        min = (player->getMoveableCoordinates().at(i) - enemyList.at(0)->getCoord() );
                        index = i;
                    }
                }
            }
            if(index != -1) {
                player->movePlayerToCoordinate(player->getMoveableCoordinates().at(index));
                return TO_ENEMY;
            }

        }
        else if (goal == CHEST){
            int min = player->getCoord() - getBoard()->getChestCoordinates(); int index = -1 ;
            for(int i = 0 ; i < player->getMoveableCoordinates().size() ; i++){
                if(getBoard()->isCoordinateInBoard(player->getMoveableCoordinates().at(i)) && !getBoard()->isPlayerOnCoordinate(player->getMoveableCoordinates().at(i))){
                    if((player->getMoveableCoordinates().at(i) - getBoard()->getChestCoordinates() ) < min ){
                        min = (player->getMoveableCoordinates().at(i) -getBoard()->getChestCoordinates());
                        index = i;
                    }
                }
            }
            if(index != -1) {
                player->movePlayerToCoordinate(player->getMoveableCoordinates().at(index));
                return CHEST;
            }
        }
    }

    return NO_GOAL;

    /**
   * Play a turn for the given player.
   * If the player is dead announce its death by printing the boardID of the player
   * as in "Player 07 died.". Remove that player from the board and release its resources.
   *
   * Each player has a goal list sorted by its priority for that player.
   * When a player plays a turn it iterates over its goal list and tries to take
   * an action. Valid actions are attack, move and heal. A player can take only
   * one action in a turn, and if there is no action it can take it stops and does nothing.
   * Before moving a player you must check if the coordinate to move is valid.
   * Meaning that, the coordinate is in the bounds of the board and there are no
   * players there.
   *
   * IMPORTANT NOTE: every usage of the word nearest is referencing smallest the manhattan
   * distance, which is formulated as (abs(x_1-x_2) + abs(y_1-y_2)). operator-
   * overloaded in Coordinate.h computes exactly that, so you can use that method to
   * calculate the distance between two coordinates.
   *
   * Below are the explanations for goals:
   *
   * ATTACK:
   *   - If there are any enemies in the attack range of the player attack to it.
   *     If there are more than 1 enemy in the range attack to the one with
   *     lowest ID. If there is no one to attack try the next goal.
   *
   * CHEST:
   *   - Move to the direction of the chest, if both vertical and horizontal moves
   *     are available, pick the horizontal one. If the horizontal move is blocked
   *     but the vertical move is not, move vertically. If all directions towards
   *     the chest is blocked try the next goal.
   *
   * TO_ENEMY:
   *   - Move towards the nearest enemy. If there are more than one enemies with the same distance
   *     move towards the one with the smallest ID. If both vertical and horizontal moves
   *     are available, pick the horizontal one. If an enemy is in the squares
   *     that the player can move or every move that brings the player closer to
   *     the selected enemy is blocked, try the next goal.
   *
   * TO_ALLY:
   *   - Move towards the nearest ally. If there are more than one allies with the same distance
   *     move towards the one with the smallest ID.  If both vertical and horizontal moves
   *     are available, pick the horizontal one. If an ally is in the squares
   *     that the player can move or every move that brings the player closer to
   *     the selected ally is blocked, try the next goal.
   *
   * HEAL:
   *   - If there are any allies in the healing range heal all of them. if there
   *     is no one to heal try the next goal.
   *
   *
   * @return the goal that the action was taken upon. NO_GOAL if no action was taken.
   */
    
    
}