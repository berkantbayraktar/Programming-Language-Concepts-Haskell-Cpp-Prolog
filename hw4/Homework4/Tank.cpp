#include"Tank.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

/**
   * Attack damage 25
   * Heal power 0
   * Max HP 1000
   * Goal Priorities -> {TO_ENEMY,ATTACK,CHEST} in decreasing order
   * Class abbreviation -> "ta" or "TA"
   * Can move to adjacent up, down, left or right square
   * Can attack to adjacent up, down, left or right square
   *
   */


const std::vector<Coordinate> moveOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1)};
const std::vector<Coordinate> attackOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1)};

Tank::Tank(uint _id , int _x , int _y , Team _team): Player(_id, _x, _y, _team){
    this->HP = this->getMaxHP();
    
}

int Tank::getAttackDamage() const{
    return 25;
}

int Tank::getHealPower() const{
    return 0;
}

int Tank::getMaxHP() const{
    return 1000;
}

std::vector<Goal> Tank::getGoalPriorityList(){
    std::vector<Goal> goalPriority = std::vector <Goal>();

    goalPriority.push_back(TO_ENEMY);
    goalPriority.push_back(ATTACK);
    goalPriority.push_back(CHEST);
    
    return goalPriority;
}

const std::string Tank::getClassAbbreviation() const{
    if(team == BARBARIANS)
        return "TA";

    else if (team == KNIGHTS)
        return "ta";
}

std::vector<Coordinate> Tank::getAttackableCoordinates(){
    std::vector<Coordinate> attackableCoordinates = std::vector<Coordinate>();

    for(Coordinate offset : attackOffsets){
        Coordinate attackableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
        attackableCoordinates.push_back(attackableCoordinate);
    }
    
    return attackableCoordinates;
}

std::vector<Coordinate> Tank::getMoveableCoordinates(){
    std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : moveOffsets){
        Coordinate moveableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
        moveableCoordinates.push_back(moveableCoordinate);
    }
    return moveableCoordinates;
}

std::vector<Coordinate> Tank::getHealableCoordinates(){
    std::vector <Coordinate> healableCoordinates = std::vector <Coordinate>();

    return healableCoordinates;
}