#include <iostream>
#include "Game.h"
#include "InputParser.h"
/** 
 * @author Berkant Bayraktar
 * @version 1.0
 * 
 * dedicated to Izel Yemisci
 * */


int main (){
//Game(uint maxTurnNumber, uint boardSize, Coordinate chest);
    Coordinate c = Coordinate(10,10);
    Game *g ;
    g = InputParser::parseGame();
    g->getBoard()->printBoardwithClass();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    g->getBoard()->printBoardwithID();
    g->playTurn();
    delete g;
    return 0;
}