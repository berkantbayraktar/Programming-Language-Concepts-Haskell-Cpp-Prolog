#include <iostream>
#include "Laptime.h"
#include "Car.h"
#include "Utilizer.h"

using namespace std;

int main(){

    
  
/*Car ferrari =  Car("Berkant Bayraktar");
    
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
    cout << "Error Lap: " << ferrari[6] << endl;*/
    
    Laptime *n = new Laptime(1000);
    Laptime *m = new Laptime(2000);
    n->addLaptime(m);
    cout << *n<<endl;
    cout << *m<<endl;
    Car *ferrari = new Car("Berkant Bayraktar");
    (*ferrari).Lap(Utilizer::generateAverageLaptime());
    (*ferrari).Lap(Utilizer::generateAverageLaptime());
    cout << "Informations Ferrari: " << *ferrari << endl;
    delete n;
    delete m;
    delete ferrari;
     
    return 0;
}