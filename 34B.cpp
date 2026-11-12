#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n  >> m;
    vector<int> nums;
    for(int i = 0; i < n ; i++){
        int a;
        cin >> a;
        if(a < 0) nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    int s = nums.size();
    long long sum = 0;
    for(int i = 0; i < s && i < m; i++){
        sum += -nums[i];
    }
    cout << sum << endl;
    return 0;
} 
