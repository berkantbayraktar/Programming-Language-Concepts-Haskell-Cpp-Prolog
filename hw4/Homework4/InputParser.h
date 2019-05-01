#ifndef HW4_INPUTPARSER_H
#define HW4_INPUTPARSER_H

#include<iostream>
#include"Game.h"
class InputParser{

public:

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
   * 2
   * 12 ARCHER BARBARIAN 3 5
   * 11 FIGHTER KNIGHT 1 1
   *
   * @returns Pointer to the Dynamically allocated Game object
   */
  static Game* parseGame();
};

#endif
