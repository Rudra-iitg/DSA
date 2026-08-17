#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {4,64,43,7,23,64,7};
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        if(*it > 10){
            cout << *it << "  ";
        }
    }
    cout << endl;
    return 0;
}