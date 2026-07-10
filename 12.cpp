#include <iostream>
using namespace std;
int main(){
    float numa = 12.0;
    
    int numb = 23;

    int sum = static_cast<int>(numa) + numb;
    cout << sum;
    return 0;
}