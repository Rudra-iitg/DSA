#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int removeDuplicate(vector<int> &num){
        if(num.empty()) return 0;
        
        int i = 0;
        for(int j = 1; j < num.size(); j++){
            if(num[j] != num[i]){
                i++;
                num[i] = num[j];
            }
        }
        return i + 1;
    }
};

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int k = sol.removeDuplicate(nums);
    cout << "Unique coutn : " << k << '\n';
    cout << "Array after removing duplicate: " ;
    for(int i = 0; i < k ; i++){
        cout << nums[i] << "  ";
    }
    cout << endl;
    return 0;
}