#include <iostream>
using namespace std;
int main(){
    int k , r;
    cin >> k >> r;
    int var = k;
    for(int i = 1; i <= 10; i++){
        if(k % 10 == 0 || k % 10 == r ) break;
        k += var;    
    }
    cout << k/var;
    return 0;
}