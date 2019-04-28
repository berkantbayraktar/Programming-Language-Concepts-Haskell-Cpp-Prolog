#include "Laptime.h"
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/


Laptime::Laptime(int laptime){
    this->laptime = laptime;
    this->next = NULL;
}

Laptime::Laptime(const Laptime& rhs){ //WORKS WELL
    this->laptime = rhs.laptime;
    this->next = NULL;

    Laptime *current;
    Laptime *temp = rhs.next;
    Laptime *new_laptime;
    while(temp != NULL){
        if(this->next == NULL){
            new_laptime = temp;
            next = new_laptime;
            current = next;
            temp = temp->getNext();
        }
        else{
            new_laptime = temp;
            current->addLaptime(new_laptime);
            temp = temp->getNext();
            current = current->getNext();
        }
    }
}

Laptime::~Laptime(){
    next = NULL;
}

void Laptime::addLaptime(Laptime *next){
    this->next = next;
}

bool  Laptime::operator<(const Laptime& rhs) const{
    return (laptime < rhs.laptime);
}

bool  Laptime::operator>(const Laptime& rhs) const{
    return (laptime > rhs.laptime);
}


Laptime& Laptime::operator+(const Laptime& rhs){
    this->laptime = this->laptime + rhs.laptime;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Laptime& laptime){
    long t = laptime.laptime;
    
    long min = t / 60000;
    t = t - 60000 * min;


    long sec = t / 1000;
    t = t - 1000 * sec;

    os << min << ":" ;
    os << std::setfill('0') << std::setw(2) <<  sec << "." ;
    os << std::setfill('0') << std::setw(3) << t;
    return os;

}

int Laptime::getLaptime()const{
    return laptime;
}

Laptime * Laptime::getNext()const{
    return next;
}