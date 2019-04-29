#include "Championship.h"
#include "Utilizer.h"

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
    races.clear();
    races.shrink_to_fit();
}
void Championship::addNewRace(Race& race){
    std::string race_name = race.getRaceName();
    races.push_back(race);
    for(unsigned int i = 0 ; i < races.size() ; i++){
        if(races.at(i).getRaceName() == race_name)
        {
            races.at(i).setHead(race.getHead());
        }
            
    }
 
}

void Championship::addNewRace(std::string race_name){
    Race new_race = *races.begin();
    new_race.setAverageLapTime(Utilizer::generateAverageLaptime());
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
        {   
            ++races.at(i);
        }
    }
}

 Race& Championship::operator[](std::string race_name){
    for(unsigned int i = 0 ; i < races.size() ; i++){
        if(races.at(i).getRaceName() == race_name)
        {
            return races.at(i);
        }
            
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
                if(points.at(i).second >= 0 && points.at(i).second <=9)
                    leaderboard.at(j).second += table[points.at(i).second];
            }
        }
    }

    for(unsigned int i = 0 ; i < championship.races.size() ; i++){
        int indexOfTheFastestCar = championship.races.at(i).indexOfTheFastestCar();
        for(int j = 0 ; j < first_race.getNumberOfCarsinRace() ; j++){
            Race current = championship.races.at(i);
            if(leaderboard.at(j).first == current.getCar(indexOfTheFastestCar)->getDriverName()){
                if(indexOfTheFastestCar >= 0 && indexOfTheFastestCar <= 9)
                    leaderboard.at(j).second += 1;
            }
        }

    }

    std::sort(leaderboard.begin(), leaderboard.end(), [](const std::pair<std::string,int> &left, const std::pair<std::string,int> &right) {
    return left.second > right.second;
});
    int digit = std::to_string(leaderboard.size()).length();

    for(unsigned int i = 0; i < leaderboard.size(); i++){
        size_t pos = leaderboard.at(i).first.find(" ");
        std::string p = leaderboard.at(i).first.substr(pos+1,3);
        for(int i = 0 ; i < int(p.length()) ; i++){
            p [i] = toupper(p[i]);
        }
        os 
        << std::setfill('0') << std::setw(digit) << i+1 
        << "--" << p
        << "--" << leaderboard.at(i).second << std::endl ; 
    }

    return os;
 }


 Race& Championship::getRace(std::string race_name){
     for(unsigned int i = 0 ; i < races.size() ; i++){
        if(races.at(i).getRaceName() == race_name)
            return races.at(i);
    }
 }
