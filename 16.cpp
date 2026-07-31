#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find maximum sum of subarrays and print the subarray having maximum sum
    int maxSubArray(vector<int>& nums) {
        
        long long maxi = LLONG_MIN;

        long long sum = 0;

        int start = 0;

        int AnsStart = -1, AnsEnd = -1;

        for(int i = 0 ; i < nums.size() ; i++){
            if(sum == 0){
                start = i;
            }

            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
                AnsEnd = i;
                AnsStart = start;
            }

            if(sum < 0){
                sum = 0;
            }
        }


        
        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = AnsStart; i <= AnsEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;
        
        // Return the maximum subarray sum found
        return maxi;
    }
};

int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    
    // Create an instance of Solution class
    Solution sol;

    int maxSum = sol.maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}