#include <iostream>
using namespace std;

class Animal{
    public:
        string name;
        void eat(){
            cout << name << " is eating. " << endl;
        }
        Animal(string n) : name(n){
            cout << "Animal Constructed. " << endl;
        }
        virtual void speak(){
            cout << " Some Random sound. " << endl;
        }
        virtual ~Animal(){
            cout << "Animal Destroyed. " << endl;
        }
    protected:
        int age;
    private:
        string secretID;
};


class Swimmer : virtual public Animal{
    public:
        Swimmer(string n = "") : Animal(n) {}
        void swim(){
            cout << "It can swim. " << endl;
        }
};
class Runner: virtual public Animal{
    public:
        Runner(string n = "") : Animal(n) {}
        void run(){
            cout << "It can run. " << endl;
        }
};
class Dog : public Swimmer , public Runner{
    public:
        void bark(){
            cout << name << " is  barking." << endl;
        }
        void birthday(){
            age++;
        }
        void speak() override {
            cout << " woof " << endl;
        } 
        Dog (string n) : Animal(n){
            cout << " Dog Cosntructor." << endl;       
        }
        ~Dog(){
            cout << "Dog Destroyed." << endl;
        }
};
int main(){
    Dog german("German Shephard");
    german.speak();
    return 0;
}