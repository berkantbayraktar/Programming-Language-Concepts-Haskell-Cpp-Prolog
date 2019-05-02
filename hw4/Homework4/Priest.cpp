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


int Player::getAttackDamage() const{
    return 0;
}

int Player::getHealPower() const{
    return 50;
}

int Player::getMaxHP() const{
    return 150;
}

const std::string Player::getClassAbbreviation() const{
    if(team == BARBARIANS)
        return "PR";

    else if (team == KNIGHTS)
        return "pr";
}

std::vector<Coordinate> Player::getMoveableCoordinates(){
    std::vector <Coordinate> moveableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : moveOffsets){
        Coordinate moveableCoordinates = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
    }
    return moveableCoordinates;
}

std::vector<Coordinate> Player::getHealableCoordinates(){
    std::vector <Coordinate> healableCoordinates = std::vector <Coordinate>();

    for(Coordinate offset : healOffsets){
        Coordinate healableCoordinates = Coordinate(coordinate.x + offset.x , coordinate.y + offset.y);
    }
    return healableCoordinates;
}


