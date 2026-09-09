#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string st1, st2;
    cin >> st1 >> st2;
    cout <<  endl;
    string ans;
    cin >> ans;
    cout <<  endl;
    vector<int> A1(26,0);
    for(char x : st1){
        A1[(int)x - 65]++;
    }
    for(char x : st2){
        A1[(int)x - 'A']++;
    }
    vector<int> A2(26,0);
    for(char x : ans){
        A2[(int)x - 'A']++;
    }
    bool okay = true;
    for(int i = 0 ; i < 26 ; i++){
        if(A1[i] == A2[i]){
            okay = true;
        }
        else{
            okay = false;
            break;
        }
    }
    if(okay == true) cout << "YES" <<  endl;
    else cout << "NO" << endl;
    return 0;
}