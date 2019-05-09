#include"Scout.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

/**
   * Attack damage 25
   * Heal power 0
   * Max HP 125
   * Goal Priorities -> {CHEST,TO_ALLY,ATTACK} in decreasing order
   * Class abbreviation -> "sc" or "SC"
   * Can move to all adjacent squares, including diagonals.
   * Can attack all adjacent squares, including diagonals.
   *
   */


const std::vector<Coordinate> moveOffsets = {Coordinate(-1,0), Coordinate(1,0), Coordinate(0,1), Coordinate(0,-1), Coordinate(-1,-1), Coordinate(-1,1), Coordinate(1,1), Coordinate(1,-1)};
const std::vector<Coordinate> attackOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1), Coordinate(-1,-1), Coordinate(-1,1), Coordinate(1,1), Coordinate(1,-1)};

Scout::Scout(uint _id , int _x , int _y , Team _team): Player(_id, _x, _y, _team){
    this->HP = this->getMaxHP();
    
}

int Scout::getAttackDamage() const{
    return 25;
}

int Scout::getHealPower() const{
    return 0;
}

int Scout::getMaxHP() const{
    return 125;
}

std::vector<Goal> Scout::getGoalPriorityList(){
    std::vector<Goal> goalPriority = std::vector <Goal>();

    goalPriority.push_back(CHEST);
    goalPriority.push_back(TO_ALLY);
    goalPriority.push_back(ATTACK);
    
    return goalPriority;
}

const std::string Scout::getClassAbbreviation() const{
    if(team == BARBARIANS)
        return "SC";

    else if (team == KNIGHTS)
        return "sc";
}

std::vector<Coordinate> Scout::getAttackableCoordinates(){
    std::vector<Coordinate> attackableCoordinates = std::vector<Coordinate>();

    for(Coordinate offset : attackOffsets){
        Coordinate attackableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
        attackableCoordinates.push_back(attackableCoordinate);
    }
    
    return attackableCoordinates;
}

std::vector<Coordinate> Scout::getMoveableCoordinates(){
    std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : moveOffsets){
        Coordinate moveableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
        moveableCoordinates.push_back(moveableCoordinate);
    }
    return moveableCoordinates;
}

std::vector<Coordinate> Scout::getHealableCoordinates(){
    std::vector <Coordinate> healableCoordinates = std::vector <Coordinate>();

    return healableCoordinates;
}
