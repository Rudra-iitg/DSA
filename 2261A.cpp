#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        string st;
        cin >> st;
        int p = 0;
        int q = 0;
        for(int i = 0; i < a; i++){
            if(st[i] == '1'){
                p = i+1;
                break;
            }
            else continue;
        }
        for(int i = a-1; i >= 0; i--){
            if(st[i] == '1'){
                q = i+1;
                break;
            }
            else continue;
        }
        cout << q - p << endl;
    }
    return 0;
}