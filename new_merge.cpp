#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    while(right <= high){
        temp.push_back(arr[right++]);
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}
void mergesort(vector<int> &arr , int low, int high){
    if(low >= high) return ;

    int mid = low + (high - low)/2;
    mergesort(arr, low , mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low , mid , high);
}

int main(){
    vector<int> nums = {3, 1,5,3,7,5,12,8,5,9,3,34,21,14,97,54,61,2,63,8517,26};
    int n = nums.size() - 1 ;
    mergesort(nums, 0, n);
    for(int x : nums){
        cout << x << "  ";
    }
    cout << endl;
    return 0;
}