#include <iostream>
using namespace std;
// ===============POLYMORPHISM=============
// class Add{
//     public:
//     // //=============Function overloading=============
//     //     int sum(int x, int y){
//     //         return x + y;
//     //     }
//     //     int sum(int x, int y, int z){
//     //         return x + y + z;
//     //     }
    
// };
//===================OPERATOR OVERLOADING============
class Complex{
    public:
        int real;
        int imag;

        Complex(){
            real = imag = -1; 
        }
        Complex(int r, int i): real(r), imag(i){};
        void print(){
            cout << this -> real << " + i" << this -> imag << endl;
        }
        Complex operator+(const Complex &B){
            Complex temp;
            temp.real = this -> real + B.real;
            temp.imag = this -> imag + B.imag;
            return temp;
        }
};
int main(){
    // int x = 4, y = 43, z = 453;
    // Add A;
    // cout << A.sum(x,y) << endl;
    // cout << A.sum(x , y ,z);
    // return 0;
    //=================================
    Complex A(4,5);
    A.print();
    Complex B(5,7);
    B.print();
    cout << endl;

    Complex C = A + B;
    C.print();

    
    return 0;
}