#include <iostream>
using namespace std;

class vehicle{
    protected:
        string name;
    public:
        
        string model;
        int noOfTyre; 
        
        vehicle(string name, string model, int noOfTyre){
            cout << "I am inside vehicle constructor" << endl;
            this -> name = name;
            this -> model = model;
            this -> noOfTyre = noOfTyre;
        }

    public:
        void start_engine(){
            cout << "Engene is starting " << name << " " << model << endl;
        }
        void stop_engine(){
            cout << "Engene is stopping " << name << " " << model << endl;
        }
};

class car: public vehicle{
    public:
        int noOfDoors;
        string transmission;

        car(string name, string model, int noOfTyre, int noOfDoors, string transmission)
        : vehicle(name, model, noOfTyre){
            cout << "I am inside car constructor" << endl;
            this -> noOfDoors = noOfDoors;
            this -> transmission = transmission;
        }
        
        void startAC(){
            cout << "AC has started of " << name << endl;
        }
};

int main(){
    car A("Maruti", "600", 4, 4, "Manual");
    A.start_engine();
    return 0;
}