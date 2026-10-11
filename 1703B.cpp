#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        string st;
        cin >> st;
        vector<int> arr (26, 0);
        for(int i = 0; i < a ; i++){
            arr[st[i] - 'A']++;
        }
        int count = 0;
        for(int x : arr){
            if(x != 0){
                count += x + 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}