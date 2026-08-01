#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
        void new_arr(vector<int> &nums){
            
            //BRUTE FORCE METHOD
            //vector<int> new_arr(vector<int> &nums){
            // int n = nums.size();
            // vector <vector<int>> all ;
            // sort(nums.begin(), nums.end());
            // do{
            //     all.push_back(nums);
            // }while(next_permutation(nums.begin(),nums.end()));
            // for(int i = 0; i < all.size(); i++){
            //     if(all[i] == nums){
            //         if(i == all.size() - 1){
            //             return all[0];
            //         }
            //         return all[i+1];
            //     }
            // }

            //======================OPTIMAL APPROACH================
            int index = -1;
            for(int i = nums.size() - 2; i >= 0; i--){
                if(nums[i] < nums[i+1]){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                reverse(nums.begin(), nums.end());
                return;
            }
            for(int i = nums.size() -1; i > index ; i--){
                if(nums[i] > nums[index]){
                    swap(nums[i], nums[index]);
                    break;
                }
            }
            reverse(nums.begin() + index + 1, nums.end());
        }
};
int main(){
    vector<int> arr = {3,1,2};
    Solution sol;
    sol.new_arr(arr);
    cout << "The next permutation" << endl;
    for(int x : arr) cout << x << "\t";
    return 0;
}