#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    int give_index(vector<int> arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == target){
                return mid;
            }
            if(arr[low] <= arr[mid]){
                if(arr[low] <= target && arr[mid] >= target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(arr[mid] <= target && arr[high] >= target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector <int> arr = {4, 5, 6, 7, 0, 1, 2};
    Solution sol;
    int ans = sol.give_index(arr, 1);
    cout << "The element 1 is present at the index : " << ans << endl;
    return 0;
}