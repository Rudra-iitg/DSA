#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<int> arr(4, 0);
    for(int &x : arr){
        cin >> x;
    }
    string st;
    cin >> st;
    int count = 0;
    for(char x : st){
        count += arr[x - '0' - 1];
       }
    cout << count << endl;
    return 0;
}