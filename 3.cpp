#include <iostream>
using namespace std;

class vehicle{
    protected:
        string name;
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
        ~vehicle(){
            cout << "I am inside vehicle Distructor" << endl;
        }
};

class car: public vehicle{
    protected:
        int noOfDoors;
        string transmission;
    public:
        car(string name, string model, int noOfTyre, int noOfDoors, string transmission)
        : vehicle(name, model, noOfTyre){
            cout << "I am inside car constructor" << endl;
            this -> noOfDoors = noOfDoors;
            this -> transmission = transmission;
        }
        
        void startAC(){
            cout << "AC has started of " << name << endl;
        }
        ~car(){
            cout << "I am inside car Distructor" << endl;
        }
};

class motorcycle: public vehicle{
    protected:
        string handleType;
        string suspesnionType;
    public:
        motorcycle(string _name, string _model, int _noOfTyre, string _handleType, string _suspensionType)
        : vehicle(_name, _model, _noOfTyre){
            cout << "Motorcycle Constructor called" << endl;
            this -> handleType = _handleType;
            this -> suspesnionType = _suspensionType;
        }
        void wheelie(){
            cout << "The " << name << " is doing wheelie" << endl;
        }
        ~motorcycle(){
            cout << "I am inside motorcycle Distructor" << endl;
        }
};

int main(){
    car A("Maruti", "600", 4, 4, "Manual");
    A.start_engine();
    A.startAC();
    A.stop_engine();

    motorcycle M("Bullet", "450", 2, "High", "Long");
    M.start_engine();
    M.wheelie();
    M.stop_engine();
    return 0;
}