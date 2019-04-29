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
    Race istanbul = Race("istanbul");
    for(int i= 0 ; i < 10 ; i++){
        istanbul.addCartoRace();
    }
     
    // (*istanbul).addCartoRace(*ferrari);
    // (*istanbul).addCartoRace(*mercedes);
    // (*istanbul).addCartoRace(*yamaha);
    // (*istanbul).addCartoRace(*renault);
    // (*istanbul).addCartoRace(*opel);
    cout << istanbul;
    for(int i = 0 ; i < 10 ; i++){
        ++istanbul;
        cout << istanbul;
    }
    --istanbul;
    cout << istanbul << endl;;
    --istanbul;
    cout << "ISTANBUL"<< endl;
    cout << istanbul<< endl;
    cout << "performance test:" << istanbul[9].getPerformance() << endl;

    Race monaco = istanbul;
    cout << "MONACO"<< endl;
    cout << monaco <<endl;
    cout << "performance test:" << monaco[9].getPerformance() << endl;
            

    cout << "Number of cars in the race: " << monaco.getNumberOfCarsinRace()  << endl; ;
   
    return 0;
}