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

const std::vector<Coordinate> moveOffsets = {Coordinate(-1,0),Coordinate(1,0), Coordinate(0,1), Coordinate(0,-1)};
const std::vector<Coordinate> attackOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1)};

Fighter::Fighter(uint _id , int _x , int _y , Team _team): Player(_id, _x, _y, _team){
    this->HP = this->getMaxHP();
    
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

std::vector<Goal> Fighter::getGoalPriorityList(){
    std::vector<Goal> goalPriority = std::vector <Goal>();
    
    goalPriority.push_back(ATTACK);
    goalPriority.push_back(TO_ENEMY);
    goalPriority.push_back(CHEST);

    return goalPriority;
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
        attackableCoordinates.push_back(attackableCoordinate);
    }
    
    return attackableCoordinates;
}

std::vector<Coordinate> Fighter::getMoveableCoordinates(){
    std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : moveOffsets){
        Coordinate moveableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
        moveableCoordinates.push_back(moveableCoordinate);
    }
    return moveableCoordinates;
}

std::vector<Coordinate> Fighter::getHealableCoordinates(){
    std::vector <Coordinate> healableCoordinates = std::vector <Coordinate>();

    return healableCoordinates;
}