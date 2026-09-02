#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    string st;
    getline(cin,st);
    int n = st.size();
    set<char> letters;
    for(char x : st){
        if(x == '{' || x == '}' || x == ',' || x == ' '){
            continue;
        }
        else{
            letters.insert(x);
        }
    }
    cout << letters.size();
    return 0;
}