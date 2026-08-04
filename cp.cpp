#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string str1;
    string str2;
    cin >> str1 >> str2;
    for (char &c : str1){
        c = toupper(c);
    }
    for (char &c : str2){
        c = toupper(c);
    }
    for(int i = 0 ; i < str1.size(); i++){
        if(str1[i] == str2[i]){
            if(i == str2.size() - 1){
                cout << 0;
                break;
            }
            else{
                continue;
            }    
        }
        else if(str1[i] < str2[i]){
            cout << -1;
            break;
        }
        else{
            cout << 1;
            break;
        }
    }
    return 0;
}