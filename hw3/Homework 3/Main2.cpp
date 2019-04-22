#include <iostream>
#include "Laptime.h"
#include "Car.h"
#include "Utilizer.h"
#include "Race.h"

using namespace std;

int main (){
    // Car *ferrari = new Car("Berkant Bayraktar");
    // (*ferrari).Lap(Utilizer::generateAverageLaptime());
    // (*ferrari).Lap(Utilizer::generateAverageLaptime());
    // (*ferrari).Lap(Utilizer::generateAverageLaptime());
    // Car *mercedes = new Car("Izel Yemisci");
    // Car *yamaha = new Car("Bayraktar Serhat");
    // Car *renault = new Car("Bayraktar Osman");
    //  Car *opel = new Car("Bayraktar Selda");
    // (*mercedes).Lap(Utilizer::generateAverageLaptime());
    // (*mercedes).Lap(Utilizer::generateAverageLaptime());
    // (*mercedes).Lap(Utilizer::generateAverageLaptime());
    Race *istanbul = new Race("istanbul");
    for(int i= 0 ; i < 5 ; i++){
        (*istanbul).addCartoRace();
    }
     
    // (*istanbul).addCartoRace(*ferrari);
    // (*istanbul).addCartoRace(*mercedes);
    // (*istanbul).addCartoRace(*yamaha);
    // (*istanbul).addCartoRace(*renault);
    // (*istanbul).addCartoRace(*opel);
    cout << (*istanbul);
    for(int i = 0 ; i < 3 ; i++){
        ++(*istanbul);
        cout << (*istanbul);
    }
    --(*istanbul);
    cout << (*istanbul);
            

    cout << ((*istanbul)[0] > (*istanbul)[4])  << endl; ;
    cout << (*istanbul).getNumberOfCarsinRace()  << endl; ;
   
    return 0;
}