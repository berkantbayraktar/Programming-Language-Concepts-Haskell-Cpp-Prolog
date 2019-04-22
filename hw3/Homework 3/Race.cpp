#include "Race.h"
#include "Utilizer.h"
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
const std::string driverList[13] = {"Ayrton Senna", "Michael Schumacher", "Jim Clark", "Juan Manuel Fangio" , "Fernando Alonso",
"Alain Prost", "Jackie Stewart", "Emerson Fittipaldi", "Nelson Piquet",
 "Sebastian Vettel", "Lewis Hamilton", "Max Verstappen", "Kimi Raikonnen"};

Race::Race(std::string race_name) : race_name(race_name), average_laptime(Utilizer::generateAverageLaptime()), head(NULL) {}
Race::Race(const Race& rhs) : race_name(race_name),average_laptime(Utilizer::generateAverageLaptime()),head(NULL){}


Race::~Race(){
    // Car *current = head ;
    // while(current != NULL){
    //     Car *n = current->getNext();
    //     delete current;
    //     current = n;
    // }
    // delete head;
}

std::string Race::getRaceName()const{
    return race_name;
}

void Race::addCartoRace(){
    int index;
    index = rand()%13;
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

int Race::getNumberOfCarsinRace()const{
    Car *current = head;
    int numberOfCars = 0;
    
    while(current != NULL){
        numberOfCars++;
        current = current->getNext();
    }
    return numberOfCars;
}

void Race::goBacktoLap(int lap){
    int revert_times = 0;
    Car *current = head;
    if(current == NULL)
        return;
    else{
        while(current != NULL){
            int revert_times = current->getNumberOfLaps() - lap - 1;
            for(int i = 0 ; i < revert_times ; i++)
                --(*this);
            current = current->getNext();    
        }
    }    
}

void Race::operator++(){
    Car *current = head;
    while(current != NULL){
        
        current->Lap(Utilizer::generateAverageLaptime());
        
        current = current-> getNext();
    }
    putCarsOrder();
}

void Race::operator--(){
    Car *current = head; // Get first Car

    while(current != NULL){
        Laptime * traverse = current->getHead(); // Get first Lap
        Laptime *temp ;
        if(traverse != NULL){
            while(traverse->getNext() != NULL){
                temp = traverse;
                traverse = traverse->getNext();
            }         
            delete traverse;
            if(temp != NULL)
                temp->addLaptime(NULL);
        }
        current = current->getNext();
    }
    putCarsOrder();
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
    int numberOfcars = race.getNumberOfCarsinRace();
    std::string str_numberOfcars = std::to_string(numberOfcars);
    int digit = str_numberOfcars.length();


    int index = -48;
    while(temp != NULL){
        os << std::setfill('0') << std::setw(digit) << '1' + index ;
        os << "--" << *temp << std::endl;
        temp = temp ->getNext();
        index++;
    }
    return os;
}

void Race::putCarsOrder(){
   for (int i = 0 ; i < getNumberOfCarsinRace() -1 ; i++){
       for(int j = 0 ; j < (getNumberOfCarsinRace() -1 -i) ; j++){
           if((*this)[j] > (*this)[j+1]){
                if(j== 0){  // swap 0 index and 1
                    Car *a = (*this).getCar(j);
                    Car *b = (*this).getCar(j+1);
                    Car *c = (*this).getCar(j+2);
                    a->addCar(c);
                    b->addCar(a);
                    head = b;
                }
                else{ //swap middle
                    Car *a = (*this).getCar(j);
                    Car *b = (*this).getCar(j+1);
                    Car *c = (*this).getCar(j+2);
                    Car *d = (*this).getCar(j-1);

                    a->addCar(c);
                    b->addCar(a);
                    d->addCar(b);
                    
                }   
           }
       }
   }       
}

Car* Race::getCar(const int car_in_position){
    Car *temp = head;
    for(int i = 0 ; i < car_in_position ; i++)
    {
        temp = temp->getNext();
        if(temp == NULL)
            break;
    }
    return temp;
}