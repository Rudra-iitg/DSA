#include <iostream>
using namespace std;
int main(){
    cout << "=============TABLE===============\n";
    cout << "Enter a number: ";
    int x ;
    cin >> x;
    for(int i = 1; i <= 10000; i++){
        cout << x << " * " << i << " = " << x * i << endl;
    }
    return 0;
}