#include "Car.h"
#include "Utilizer.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

Car::Car(std::string driver_name){
    this->driver_name = driver_name;
    this->performance = Utilizer::generatePerformance();
    this->head = NULL;
    this->next = NULL;
}

Car::Car(const Car& rhs){
    this->driver_name = rhs.driver_name;
    this->performance = rhs.performance;
    this->head = rhs.head;
    this->next = rhs.next;
}

Car::~Car(){
    // Laptime *current = head;
    // while(current != NULL){
    //     Laptime *n = current->getNext();
    //     delete current;
    //     current = n;
    // }
    // head = NULL;
}

std::string Car::getDriverName() const{
    return driver_name;
}

double Car::getPerformance() const{
    return performance;
}

void Car::addCar(Car *next){
    this->next = next;
}

bool Car::operator<(const Car& rhs) const{
    long lhs_total_laptime = 0, rhs_total_laptime = 0;
    Laptime *temp = head;
    while(temp != NULL){
        lhs_total_laptime += (*temp).getLaptime();
        temp = temp->getNext();
    }
    temp = rhs.head;
    while(temp != NULL){
        rhs_total_laptime += (*temp).getLaptime();
        temp = temp->getNext();
    }
    return (lhs_total_laptime < rhs_total_laptime);
}

bool Car::operator>(const Car& rhs) const{
    long lhs_total_laptime = 0, rhs_total_laptime = 0;
    Laptime *temp = head;
    while(temp != NULL){
        lhs_total_laptime += (*temp).getLaptime();
        temp = temp->getNext();
    }
    temp = rhs.head;
    while(temp != NULL){
        rhs_total_laptime += (*temp).getLaptime();
        temp = temp->getNext();
    }
    return (lhs_total_laptime > rhs_total_laptime);
}

Laptime Car::operator[](const int lap) const {
    Laptime *temp = head;
    
    for(int i = 0 ; i < lap ; i++)
    {
        temp = temp->getNext();
        if(temp == NULL){
            temp = new Laptime(0);
            break;
        }
    }
    return *temp;
}

void Car::Lap(const Laptime& average_laptime){
    Laptime *new_laptime = new Laptime(average_laptime.getLaptime() + Utilizer::generateLaptimeVariance(performance));
    if(head == NULL){
        head = new_laptime;
        //std::cout << *head << std::endl;
    }
    
    else{
        Laptime *temp = head;
        //std::cout << *new_laptime << std::endl;
        while(temp->getNext() != NULL)
            temp = temp->getNext();
        temp->addLaptime(new_laptime);  
               
    }    
}

std::ostream& operator<<(std::ostream& os, const Car& car){
    long fastest_laptime = 0, latest_laptime = 0, total_laptime = 0;
    Laptime *temp,*ll,*fl,*tl;
    size_t pos = car.driver_name.find(" ");
    std::string p =car.driver_name.substr(pos+1,3);
    for(int i = 0 ; i < p.length() ; i++){
        p [i] = toupper(p[i]);
    }

    temp = car.head;

    if(temp != NULL){
        while(temp->getNext() != NULL)
            temp = temp->getNext();

    latest_laptime = temp->getLaptime();

    }
    

    fastest_laptime = car.getFastestLapTime();

    temp = car.head;
    while(temp != NULL){
        total_laptime += temp->getLaptime();
        temp = temp->getNext();
    }

    ll = new Laptime(latest_laptime);
    fl = new Laptime(fastest_laptime);
    tl = new Laptime(total_laptime);

    os  << p << "--" << (*ll) << "--" << (*fl) << "--" << (*tl);
    
    return os;
}

Car * Car::getNext()const{
    return next;
}

Laptime * Car::getHead()const{
    return head;
}


int Car::getNumberOfLaps(){

    Laptime *temp;
    int numberOfLaps = 0;
    temp = head;
    while(temp != NULL){
        numberOfLaps++;
        temp = temp->getNext();
    }
    return numberOfLaps;

}

long Car::getFastestLapTime()const{
    long fastest_laptime = 0;

    Laptime * current = head;

    if(current != NULL)
        fastest_laptime = LONG_MAX;

    while(current != NULL){
        if(current->getLaptime() < fastest_laptime)
            fastest_laptime  = current->getLaptime();
        current = current->getNext();    
    }
    return fastest_laptime;
}