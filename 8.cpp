#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    vector<int> move_zeros(vector<int> &arr, int n){
        vector<int> temp(n,0);
        int index = 0;
        for(int i = 0 ; i < n; i++){
            if(arr[i] != 0){
                temp[index] = arr[i];
                index++;
            }
        }
        for(int i = 0; i < n; i++){
            arr[i] = temp[i];
        }
        return arr;
    }
};
int main(){
    // Print all the zeroes on the last of the array;
    vector<int> arr = {3, 0 ,5, 7,0, 3, 5,2,7,0,4};
    int n = arr.size();
    cout << "Array before moving zeros: ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    Solution sol;
    vector<int> result = sol.move_zeros(arr, n);
    cout << "Array after moving zeros: ";
    for(int i = 0 ; i < n ; i++){
        cout << result[i] << "  ";
    }
    cout << endl;
    return 0;
}