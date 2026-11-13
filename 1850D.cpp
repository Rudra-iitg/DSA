#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n,0);
        for(int &x : arr){
            cin >> x;
        }
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        sort(arr.begin(), arr.end());
        int a = 1;
        int maxx = 1;
        for(int i = 0; i < n-1; i++){
            if(arr[i+1]- arr[i] <= k){
                a++;
                maxx = max(a, maxx);
            }
            else{
                maxx = max(a, maxx);
                a=1;
            }
        }
        cout << n-maxx << endl;
    }
    return 0;
}