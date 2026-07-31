#include <iostream>
#include <vector>

using namespace std;

// class Solution{
//     public:
//     void arr_sort(vector <int>& arr){
//         int n = arr.size();
//         vector<int> pos_arr, neg_arr;
//         for(int x = 0 ; x < n; x++){
//             if(arr[x] > 0){
//                 pos_arr.push_back(arr[x]);
//             }
//             else{
//                 neg_arr.push_back(arr[x]);
//             }
//         }
//         for(int i = 0; i < n/2 ; i++){
//             arr[i * 2] = pos_arr[i];
//             arr[( i * 2 ) + 1] = neg_arr[i];
//             }
//         for(int x : arr){
//             cout << x << "\t";
//         }
//     }
// };
// int main(){
//     vector<int> arr = { 4, -3, 5, 8, -2, 6, -11, -7 };
//     Solution Sol;
//     cout << "Array before sorting" << endl;
//     for(int x : arr){
//         cout << x << "\t";
//     }
//     cout << endl;
//     cout << "Array after sorting: " << endl;
//     Sol.arr_sort(arr);
//     return 0;
// }

// ==========OPTIMAL APPROACH================
class Solution{
    public:
    vector<int> arr_sort(vector<int> &arr){
        int n = arr.size();
        int pos_idx = 0, neg_idx = 1;
        vector<int> new_arr(n,0);
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                new_arr[pos_idx] = arr[i];
                pos_idx += 2;
            }
            else{
                new_arr[neg_idx] = arr[i];
                neg_idx += 2;
            }
        }
        return new_arr;
    }
};
int main(){
    vector<int> arr = { 4, -3, 5, 8, -2, 6, -11, -7 };
    Solution Sol;
    cout << "Array before sorting" << endl;
    for(int x : arr){
        cout << x << "\t";
    }
    cout << endl;
    vector <int> ans_arr = Sol.arr_sort(arr);
    cout << "Array after sorting:" << endl;
    for(int x : ans_arr){
        cout << x << "\t";
    }
    cout << endl;
    return 0;
}