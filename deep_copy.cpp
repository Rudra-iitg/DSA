#include <iostream>
using namespace std;

class Shallow{
    public:
        int *data;
        //Constructor
        Shallow(int val){
            cout << "Shallow Constructor called" << endl;
            data = new int(val);
        }
        ~Shallow(){
            cout << "Shallow Distructor called" << endl;
            delete data;
        }
};

class Deep{
    public:
        int *data;
        //Constructor
        Deep(int val){
            cout << "Deep constructor is called" << endl;
            data = new int (val);
        }
        // CUSTOM COPY CONSTRUCTOR FOR DEEP COPY
        Deep(const Deep &other){
            cout << "DEEP COPY CONSTRUCTOR IS CALLED" << endl;
            data = new int(*other.data); // CREATE NEW MEMORY AND COPY THE DATA;
        }
        ~Deep(){
            cout << "Deep copy Distructor is called" << endl;
            delete data;
        }
};

int main(){
    cout << "-------------TESTING SHALLOW COPY---------------" << endl;
    Shallow A(2);
    Shallow B = A;

    cout << "A data " << *A.data << " " << endl;
    cout << "B data " << *B.data << " " << endl;

    *A.data = 999;

    cout << "After changing the values\n";
    cout << "A data " << *A.data << " " << endl;
    cout << "B data " << *B.data << "  <<--- B data also changed" << endl;

    //===============DEEP COPY===================
    cout << "-------------TESTING DEEP COPY--------------" << endl;
    Deep d1(100);
    Deep d2 = d1; // Deep copy constructor
    cout << "d1 data " << *d1.data << endl;
    cout << "d2 data " << *d2.data << endl;
    // CHange value

    *d1.data = 420;

    cout << "After changing the deep value" << endl;
    cout << "d1 data " << *d1.data << endl;
    cout << "d2 data " << *d2.data << " <<-------- d2 is sill same as old" << endl;
    return 0;
}