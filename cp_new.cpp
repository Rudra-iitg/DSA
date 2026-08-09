#include <iostream>
#include <string>
using namespace std;

int main(){
    string st;
    cin >> st;
    if(st.size() == 1){
        cout << st;
        return 0;
    }
    for(int i = st.size() - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(st[j] == '+'){
                continue;
            }
            else{
                if((int)st[j] > (int)st[j + 2]){
                swap(st[j], st[j + 2]);
                }
            }            
        }
    }
    cout << st;
    return 0;
}