#ifndef HW4_ARCHER_H
#define HW4_ARCHER_H

#include"Player.h"

class Archer : public Player{
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
  public:
    Archer(uint _id , int _x , int _y , Team _team);
    int getAttackDamage() const;
    int getHealPower() const;
    int getMaxHP() const;
    const std::string getClassAbbreviation() const;
    std::vector<Coordinate> getAttackableCoordinates();
};

#endif
