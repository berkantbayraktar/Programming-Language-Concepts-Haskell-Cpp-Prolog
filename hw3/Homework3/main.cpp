#include <iostream>
#include "Laptime.h"
#include "Car.h"
#include "Race.h"
#include "Championship.h"
using namespace std;
int main(void) {
    /**********************************************/
    /************** LAPTIME TEST ******************/
    /**********************************************/
    Laptime small(87625);
    Laptime large(188524);

    if(small<large)
        cout<<small<<endl<<endl;
    else
        cout<<"ERROR"<<endl<<endl;

    if(large>small)
        cout<<large<<endl<<endl;
    else
        cout<<"ERROR"<<endl<<endl;

    small = large+small;

    cout<<"small "<<small<<endl;
    cout<<"large "<<large<<endl;

    /**********************************************/
    /************** CAR AND RACE TEST *************/
    /**********************************************/

    cout<<"CREATING CARS"<<endl<<endl;
    Car alonso("Fernando Alonso");
    Car hamilton("Lewis Hamilton");
    Car vettel("Sebastian Vettel");
    Car leclerc("Charles Leclerc");
    Car bottas("Valtteri Bottas");
    Car verstappen("Max Verstappen");
    Car gasly("Pierre Gasly");
    Car hulkenberg("Nico Hulkenberg");
    Car ricciardo("Daniel Ricciardo");
    Car raikkonen("Kimi Raikkonen");
    Car giovinazzi("Antonio Giovinazzi");


    cout<<"CREATING a RACE NAMED BAKU"<<endl<<endl;
    Race baku("baku");
    cout<<"RACE CREATED"<<endl<<endl;
    baku.addCartoRace(alonso);
    baku.addCartoRace(hamilton);
    baku.addCartoRace(vettel);
    baku.addCartoRace(leclerc);
    baku.addCartoRace(bottas);
    baku.addCartoRace(verstappen);
    baku.addCartoRace(gasly);
    baku.addCartoRace(hulkenberg);
    baku.addCartoRace(ricciardo);
    baku.addCartoRace(raikkonen);
    baku.addCartoRace(giovinazzi);
    baku.addCartoRace();
    baku.addCartoRace();
    baku.addCartoRace();
    baku.addCartoRace();
    baku.addCartoRace();
    baku.addCartoRace();
    baku.addCartoRace();
    baku.addCartoRace();
    baku.addCartoRace();
    
    cout<<"NUMBER OF CARS"<<endl<<endl;
    cout<<baku.getNumberOfCarsinRace()<<endl;

    cout<<"PREFIX TEST"<<endl<<endl;
    ++baku;

    cout<<"OSTREAM TEST"<<endl<<endl;;
    cout<<baku<<endl<<endl;

    for(int i = 0;i<55;i++) {
        ++baku;
    }

    cout<<"INDEXING"<<endl;
    cout<<baku[0][0]<<endl<<endl;

    cout<<"AFTER MANY LAPS"<<endl<<endl;
    cout<<baku<<endl<<endl;

    cout<<"GO BACK TEST"<<endl;
    baku.goBacktoLap(0);
    cout<<baku<<endl<<endl;


/**********************************************/
/************** CHAMPIONSHIP TEST *************/
/**********************************************/
    cout<<"CHAMPIONSHIP"<<endl<<endl;
    Championship champ;

    cout<<"ADD baku"<<endl<<endl;
    champ.addNewRace(baku);

    cout<<"OSTREAM TEST"<<endl<<endl;
    cout<<champ<<endl;


    cout<<"ADDING NEW RACE China"<<endl<<endl;
    champ.addNewRace("china");
    for(int i = 0; i<25 ;i++) {
        champ.addLap("china");
    }
    cout<<"first without istanbul Overall Championship Results"<<endl<<endl;
    cout<<champ<<endl;


    cout<<"ADDING NEW RACE Istanbul"<<endl<<endl;
    champ.addNewRace("istanbul");
    for(int i = 0; i<25 ;i++) {
        champ.addLap("istanbul");
    }

    cout<<"China RACE RESULST"<<endl<<endl;
    cout<<champ["china"]<<endl<<endl;

    cout<<"Baku RACE RESULST"<<endl<<endl;
    cout<<champ["baku"]<<endl<<endl;
   

    cout<<"Istanbul RACE RESULST"<<endl<<endl;
    cout<<champ["istanbul"]<<endl<<endl;


    cout<<"with Istanbul Overall Championship Results"<<endl<<endl;
    cout<<champ<<endl;

    for(int i = 0 ; i < 20 ; i++){
        std::cout <<  baku[i].getDriverName() << std::endl;
    }

    champ.removeRace("istanbul");

    cout<<"without istanbul Overall Championship Results"<<endl<<endl;
    cout<<champ<<endl;

    cout<<"END OF TEST"<<endl;
    

}