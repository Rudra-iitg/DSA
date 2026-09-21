#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a, b , c , d;
    cin >> a >> b >> c >> d;
    int max1 = max({a , b , c , d});
    if(a != max1) cout << max1 - a << " ";
    
    if(b != max1) cout << max1 - b << " ";
    if(c != max1) cout << max1 - c << " ";
    if(d != max1) cout << max1- d << " ";
    return 0;
}