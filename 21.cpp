#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public: 
    void matrix_transform(vector<vector<int>> &matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(matrix[i][j] == 0){
                    for(int col = 0; col < n ; col++){
                        if(matrix[i][col] != 0){
                            matrix[i][col] = -1;
                        }
                    }
                    for(int row = 0; row < m ;row++){
                        if(matrix[row][j] != 0){
                            matrix[row][j] = -1;
                        }
                    }
                }
            }
        }
        for(int i = 0 ; i < m ; i++){
                for(int j = 0; j < n ; j++){
                    if(matrix[i][j] == -1){
                        matrix[i][j]  = 0;
                    }  
                }
            }
    }
};
int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    cout << "Original Vactor: " << endl;
    
    for(int i = 0 ; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << "  ";
        }
    
        cout << endl;
    }
    Solution sol;
    cout << "Final vector: " << endl;
    sol.matrix_transform(matrix);
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}