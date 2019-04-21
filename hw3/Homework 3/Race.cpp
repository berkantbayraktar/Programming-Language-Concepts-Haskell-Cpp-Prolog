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

Race::Race(std::string race_name){
    this->race_name = race_name;
    this->average_laptime = Utilizer::generateAverageLaptime();
    this->head = NULL;
}

Race::Race(const Race& rhs){
    this->race_name = rhs.race_name;
    this->average_laptime = rhs.average_laptime;
    /* LEFT OVER*/
}

Race::~Race(){

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
        std::cout << *head << std::endl;
    }
    else{
        temp = head;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        temp->addCar(new_car);
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


