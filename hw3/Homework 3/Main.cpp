#include <iostream>
#include "Laptime.h"
#include "Car.h"
#include "Utilizer.h"

using namespace std;

int main(){

    
  

    Car ferrari =  Car("Berkant Bayraktar");
    
    cout << "Driver Name: " << ferrari.getDriverName() << endl;
    cout << "Performance: " << ferrari.getPerformance() << endl;
    ferrari.Lap(Utilizer::generateAverageLaptime());
    ferrari.Lap(Utilizer::generateAverageLaptime());
    ferrari.Lap(Utilizer::generateAverageLaptime());
    ferrari.Lap(Utilizer::generateAverageLaptime());
    ferrari.Lap(Utilizer::generateAverageLaptime());
    ferrari.Lap(Utilizer::generateAverageLaptime());
    cout << "Informations Ferrari: " << ferrari<< endl;
    Car *mercedes = new Car("Izel Yemisci");
    cout << "Driver Name: " << (*mercedes).getDriverName() << endl;
    cout << "Performance: " << (*mercedes).getPerformance() << endl;
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    (*mercedes).Lap(Utilizer::generateAverageLaptime());
    cout << "Informations Mercedes: " << (*mercedes)<< endl;

    cout << "Test greater: " << (ferrari > (*mercedes)) << endl;
    cout << "Test less than: " << (ferrari < (*mercedes)) << endl;
    cout << "First Lap: " << ferrari[0] << endl;
    cout << "Third Lap: " << ferrari[2] << endl;
    cout << "Sixth Lap: " << ferrari[5] << endl;
    cout << "Error Lap: " << ferrari[6] << endl;

     return 0;
}