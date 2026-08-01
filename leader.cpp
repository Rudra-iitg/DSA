#include <iostream> 
#include <vector>
#include <climits>
using namespace std;

class Solution{
    public:
        void leader(vector <int> nums){
            vector<int> ans;
            int n = nums.size();
            //===================== BTUTE FORCE METHOD==================
            // for(int i = 0; i < n - 1; i++){
            //     bool isleader = true;
            //     for(int j = i + 1; j < n ; j++ ){
            //         if(nums[i] <= nums[j]){
            //             isleader = false;
            //             break;
            //         }
            //     }
            //     if(isleader){
            //         ans.push_back(nums[i]);
            //     }
            // }
            // ans.push_back(nums[n-1]);
            //
            //====================OPTIMAL METHOD===============
            int max_from_right = INT_MIN;
            for(int i = n - 1; i >= 0; i--){
                if(nums[i] >= max_from_right){
                    ans.push_back(nums[i]);
                    max_from_right = nums[i];
                }
            }
            reverse(ans.begin(), ans.end());
            for(int x : ans){
                cout << x << "\t";
            }
        }

};
int main(){
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    Solution sol;
    sol.leader(arr);
    cout << endl;
    return 0;
}