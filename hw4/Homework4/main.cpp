#include <iostream>
#include "Game.h"
#include "InputParser.h"
int main (){
//Game(uint maxTurnNumber, uint boardSize, Coordinate chest);
    Coordinate c = Coordinate(10,10);
    Game *g ;
    g = InputParser::parseGame();
    g->board.printBoardwithClass();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    g->board.printBoardwithID();
    delete g;
    return 0;
}