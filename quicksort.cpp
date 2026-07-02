#include <iostream>
using namespace std;
class sorting{
    public:
    void quicksort(vector<int> & array, int low, int high){
        if(low < high){
            int pivotindex = partitiions(array, low, high);
            quicksort(array, low, pivotindex - 1);
            quicksort(array, pivotindex + 1, high);
        }
    }

    int partitiions(vector<int> & array, int low, int high){
        int pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++){
            if(array[j] <= pivot){
                i++;
                swap(array[i],array[j]);
            }
        }
        swap(array[i + 1], array[high]);
        return i + 1;
    }

};

int main(){
    vector<int>arr = {23, 42,11, 32,1, 2, 54,26, 79, 45,67, 55};
    cout << "Elements before sorting: ";
    for( int x : arr){
        cout << x << '\t';
    }
    cout << endl;
    cout << "Array after sorting: ";
    sorting sort;
    sort.quicksort(arr, 0 , arr.size()-1);
    for(int x : arr){
        cout << x << '\t';
    }
    cout << endl;
    return 0;

}