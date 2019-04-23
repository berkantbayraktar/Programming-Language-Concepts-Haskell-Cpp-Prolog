#include "Race.h"
#include "Utilizer.h"
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
const std::string driverList[29] = {"Ayrton Senna", "Michael Schumacher", "Jim Clark", "Juan Manuel Fangio" , "Fernando Alonso",
"Alain Prost", "Jackie Stewart", "Emerson Fittipaldi", "Nelson Piquet",
 "Sebastian Vettel", "Lewis Hamilton", "Max Verstappen", "Kimi Raikonnen", "Daniel Ricciardo", "Lando Norris",
 "Romain Grosjean","Pierre Gasly", "Sergio Perez", "Charles Leclerc", "Lance Stroll", "Kevin Magnussen", "Alexander Albon",
 "Daniil Kvyat", "Nico Hulkenberg", "Carlos Sainz", "George Russell", "Valtteri Bottas", "Robert Kubica", "Antonio Giovinazzi"};

Race::Race(std::string race_name) : race_name(race_name), average_laptime(Utilizer::generateAverageLaptime()), head(NULL) {}
Race::Race(const Race& rhs) : race_name(rhs.race_name),average_laptime(rhs.average_laptime),head(NULL){ //WORKS WELL
    Car *temp = rhs.head;
    Car *current;
    while(temp != NULL){
        if(this->head == NULL){
            Car *new_car = new Car(temp->getDriverName());
            new_car->setPerformance(temp->getPerformance());
            head = new_car;
            current = head;
            temp = temp->getNext();
        }

        else{
            Car *new_car = new Car(temp->getDriverName());
            new_car->setPerformance(temp->getPerformance());
            current->addCar(new_car);
            temp = temp->getNext();
            current = current->getNext();
        }
    }
}


Race::~Race(){
    // Car *current = head ;
    // while(current != NULL){
    //     Car *n = current->getNext();
    //     delete current;
    //     current = n;
    // }
    // delete head;
}

std::string Race::getRaceName()const{
    return race_name;
}

void Race::addCartoRace(){
    int index;
    index = rand()%29;
    std::string driver_name = driverList[index];
    driver_name.push_back('a' + rand()%25);
    driver_name.push_back('a' + rand()%25);
    Car *new_car = new Car(driver_name);
    Car *temp;

    if(head == NULL){
        head = new_car;
        //std::cout << *head << std::endl;
    }
    else{
        temp = head;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        temp->addCar(new_car);
        //std::cout << *new_car << std::endl;
    }
}

void Race::addCartoRace(Car& car){
    Car *temp;
    if(head == NULL){
        head = &car;
    }
    else{
        temp = head;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        temp->addCar(&car);
    }
}

int Race::getNumberOfCarsinRace(){
    Car *current = head;
    int numberOfCars = 0;
    
    while(current != NULL){
        numberOfCars++;
        current = current->getNext();
    }
    return numberOfCars;
}

void Race::goBacktoLap(int lap){
    Car *current = head;
    if(current == NULL)
        return;
    else{
        while(current != NULL){
            int revert_times = current->getNumberOfLaps() - lap - 1;
            for(int i = 0 ; i < revert_times ; i++)
                --(*this);
            current = current->getNext();    
        }
    }    
}

void Race::operator++(){
    Car *current = head;
    while(current != NULL){
        
        current->Lap(Utilizer::generateAverageLaptime());
        
        current = current-> getNext();
    }
    putCarsOrder();
}

void Race::operator--(){
    Car *current = head; // Get first Car

    while(current != NULL){
        Laptime * traverse = current->getHead(); // Get first Lap
        Laptime *temp ;
        if(traverse != NULL){
            while(traverse->getNext() != NULL){
                temp = traverse;
                traverse = traverse->getNext();
            }         
            delete traverse;
            if(temp != NULL)
                temp->addLaptime(NULL);
        }
        current = current->getNext();
    }
    putCarsOrder();
}

