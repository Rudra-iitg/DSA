#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    int sum = 0;
    for(int &x : arr){
        cin >> x;
        sum += x;
    }
    int sum1 = 0;
    int count = 0;
    sort(arr.begin(), arr.end());
    for(int i = n-1 ; i >= 0; i--){
        sum1 += arr[i];
        count++;
        if(sum1 > sum - sum1){
            cout << count << endl;
            break;
        }
    }
    return 0;
}