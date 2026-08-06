#include <iostream>
#include <vector>
using namespace std;

class FloorAndCeil{
    public:
        int floor(vector<int> nums, int x){
            int high = nums.size() - 1;
            int low = 0;
            int ans = -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(nums[mid] <= x){
                    ans = nums[mid];
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            return ans;
        }

        int ceil(vector<int> nums, int x){
            int high = nums.size() - 1;
            int low = 0;
            int ans = -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(nums[mid] >= x){
                    ans = nums[mid];
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            return ans;
        }

        pair <int, int> get_floor_and_ceil(vector <int> nums, int x){
            int f = floor(nums, x);
            int c = ceil(nums, x);
            return make_pair(f,c);
        }
};

int main(){
    vector <int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5 ;
    FloorAndCeil Finder;
    pair<int , int> ans = Finder.get_floor_and_ceil(nums, x);
    cout << "The floor and ceiling is: " << ans.first << " " << ans.second << endl;
    return 0;
}