#include "Championship.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

Championship::Championship(){
    races = std::vector<Race>();
}

Championship::Championship(const Championship& rhs){
    this->races = rhs.races;
}

Championship::~Championship(){

}
void Championship::addNewRace(Race& race){
    races.push_back(race);
}

void Championship::addNewRace(std::string race_name){
    Race new_race = *races.begin();
    new_race.setAverageLapTime();
    new_race.setRaceName(race_name);
    races.push_back(new_race);
    
}

void Championship::removeRace(std::string race_name){
    for(unsigned int i = 0 ; i < races.size() ; i++){
        if(races.at(i).getRaceName() == race_name)
            races.erase(races.begin()+i);
    }
}

void Championship::addLap(std::string race_name){
    for(unsigned int i = 0 ; i < races.size() ; i++){
        if(races.at(i).getRaceName() == race_name)
            ++races.at(i);
    }
}

 Race Championship::operator[](std::string race_name){
    for(unsigned int i = 0 ; i < races.size() ; i++){
        if(races.at(i).getRaceName() == race_name)
            return races.at(i);
    }

 }

 std::ostream& operator<<(std::ostream& os, const Championship& championship){
     for(unsigned int i = 0 ; i < championship.races.size() ; i++){
         os << championship.races.at(i);
    }
    return os;
 }
