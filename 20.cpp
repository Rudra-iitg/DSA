#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution{
    public:
        int longest_arr(vector<int> nums){
            int n = nums.size();
            if(n == 0){
                return 0;
            }
            int longest = 1;
            unordered_set<int> st;
            for(int i = 0; i < n ; i++){
                st.insert(nums[i]);
            }
            for(auto it : st){
                if(st.find(it-1) == st.end()){
                    int cnt = 1;
                    int x = it;

                    while(st.find(x + 1) != st.end()){
                        x += 1;
                        cnt += 1;
                    }
                    longest = max(cnt, longest);
                }
            }
            return longest;
        }
};
int main(){
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << "Given Vactor : {  ";
    for(int x : arr){
        cout << x << "  " ;
    }

    cout << "}";
    cout << endl;
    Solution Sol;
    cout << "The longest Consecutrve elemtens are: "<< Sol.longest_arr(arr)<< endl;
    return 0;
}