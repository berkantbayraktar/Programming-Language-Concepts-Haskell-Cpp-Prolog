#include"Game.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Game::Game(uint maxTurnNumber, uint boardSize, Coordinate chest): maxTurnNumber(maxTurnNumber), turnNumber(0), board(Board(boardSize,&players ,chest)){
    players = std::vector<Player*>();
    // Board b = Board(boardSize,&players ,chest); !!!!!!!!!!!!!!!
    // this->board = b;
}

void Game::addPlayer(int id, int x, int y, Team team ){
   
}