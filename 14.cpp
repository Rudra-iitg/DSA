#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sol {
public:
    int max_sum(vector<int> &arr, int k) {
        int n = arr.size();
        int maxLen = 0;
// BRUTE FORCE
        for (int i = 0; i < n; i++) {           // Start index
            for (int j = i; j < n; j++) {       // End index
                int currentSum = 0;
                for (int f = i; f <= j; f++) {  // Calculate sum
                    currentSum += arr[f];       // Fixed: arr[f] not arr[i]
                }
                if (currentSum == k) {          // Fixed: == not =
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        // int left = 0, right = 0;
        // int sum = arr[0];

        // while(right < n){
        //     while(left <= right && sum > k){
        //         sum -= arr[left];
        //         left++;
        //     }
        //     if (sum == k) {          
        //         maxLen = max(maxLen, right - left + 1);
        //     }
        //     right++;
        //     if(right < n ) sum += arr[right];
        // }
        return maxLen;
    }
};

int main() {
    vector<int> vec = {-1, 1, 1};
    int sum = 2;
    Sol Ans;
    int k = Ans.max_sum(vec, sum);
    cout << "The maximum length is " << k << endl;
    return 0;
}