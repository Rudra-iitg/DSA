#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    vector<int> arr(m,0);
    for(int &x : arr){
        cin >> x;
    }
    sort(arr.begin(), arr.end());
    int min_dif = INT_MAX;
    for(int i = 0; i < m - n + 1; i++){
        min_dif = min(min_dif , arr[i+n-1] - arr[i]);
    }
    cout << min_dif << endl;
    return 0;
}