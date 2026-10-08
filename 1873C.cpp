#include <iostream>
using namespace std;
int points(int a , int b){
    if((a == 0 || a == 9) || (b == 0 || b == 9)){
        return 1;
    }
    else if((a == 1 || a == 8) ||(b == 1 || b == 8)){
        return 2;
    }
    else if((a == 2 || a == 7) ||(b == 2 || b == 7)){
        return 3;
    }
    else if((a == 3 || a == 6) ||(b == 3 || b == 6)){
        return 4;
    }
    else{
        return 5;
    }
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int a = 10;
        vector<string> v(10,"");
        for(string &x : v){
            cin >> x;
        }
        int total = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                string st = v[i];
                if(st[j] == 'X'){
                    total += points(i, j);
                }
            }
        }
        cout << total << endl;
    }
    return 0;
}