#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int a , b;
        string a1, b1;
        cin >> a >> b >> a1 >> b1;
        int count = 0;
        for(int i = 0; i < 6 ; i++){
            if(a1.find(b1) != string::npos){
                break;
            }
            a1 += a1;
            count++;
        }
        if(count == 6) cout << -1 << endl;
        else cout << count << endl;
    }
    return 0;
}