#include <iostream>
#include "Laptime.h"
#include "Car.h"
#include "Utilizer.h"
#include "Race.h"
#include "Championship.h"

using namespace std;

int main(){

    Championship ikibinondokuz = Championship();
    Race istanbul = Race("istanbul");
    for(int i= 0 ; i < 5 ; i++){
        istanbul.addCartoRace();
    }
    
    ikibinondokuz.addNewRace(istanbul);
    ikibinondokuz.addNewRace("ankara");
    ikibinondokuz.addNewRace("izmir");
    ikibinondokuz.addNewRace("antalya");
    for(int i= 0 ; i < 10 ; i++){
        ikibinondokuz.addLap("istanbul");
        ikibinondokuz.addLap("ankara");
        ikibinondokuz.addLap("izmir");
        ikibinondokuz.addLap("antalya");
    }

    cout << ikibinondokuz["istanbul"] << endl;
    cout << ikibinondokuz["ankara"] << endl;
    cout << ikibinondokuz["izmir"] << endl;
    cout << ikibinondokuz["antalya"] << endl;

    cout << ikibinondokuz << endl;

}