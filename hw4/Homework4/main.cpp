#include <iostream>
#include "Game.h"
#include "InputParser.h"
int main (){
//Game(uint maxTurnNumber, uint boardSize, Coordinate chest);
    Coordinate c = Coordinate(10,10);
    Game *g = new Game(100, 50,c  );
    g = InputParser::parseGame();

    return 0;
}