#include <iostream>
using namespace std;
class Solution{
    public:
    void left_rotate(int arr[], int n){
        // BRUTE FORCE METHOD;
        int temp = arr[0];
        for(int i = 0; i < n - 1; i++){
            arr[i] = arr[i+1];
        }
        arr[n-1] = temp;
        for(int i = 0; i < n ; i++){
            cout << arr[i] << "  ";
        } 
    }
};

int main(){
    int array[] = { 3, 4, 5, -1, 34, 0};
    int n = sizeof(array)/sizeof(int);
    Solution sol;
    
    cout << "Array before rotation : " ;
    for(int i = 0; i < n ; i++){
        cout << array[i] << "  ";
    } 
    cout << endl;
    cout << "Array after roataion: ";
    sol.left_rotate(array,n);
    cout << endl;
    return 0;
}