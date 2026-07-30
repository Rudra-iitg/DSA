#include <iostream>
using namespace std;

class Shallow{
    int *id;
    Shallow(int n){
        cout << "Shallow constructor called;" << endl;
        id = new int (n);
    }
    ~Shallow(){
        cout << "Shallow Distructor called" << endl;
        delete id;
    }
};

int main(){

    Shallow Sh(5);

    return 0;
}