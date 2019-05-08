#include"Player.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Player::Player(uint id,int x, int y, Team team): id(id), coordinate(Coordinate(x,y)), team(team){}

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


void Player::movePlayerToCoordinate(Coordinate c){
    std::vector <Coordinate> moveableCoordinates = this->getMoveableCoordinates();
    for(Coordinate current : moveableCoordinates){
        if(current == c){
            std::cout << "Player " << this->getBoardID() << " moved from (" << this->getCoord().x << "/" << this->getCoord().y << ") to (" << c.x << "/" << c.y << ")" << std::endl;   // "Player 01 moved from (0/1) to (0/2)"
            this->coordinate = c; 
        }
    }
    
}

bool Player::isDead() const{
    return (this->getHP() <= 0);
}