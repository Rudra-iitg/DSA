#include <iostream>
#include <vector>
using namespace std;
class hash_new{
    public:
    int max_ele(int arr[], int n){
        int max = arr[0];
        for(int i = 1 ; i < n; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }
    void hash_map(int arr[], int max, int n){
        vector<int> hash(max + 1, 0);
        for(int i = 0; i < n; i++){
            hash[arr[i]]++; 
        }
        cout << endl;
        for(int i = 0; i < max + 1; i++){
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < max+1; i++){
            cout << hash[i] << " ";
        } 
        cout << '\n';
    }
};
using namespace std;
int main(){
    int arr[] = {3, 5,2,5,2,8,6,9,0,3,8,3,6,2,5,4,9,1,1,3,2,1,2,8,6};
    int n = sizeof(arr)/sizeof(int);
    hash_new hs;
    int max = hs.max_ele(arr, n);
    hs.hash_map(arr, max, n);
    return 0;
}