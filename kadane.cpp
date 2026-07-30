#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution{
    public:
        int max_sum(vector<int> arr, int n){
            // OPTIMAL APPROACH
            // long long max_sum = LLONG_MIN;
            // long long new_sum = 0;
            // for(int i = 0; i < n ; i++){
            //     new_sum += arr[i];
            //     max_sum = max(max_sum , new_sum);
            //     if(new_sum < 0){
            //         new_sum = 0;
            //     }
            // }
            // OPTIMAL APPRACH
            //================MOST OPTIMAL APPRACH ===============
            int max_sum = arr[0], current_sum = arr[0];
            for(int i = 1; i < n ; i++){
                current_sum = max(arr[i], current_sum + arr[i]);
                max_sum = max(current_sum , max_sum);
            }
            return max_sum;
        }
};

int main(){
    vector<int> arr = {3, 5, 6, 2, -1, 0, 3, 7, 9};
    int n = arr.size();
    cout << "Given ARRAY" << endl;
    for(int x : arr){
        cout << x << "\t";
    }
    cout << endl;
    Solution A;
    int max = A.max_sum(arr, n);
    cout << "The maximum sum of the array is " << max << endl;
    return 0;
}