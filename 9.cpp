#include <iostream>
using namespace std;
class solution{
    public:
    int find_absent(int arr[], int n){
      
        int min = arr[0];
        int max = arr[n-1];
        for(int i = 0; i < n ;i++){
            if(arr[i] < min){
                min = arr[i];
            }
            if(max < arr[i]){
                max = arr[i];
            }
        }
        int expected_sum = 0;
        int real_sum = 0;
        for(int x = 0; x < n ; x++){
            real_sum += arr[x];
        }
        for(int x = min; x <= max; x++){
            expected_sum += x;
        }
        return expected_sum - real_sum;
    }
};
int main(){
    int arr[] = {20001, 20002, 20003, 20004, 20005, 20006, 20007, 20009};
    int n = sizeof(arr)/sizeof(int);
    solution sol;
    int missing = sol.find_absent(arr,n);
    cout << "The missing element is : " << missing << endl;
    return 0;
}