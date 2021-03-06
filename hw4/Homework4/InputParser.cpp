#include"InputParser.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

/**
   * Parse the initial parameters of the game from stdin.
   * The input will be as follows.
   * First line contains the size of the board.
   * Second line contains the coordinates of the chest.
   * Third line contains the number of players, P.
   * Each of the next P lines contains a description for a player as follows.
   * ID of the player, class of the player, team of the player, x coordinate, y coordinate, .
   * Call the addPlayer method of the Game class to add the players.
   * Example input:
   * 6
   * 3 3
   * 29
   * 2
   * 12 ARCHER BARBARIAN 3 5
   * 11 FIGHTER KNIGHT 1 1
   *
   * @returns Pointer to the Dynamically allocated Game object
   */


Game* InputParser::parseGame(){
    int boardSize; int chest_x, chest_y ; int numberOfPlayers; int maxTurn;

    std:: cin >> boardSize;
    std::cin >> chest_x >> chest_y ;
    std::cin >> maxTurn;
    std::cin >> numberOfPlayers;

    Game *g = new Game(maxTurn, boardSize,Coordinate(chest_x,chest_y));

    for(int i = 0 ; i < numberOfPlayers ; i++){
        uint id; std::string playerClass, teamName; int x; int y;

        std::cin >> id >> playerClass >> teamName >> x >> y; 
       
        g->addPlayer(id, x, y, convertStringToEnum(teamName), playerClass);    
    }
    return g;
}

Team InputParser::convertStringToEnum(std::string s){
  
    if(s == "BARBARIAN")
        return BARBARIANS;
    else if (s == "KNIGHT")
        return KNIGHTS;
}