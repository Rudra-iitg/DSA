#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int group = 0;
    int first_mag ;
    int second_mag = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> first_mag;
        if(first_mag != second_mag) group++;
        second_mag = first_mag;
    }
    cout << group;
    return 0;
}
