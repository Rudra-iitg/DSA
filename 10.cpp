#include <iostream>
#include <vector>
using namespace std;
class solution{
    public:
    vector<int> union_set(int arr1[], int arr2[], int n , int m){
        vector<int> new_union;
        int  i = 0, j = 0;

        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                if(new_union.empty() || new_union.back() != arr1[i]){
                    new_union.push_back(arr1[i]);
                }
                i++;
            }
            else if(arr1[i] > arr2[j]){
                if(new_union.empty() || new_union.back() != arr2[j]){
                    new_union.push_back(arr2[j]);
                }
                j++;
            }
            else{
                if(new_union.empty() || new_union.back() != arr1[i]){
                    new_union.push_back(arr1[i]);
                }
                i++; j++;
            }
        }
        while (i < n){
            if(new_union.empty() || new_union.back() != arr1[i]){
                new_union.push_back(arr1[i]);
            }
            i++;
        }
        while (j < m){
            if(new_union.empty() || new_union.back() != arr2[j]){
                new_union.push_back(arr2[j]);
            }
            j++;
        }
        return new_union;
    }
};
int main(){
    int arr1[] = {1,2,3,4,5} ;
    int n = sizeof(arr1)/sizeof(int);
    int arr2[] = {2,4, 4, 5, 6,8};
    int m = sizeof(arr2)/sizeof(int);
    solution sol;
    
    cout << "Union of these two arrays: " ;
    vector<int> all_union = sol.union_set(arr1,arr2, n, m);
    for(int x : all_union){
        cout << x << "  ";
    }
    cout << endl;
    return 0;
}
