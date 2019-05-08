#include"Fighter.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

/**
   * Attack damage 100
   * Heal power 0
   * Max HP 400
   * Goal Priorities -> {ATTACK,TO_ENEMY,CHEST} in decreasing order
   * Class abbreviation -> "fi" or "FI"
   * Can move to adjacent up, down, left or right square
   * Can attack to adjacent up, down, left or right square
   *
   */

const std::vector<Coordinate> moveOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1)};
const std::vector<Coordinate> attackOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1)};

Fighter::Fighter(uint _id , int _x , int _y , Team _team): Player(_id, _x, _y, _team){
    this->HP = this->getMaxHP();
    goalPriority.push_back(ATTACK);
    goalPriority.push_back(TO_ENEMY);
    goalPriority.push_back(CHEST);
}

int Fighter::getAttackDamage() const{
    return 100;
}

int Fighter::getHealPower() const{
    return 0;
}

int Fighter::getMaxHP() const{
    return 400;
}

const std::string Fighter::getClassAbbreviation() const{
    if(team == BARBARIANS)
        return "FI";

    else if (team == KNIGHTS)
        return "fi";
}

std::vector<Coordinate> Fighter::getAttackableCoordinates(){
    std::vector<Coordinate> attackableCoordinates = std::vector<Coordinate>();

    for(Coordinate offset : attackOffsets){
        Coordinate attackableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
    }
    
    return attackableCoordinates;
}

std::vector<Coordinate> Fighter::getMoveableCoordinates(){
    std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : moveOffsets){
        Coordinate moveableCoordinates = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
    }
    return moveableCoordinates;
}

std::vector<Coordinate> Fighter::getHealableCoordinates(){
    std::vector <Coordinate> healableCoordinates = std::vector <Coordinate>();

    return healableCoordinates;
}