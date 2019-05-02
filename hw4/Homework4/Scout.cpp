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


const std::vector<Coordinate> moveOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1), Coordinate(-1,-1), Coordinate(-1,1), Coordinate(1,1), Coordinate(1,-1)};
const std::vector<Coordinate> attackOffsets = {Coordinate(-1,0), Coordinate(0,1), Coordinate(1,0), Coordinate(0,-1), Coordinate(-1,-1), Coordinate(-1,1), Coordinate(1,1), Coordinate(1,-1)};

int Player::getAttackDamage() const{
    return 25;
}

int Player::getHealPower() const{
    return 0;
}

int Player::getMaxHP() const{
    return 125;
}

const std::string Player::getClassAbbreviation() const{
    if(team == BARBARIANS)
        return "SC";

    else if (team == KNIGHTS)
        return "sc";
}

std::vector<Coordinate> Player::getAttackableCoordinates(){
    std::vector<Coordinate> attackableCoordinates = std::vector<Coordinate>();

    for(Coordinate offset : attackOffsets){
        Coordinate attackableCoordinate = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
    }
    
    return attackableCoordinates;
}

std::vector<Coordinate> Player::getMoveableCoordinates(){
    std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : moveOffsets){
        Coordinate moveableCoordinates = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
    }
    return moveableCoordinates;
}
