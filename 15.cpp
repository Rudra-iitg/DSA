#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<int> sort( vector<int> arr, int n ){
            int count0 = 0, count1 = 0, count2 = 0;
            for(int i = 0; i < n ; i++){
                if(arr[i] == 0) count0++;
                else if(arr[i] == 1) count1++;
                else count2++;
            }

            for(int i = 0 ; i < n ; i++){
                if(i < count0){
                    arr[i] = 0;
                }
                else if(i >= count0 && i < count0 + count1){
                    arr[i] = 1;
                }
                else{
                    arr[i] = 2;
                }

            }
            return arr;
        }

};

int main(){
    vector<int> A = {1, 0 ,1, 1, 2, 0, 2, 2, 1, 0};
    int n = A.size();

    cout << "Array befor sorting" << endl;
    for(int x : A){
        cout << x << "\t";
        }
    cout << endl;
    cout << "ARRAY AFTER SORTING" << endl;
    Solution S;
    vector<int> new_arr = S.sort(A, n);
    for(int x : new_arr){
        cout << x << "\t";
    }
    cout << endl;
    return 0;
}