#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string st;
    cin >> st;
    int length = st.length();
    for(int i = 0 ; i < length ; i++){
        int count = 0;
        for(int j = 0; j < length ; j++){
            if(st[j] == st[i]) {
                count ++;
            }
        }
        length = length - count + 1;
    }
    if(length % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    }
    else{
        cout << "IGNORE HIM!" << endl;
    }
    return 0;
}