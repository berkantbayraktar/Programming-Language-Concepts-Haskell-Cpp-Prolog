#include <iostream>
#include "Laptime.h"
#include "Car.h"
#include "Utilizer.h"
#include "Race.h"

using namespace std;

int main (){
    Car *ferrari = new Car("Berkant Bayraktar");
    (*ferrari).Lap(Utilizer::generateAverageLaptime());
    (*ferrari).Lap(Utilizer::generateAverageLaptime());
    (*ferrari).Lap(Utilizer::generateAverageLaptime());
    Car *mercedes = new Car("Izel Yemisci");
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    
    Race *istanbul = new Race("istanbul");
    (*istanbul).addCartoRace(*ferrari);
    (*istanbul).addCartoRace(*mercedes);
        
    cout << (*istanbul);
    ++(*istanbul);
    cout << (*istanbul);
    ++(*istanbul);
    cout << (*istanbul);
    --(*istanbul);
    cout << (*istanbul);
    --(*istanbul);
    cout << (*istanbul);
   
    cout << "terminating..." <<endl;
    --(*istanbul);
    cout << (*istanbul);
    --(*istanbul);
    cout << (*istanbul);
    --(*istanbul);
    cout << (*istanbul);
    return 0;
}