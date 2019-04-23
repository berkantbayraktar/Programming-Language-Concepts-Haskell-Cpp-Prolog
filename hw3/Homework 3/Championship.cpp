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
    const int table[10] = {25,18,15,12,10,8,6,4,2,1};
    std::vector<std::pair<std::string, int>> leaderboard;
    std::vector<std::pair<std::string, int>> points;

    Race first_race = championship.races.at(0);

    for(int i = 0 ; i < first_race.getNumberOfCarsinRace() ; i++)
        leaderboard.push_back(std::make_pair(first_race[i].getDriverName(),0));

    for(unsigned int i = 0 ; i < championship.races.size() ; i++){
        Race current = championship.races.at(i);
        for(int i = 0 ; i < current.getNumberOfCarsinRace();i++){
            points.push_back(std::make_pair(current[i].getDriverName(),i));
        }
    }

    for(unsigned int i = 0 ; i < points.size() ; i++){
        for(unsigned int j = 0 ; j < leaderboard.size() ; j++){
            if(points.at(i).first == leaderboard.at(j).first){
                leaderboard.at(j).second += table[points.at(i).second];
            }
        }
    }

    std::sort(leaderboard.begin(), leaderboard.end(), [](const std::pair<std::string,int> &left, const std::pair<std::string,int> &right) {
    return left.second > right.second;
});

    for(unsigned int i = 0; i < leaderboard.size(); i++){
        os << i << "--" << leaderboard.at(i).first << "--" << leaderboard.at(i).second << std::endl ; 
    }




    return os;
 }
