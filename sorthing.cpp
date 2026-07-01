#include <iostream>
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
};

int main(){
    int arr[] = {34, 23,54,11,87,33, 59,43,73,26,77};
    cout << "Array before sorting : ";
    for(int x : arr){
        cout << x << "  ";
    }
    cout << endl;
    int n = sizeof(arr)/sizeof(int);
    sorting sort;
    cout << "array after sorthing "  << " \t ";
    sort.selection_sort(n, arr);
    return 0;
}