#include <iostream>
#include "Laptime.h"

using namespace std;

int main(){
    Laptime *a = new Laptime(79125);
    Laptime *b = new Laptime(6);
    Laptime *c = new Laptime(7);
    (*a).addLaptime(b);
    (*a).addLaptime(c);
    
    cout << (*a).getLaptime() << endl;
    cout << (*a)[2].getLaptime()  << endl;
    cout << ((*a) < (*b)) << endl;
    cout << (*a) <<endl;
    return 0;
}