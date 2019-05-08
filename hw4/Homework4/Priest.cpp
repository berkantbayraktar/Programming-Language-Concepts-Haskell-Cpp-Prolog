#include"Priest.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

/**
   * Attack damage 0
   * Heal power 50
   * Max HP 150
   * Goal Priorities -> {HEAL,TO_ALLY,CHEST} in decreasing order
   * Class abbreviation -> "pr" or "PR"
   * Can move to all adjacent squares, including diagonals.
   * Can heal all adjacent squares, including diagonals.
   *
   */


const std::vector<Coordinate> moveOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1), Coordinate(-1,-1), Coordinate(-1,1), Coordinate(1,1), Coordinate(1,-1)};
const std::vector<Coordinate> healOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1), Coordinate(-1,-1), Coordinate(-1,1), Coordinate(1,1), Coordinate(1,-1)};

Priest::Priest(uint _id , int _x , int _y , Team _team): Player(_id, _x, _y, _team){
    this->HP = this->getMaxHP();
}

int Priest::getAttackDamage() const{
    return 0;
}

int Priest::getHealPower() const{
    return 50;
}

int Priest::getMaxHP() const{
    return 150;
}

std::vector<Goal> Priest::getGoalPriorityList(){
    std::vector<Goal> goalPriority = std::vector <Goal>();
    goalPriority.push_back(HEAL);
    goalPriority.push_back(TO_ALLY);
    goalPriority.push_back(CHEST);

    return goalPriority;
}

const std::string Priest::getClassAbbreviation() const{
    if(team == BARBARIANS)
        return "PR";

    else if (team == KNIGHTS)
        return "pr";
}

std::vector<Coordinate> Priest::getMoveableCoordinates(){
    std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : moveOffsets){
        Coordinate moveableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
        moveableCoordinates.push_back(moveableCoordinate);
    }
    return moveableCoordinates;
}

std::vector<Coordinate> Priest::getHealableCoordinates(){
    std::vector <Coordinate> healableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : healOffsets){
        Coordinate healableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
        healableCoordinates.push_back(healableCoordinate);
    }
    return healableCoordinates;
}

std::vector<Coordinate> Priest::getAttackableCoordinates(){
    std::vector <Coordinate> attackableCoordinates = std::vector <Coordinate> ();

    return attackableCoordinates;
}

