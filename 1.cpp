#include <iostream>
using namespace std;

class student{
    public:
    int id;
    int age;
    string name;
    int num;

    //constructor
    student(){
        cout << "Student deflault constructor called\n";
    }
    void study(){
        cout << this -> name << " Studying\n ";
    }
    void sleep(){
        cout << this -> name << " Sleeping\n ";
    }

    //Distrocotr
    ~student(){
        cout << this -> name << "The defautl distructor is called\n";
    }
};

int main(){
    cout << "=========================\n";
    student A;
    A.age = 15;
    A.id = 001;
    A.name = "Dhanush"; 
    A.study();
    student B;
    B.age = 135;
    B.id = 002;
    B.name = "Anand"; 
    A.sleep();
    return 0;
}