#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int n ; 
    cin >> n;
    vector<int> solder(n);
    int min_height = INT_MAX;
    int min_i = 0;
    int max_i = n - 1;
    int max_height = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        cin >> solder[i];
        if(solder[i] <= min_height) min_height = solder[i], min_i = i;
        if(solder[i] >= max_height) max_height = solder[i], max_i = i;
    }
    if(min_i > max_i){
        cout << max_i + (n-1 - min_i);
    }
    else{
        cout << max_i + (n - 1 - min_i) - 1;
    }
    return 0;
}