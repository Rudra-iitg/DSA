#include <iostream>
#include <string>
using namespace std;
int main(){
    string st;
    cin >> st;
    int n = st.length();
    int i = 0;
    while(i < n){
        if(st[i] == 'W' && st[i+1] == 'U' && st[i+2] == 'B'){
            i += 3;
        }
        else{
            cout << st[i];
            i++;
            if(st[i] == 'W' && st[i+1] == 'U' && st[i+2] == 'B' && i != n-3){
                cout << " ";
            }
        }
    }
    return 0;
}