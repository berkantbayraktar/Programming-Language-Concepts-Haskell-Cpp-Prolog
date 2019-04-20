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
    delete next;
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

Laptime Laptime::operator[](const int lap) const{
    Laptime *n = next;
    for(int i = 1 ; i < lap ; i++){
        n = n->next;

        if(n == NULL)
            break;
    }

    if(n == NULL)
        return Laptime(0);
    else if(lap == 0)
        return *this;
    else if (lap > 0)
        return *n; 
    else
        return Laptime(0);       
}

Laptime& Laptime::operator+(const Laptime& rhs){
    Laptime *total = new Laptime(laptime + rhs.laptime);
    return *total;
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

int Laptime::getLaptime(){
    return laptime;
}