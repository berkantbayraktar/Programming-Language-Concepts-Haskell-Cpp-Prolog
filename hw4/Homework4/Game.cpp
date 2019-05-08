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
    return (pl->getBoardID() < pr->getBoardID()) ;
});
    // "Turn 13 has started."
    std::cout << "Turn " << turnNumber << " has started." <<std::endl;
    
    for(std::vector<Player*>::iterator it  = players.begin() ; it != players.end() ; it++){
            this->playTurnForPlayer(*it);
        }

}

Goal Game::playTurnForPlayer(Player* player){
    if(player->getHP() <= 0){
        std::cout << "Player " << player->getBoardID() << " died." << std::endl;
        delete player;
        player = NULL;
    }
    
    for(Goal goal : player->getGoalPriorityList()){
        if(goal == ATTACK){
            for(Coordinate attackableCoordinate : player->getAttackableCoordinates()){
                if(getBoard()->isCoordinateInBoard(attackableCoordinate) && getBoard()->isPlayerOnCoordinate(attackableCoordinate)){
                    Player *p = getBoard()->operator[](attackableCoordinate);
                    if(p->getTeam() != player->getTeam()){
                        player->attack(p);
                        return ATTACK;
                    }
                }
            }
        }
        else if(goal == HEAL){
            bool isHealed = false;
            for(Coordinate healableCoordinate : player->getHealableCoordinates()){
                if(getBoard()->isCoordinateInBoard(healableCoordinate) && getBoard()->isPlayerOnCoordinate(healableCoordinate)){
                    Player *p = getBoard()->operator[](healableCoordinate);
                    if(p->getTeam() == player->getTeam()){
                        player->heal(p);
                        isHealed =true;
                    }
                }
            }
            if(isHealed)
                return HEAL;
        }

        else if (goal == TO_ALLY){

        }
        else if (goal == TO_ENEMY){

        }
        else if (goal == CHEST){

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