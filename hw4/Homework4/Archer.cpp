#include"Archer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
static const std::vector<Coordinate> attackOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1), Coordinate(-2,0), Coordinate(0,2), Coordinate(2,0), Coordinate(0,-2)};

/**
   * Attack damage 50
   * Heal power 0
   * Max HP 200
   * Goal Priorities -> {ATTACK}
   * Class abbreviation -> "ar" or "AR"
   * Not able to move at all.
   * Can attack to a range of 2 squares directly up, down, left or right, from
   * its coordinate.
   *
   */

Archer::Archer(uint _id , int _x , int _y , Team _team): Player(_id, _x, _y, _team){
    this->HP = this->getMaxHP();
    goalPriority.push_back(ATTACK);
}

int Archer::getAttackDamage() const{
    return 50;
}

int Archer::getHealPower() const{
    return 0;
}

int Archer::getMaxHP() const{
    return 200;
}

const std::string Archer::getClassAbbreviation() const{
    if(team == BARBARIANS)
        return "AR";

    else if (team == KNIGHTS)
        return "ar";
}

std::vector<Coordinate> Archer::getAttackableCoordinates(){
    std::vector<Coordinate> attackableCoordinates = std::vector<Coordinate>();

    for(Coordinate offset : attackOffsets){
        Coordinate attackableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
    }
    
    return attackableCoordinates;
}

// std::vector<Coordinate> Archer::getMoveableCoordinates(){
//     std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

//     return moveableCoordinates;
// }

// std::vector<Coordinate> Archer::getHealableCoordinates(){
//     std::vector <Coordinate> healableCoordinates = std::vector <Coordinate>();

//     return healableCoordinates;
// }