#include "Laptime.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/


Laptime::Laptime(int laptime){
    this->laptime = laptime;
    this->next = NULL;
}

Laptime::Laptime(const Laptime& rhs){
    this->laptime = rhs.laptime;
    this->next = rhs.next;
}

Laptime::~Laptime(){
    if(next != NULL){
        delete next; 
        next = NULL;
    }
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

    os << min << ":" << sec << "." << t;
    return os;

}

int Laptime::getLaptime()const{
    return laptime;
}

Laptime * Laptime::getNext()const{
    return next;
}

