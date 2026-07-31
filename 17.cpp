#include <iostream>
using namespace std;

class Solution{
    public:
    int profit(vector<int> arr){
        // int profit = 0;
        // int n = arr.size();
        // for(int i = 0; i < n-1; i++ ){
        //     for(int j = i + 1; j < n; j++){
        //         if(arr[j] - arr[i] > profit){
        //             profit = arr[j] - arr[i];
        //         }
        //     }
        // }

        //=========OPTIMAL APPROACH============
        int min_price = INT_MAX;
        int max_profit = 0;
        for(int price:arr){
            if(price < min_price){
                min_price = price;
            }
            else{
                max_profit = max(max_profit, price - min_price);
            }
        }
        return max_profit;
    }
};

int main(){
    vector<int> arr = {7,6,4,3,1};
    Solution sol;
    cout << "The maximum profit that can be made: " << sol. profit(arr) << endl;
    return 0;
}