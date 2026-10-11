#include <iostream>
#include <string>
using namespace std;
int main(){
    int n; 
    cin >> n;
    while(n--){
        string st;
        cin >> st;
        string ans = "";
        int n = st.length();
        for(int i = 0; i < n ; i+=2){
            ans.push_back(st[i]);
        }
        ans.push_back(st[n-1]);
        cout << ans << endl;
    }
    return 0;
}