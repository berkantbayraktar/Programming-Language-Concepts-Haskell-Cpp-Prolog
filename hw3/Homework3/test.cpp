#include "Laptime.h"
#include "Car.h"
#include "Race.h"
#include "Championship.h"
#include <iostream>
int main() {
/*
    Laptime *l1 = new Laptime(60001);
    Laptime *l2 = new Laptime(60302);
    Laptime *l3 = new Laptime(60203);
    Laptime *l4 = new Laptime(*l1);
    l1->addLaptime(l2);
    l1->addLaptime(l3);
    l1->addLaptime(l4);

    std::cout << *l1 << "\n";
    std::cout << *l2 << "\n";
    std::cout << *l3 << "\n";
    std::cout << *l4 << "\n";

    std::cout << *(l1) <<"\n";
    std::cout << *(l1->getNext()) <<"\n";
    std::cout << *(l1->getNext()->getNext()) <<"\n";
    std::cout << *(l1->getNext()->getNext()->getNext()) <<"\n";
    std::cout << (*l1 + *l2) <<"\n";
    std::cout << *(l1) <<"\n";

    if (*l2 > *l1) {
        std::cout << "TRUE\n";
    }
*/


Laptime *l = new Laptime(60000);
Car* c1 = new Car("lewis Hamilton");
Car* c2 = new Car("John snow");
Car* c3 = new Car("daranes targaryen");
Car* c4 = new Car("daranes anan");

c1->Lap(*l);
c1->Lap(*l);
c1->Lap(*l);

c2->Lap(*l);
c2->Lap(*l);
c2->Lap(*l);

c3->Lap(*l);
c3->Lap(*l);
c3->Lap(*l);

c4->Lap(*l);
c4->Lap(*l);
c4->Lap(*l);

c1->addCar(c2);
c1->addCar(c3);

std::cout << (*c1)[0] << "\n";  

Car* c5 = new Car(*c1);

c1->addCar(c4);

std::cout << *(c1) << "\n";
std::cout << *(c1->getNext()) << "\n";
std::cout << *(c1->getNext()->getNext()) << "\n";
std::cout << *(c1->getNext()->getNext()->getNext()) << "\n";


std::cout << "\n" << *(c5) << "\n";
std::cout << *(c5->getNext()) << "\n";
std::cout << *(c5->getNext()->getNext()) << "\n";





return 0;
}
