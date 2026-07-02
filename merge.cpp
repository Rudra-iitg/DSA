#include <iostream>
#include <vector>
using namespace std;

class Sort{
    public:
    void merge(vector<int> &arr, int low , int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            } 
            else {
                temp.push_back(arr[right++]);
            }
        }
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= high){
            temp.push_back(arr[right++]);
        }
        // Copy sorted values back to original array
        for(int i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }
    }


    void mergesort(vector<int> &arr, int low, int high){
        if(low >= high) return;

        int mid = (low + high) / 2;

        mergesort(arr, low , mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
};


int main(){
    vector<int> array = { 32, 43,21,52, 2, 31, 14, 53, 66, 34,76,16};
    int n = array.size();
    Sort sort;
    sort.mergesort(array, 0 , n-1);
    for (int x : array){
        cout << x << "  ";
    }
    cout << endl;
    return 0;
}