Car Race::operator[](const int car_in_position){
    Car *temp = head;
    for(int i = 0 ; i < car_in_position ; i++)
    {
        temp = temp->getNext();
        if(temp == NULL)
            break;
    }
    return *temp;

}

Car Race::operator[](std::string driver_name){
    Car *temp = head;
    while(temp != NULL){
        if(temp->getDriverName() == driver_name)
            return *temp;
        temp = temp->getNext();    
    }
    return *temp;
}

Race& Race::operator=(const Race& rhs){
    Race temp(rhs);
    std::swap(temp.head,head);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Race& race){
    Car *current = race.head;
    int numberOfcars = race.getNumberOfCars();
    std::string str_numberOfcars = std::to_string(numberOfcars);
    int digit = str_numberOfcars.length();
    int indexFastestCar = race.indexOfTheFastestCar();

    int rank = 1;
    while(current != NULL){
        os << std::setfill('0') << std::setw(digit) << std::to_string(rank);
        os << "--" << *current;
        
        if(rank == 1){
            os << "--" << "25";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 2){
            os << "--" << "18";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 3){
            os << "--" << "15";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 4){
            os << "--" << "12";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 5){
            os << "--" << "10";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 6){
            os << "--" << "8";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 7){
            os << "--" << "6";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 8){
            os << "--" << "4";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 9){
            os << "--" << "2";
            if(indexFastestCar+1 == rank)
                os << "--" << "1";
        }
            
        else if(rank == 10){
            os << "--" << "1";
            if(indexFastestCar+1 == rank)
                os << "--" << "1"; 
        }
            

        os << std::endl;
        current = current ->getNext();
        rank++;
    }
    return os;
}

void Race::putCarsOrder(){
   for (int i = 0 ; i < getNumberOfCarsinRace() -1 ; i++){
       for(int j = 0 ; j < (getNumberOfCarsinRace() -1 -i) ; j++){
           if((*this)[j] > (*this)[j+1]){
                if(j== 0){  // swap 0 index and 1
                    Car *a = (*this).getCar(j);
                    Car *b = (*this).getCar(j+1);
                    Car *c = (*this).getCar(j+2);
                    a->addCar(c);
                    b->addCar(a);
                    head = b;
                }
                else{ //swap middle
                    Car *a = (*this).getCar(j);
                    Car *b = (*this).getCar(j+1);
                    Car *c = (*this).getCar(j+2);
                    Car *d = (*this).getCar(j-1);

                    a->addCar(c);
                    b->addCar(a);
                    d->addCar(b);
                    
                }   
           }
       }
   }       
}

Car* Race::getCar(const int car_in_position){
    Car *temp = head;
    for(int i = 0 ; i < car_in_position ; i++)
    {
        temp = temp->getNext();
        if(temp == NULL)
            break;
    }
    return temp;
}

int Race::indexOfTheFastestCar()const{ // returns index of the car which has the fastest lap in the Race
    Car *current = (*this).head;
    long fastest_laptime = 0;
    int numberOfcar = (*this).getNumberOfCars();
    int index = 0;

    if(current != NULL)
        fastest_laptime = LONG_MAX;

    for(int i = 0 ; i < numberOfcar ; i++){
        if( current->getFastestLapTime() < fastest_laptime ){
            index = i;
            fastest_laptime = current->getFastestLapTime();     
        }
        current = current->getNext();
    }
    return index;
}

void Race::setAverageLapTime(){
    this->average_laptime = Laptime(Utilizer::generateAverageLaptime());
}


void Race::setRaceName(std::string race_name){
    this->race_name = race_name;
}

int Race::getNumberOfCars()const{
    Car *current = head;
    int numberOfCars = 0;
    
    while(current != NULL){
        numberOfCars++;
        current = current->getNext();
    }
    return numberOfCars;
}