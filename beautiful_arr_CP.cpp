#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int beautiful_arr(int row, int col){
    int count = 0;
    if(row != 3){
        count += abs(row - 3);
    }
    else if(col != 3){
        count += abs(col - 3);
    }
    else{
        return count;
    };
    return count;
}

int main(){
    vector<vector<int>> arr;
    arr.resize(5, vector<int>(5));
    int row;
    int col;
    cout << "enter the nums: ";
    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                row = i + 1;
                col = j + 1;
            }
        }
    }
    cout << endl;
    cout << " Input Array:" << endl;
    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j < 5; j++){
            cout <<  arr[i][j] << '\t';
        }
        cout << endl;
    }
    int ans = beautiful_arr( row, col);
    cout << "The number of steps required: " << ans << endl;
    return 0;
}