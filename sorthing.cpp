#include <iostream>
#include <vector>
using namespace std;

class sorting{
    public:
    void selection_sort(int n , int array[]){
        for(int i = 0; i < n -1 ; i++){
            int min = i;
            for(int j = i +1; j < n; j++){
                if(array[j] < array[min]){
                    min = j;
                }
            }
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
            }
        for(int z = 0 ; z < n ; z++){
            cout << array[z] << "  " ;
        }
    }
    void bubble_sort(int n, vector<int> &array1){
        for(int i = n -1 ; i >=0 ; i--){
            int did_swap = 0;
            for(int j = 0 ; j < i; j++){
                if(array1[j] > array1[j+1]){
                    swap(array1[j], array1[j+1]);
                    did_swap = 1;
                }
            }
            if(did_swap == 0){
                break;
            }
        }
        for(int z = 0 ; z < n ; z++){
            cout << array1[z] << "  " ;
        }
    }
    void insertion_sort(int arr[], int n){
        for (int i = 0; i < n ; i++){
            int j = i;
            while(j > 0 && arr[j - 1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;

                j--;
            }
        }
        for(int z = 0 ; z < n ; z++){
            cout << arr[z] << "  " ;
        }
    }
};

int main(){
    int arr[] = {34, 23,54,11,87,33, 59,43,73,26,77};
    int n = sizeof(arr)/sizeof(int);
    vector<int> bubble_array;
    for(int i = 0 ; i < n; i++){
        bubble_array.push_back(arr[i]);
    }
    cout << "Array before sorting : ";
    for(int x : arr){
        cout << x << "  ";
    }
    cout << endl;
    
    sorting sort;
    cout << "array after selection sorthing: "  << '\t';
    sort.selection_sort(n, arr);
    cout << endl;
    cout << "Array after bubble_sort: " << '\t';
    sort.bubble_sort(n, bubble_array);
    cout << endl;
    cout << " Array after insertion sort: " << '\t';
    sort.insertion_sort(arr, n);
    return 0;
}