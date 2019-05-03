#include"Player.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Player::Player(uint id,int x, int y, Team team): id(id), coordinate(Coordinate(x,y)), team(team){
    goalPriority =  std::vector<Goal>();
}


uint Player::getID() const{
    return id;
}

const Coordinate& Player::getCoord() const{
    return coordinate;
}

int Player::getHP() const{
    return HP;
}

Team Player::getTeam() const{
    return team;
}

std::string Player::getBoardID(){
    
    std::string str_id = std::to_string(id);
    int length = str_id.length();
    
    if(length == 1){
        
        return std::to_string(0) + str_id;
    }
        
    else{ 
        return str_id;
    }
          
}

std::vector<Goal> Player::getGoalPriorityList(){
    return goalPriority;
}

const std::string Player::getClassAbbreviation() const{
    return "XD";
}

bool Player::attack(Player *enemy){
    enemy->HP -= this->getAttackDamage();
    std::cout<< "Player " << this->getBoardID() << " attacked " << "Player " << enemy->getBoardID() << " (" << this->getAttackDamage() << ")" << std::endl;  // "Player 01 attacked Player 05 (75)"
    return isDead();
}

void Player::heal(Player *ally){
    ally->HP += this->getHealPower();
    if(ally->HP > ally->getMaxHP())
        ally->HP = ally->getMaxHP();
    
    std::cout << "Player " << this->getBoardID() << " healed " << "Player " << ally->getBoardID() << std::endl;   // "Player 01 healed Player 05"
}

std::vector<Coordinate> Player::getAttackableCoordinates(){
    std::vector <Coordinate> attackableCoordinates = std::vector <Coordinate> ();

    return attackableCoordinates;
}

std::vector<Coordinate> Player::getMoveableCoordinates(){
    std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

    return moveableCoordinates;
}

std::vector<Coordinate> Player::getHealableCoordinates(){
    std::vector <Coordinate> healableCoordinates = std::vector <Coordinate>();

    return healableCoordinates;
}

void Player::movePlayerToCoordinate(Coordinate c){
    // IMPLEMENT
}

bool Player::isDead() const{
    return (this->getHP() <= 0);
}