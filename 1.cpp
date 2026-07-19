#include <iostream>
using namespace std;

class student{
    public:
    int id;
    int age;
    string name;
    int num;

    //constructor
    // student(){
    //     cout << "Student deflault constructor called\n";
    // }
    //PARAMATERISED CONSTRUCTOR
    student(int id, int age, string name, int num){
        cout << "Student deflault constructor called\n";
        this -> id = id;
        this -> age = age;
        this -> name = name;
        this -> num = num;
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
    // student A;
    // A.age = 15;
    // A.id = 001;
    // A.name = "Dhanush"; 
    // A.study();
    // student B;
    // B.age = 135;
    // B.id = 002;
    // B.name = "Anand"; 
    // A.sleep();
    student A(1, 5, "Keshab", 4);
    student B(4, 6, "Rishab", 4);
    student C(9, 11, "Sahab", 4);
    student D(7, 11, "Rakshab", 4);
    cout << A.name << " " << A.age << endl;
    A.sleep();
    B.study();
    return 0;
}