#include "Race.h"
#include "Utilizer.h"
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
const std::string driverList[10] = {"Ayrton Senna", "Michael Schumacher", "Jim Clark", "Juan Manuel Fangio" , "Fernando Alonso",
"Alain Prost", "Jackie Stewart", "Emerson Fittipaldi", "Nelson Piquet",
 "Sebastian Vettel"};

Race::Race(std::string race_name) : race_name(race_name), average_laptime(Utilizer::generateAverageLaptime()), head(NULL) {}
Race::Race(const Race& rhs) : race_name(race_name),average_laptime(Utilizer::generateAverageLaptime()),head(NULL){}


Race::~Race(){
    Car *temp ;
    while(head != NULL){
        temp = head-> getNext();
        delete head;
        head = temp;
    }
}

std::string Race::getRaceName()const{
    return race_name;
}

void Race::addCartoRace(){
    int index;
    index = rand()%10;
    std::string driver_name = driverList[index];
    Car *new_car = new Car(driver_name);
    Car *temp;

    if(head == NULL){
        head = new_car;
        //std::cout << *head << std::endl;
    }
    else{
        temp = head;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        temp->addCar(new_car);
        //std::cout << *new_car << std::endl;
    }
}

void Race::addCartoRace(Car& car){
    Car *temp;
    if(head == NULL){
        head = &car;
    }
    else{
        temp = head;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        temp->addCar(&car);
    }
}

int Race::getNumberOfCarsinRace(){
    Car *temp;
    int numberOfCars = 0;
    temp = head;
    while(temp != NULL){
        numberOfCars++;
        temp = temp->getNext();
    }
    return numberOfCars;
}

void Race::goBacktoLap(int lap){

}

void Race::operator++(){
    Car *temp = head;
    while(temp != NULL){
        
        temp->Lap(Utilizer::generateAverageLaptime());
        
        temp = temp-> getNext();
    }
}

void Race::operator--(){
    Car *current = head;
    Laptime *traverse ;
    if(current == NULL)
        return;
    else{
        while(current != NULL){
            traverse = current->getHead();
            while(traverse->getNext() != NULL){
                traverse = traverse->getNext();
            }
            
            delete traverse;
            current = current->getNext();
        }
    }
}

Car Race::operator[](const int car_in_position){
    Car *temp = head;
    for(int i = 0 ; i < car_in_position ; i++)
    {
        temp = temp->getNext();
        if(temp == NULL)
            break;
    }
    return *temp;

}

Car Race::operator[](std::string driver_name){
    Car *temp = head;
    while(temp != NULL){
        if(temp->getDriverName() == driver_name)
            return *temp;
        temp = temp->getNext();    
    }
    return *temp;
}

Race& Race::operator=(const Race& rhs){
    this->head = rhs.head;
    this->race_name = rhs.race_name;
    this->average_laptime = rhs.average_laptime;
}

std::ostream& operator<<(std::ostream& os, const Race& race){
    Car *temp = race.head;
    int index = -48;
    while(temp != NULL){
        os << "00" << '1' + index << "--" << *temp << std::endl;
        temp = temp ->getNext();
        index++;
    }
    return os;
}