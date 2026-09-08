#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        long long a;
        cin >> a;
        if(a % 2 == 0) cout << (a/2)-1;
        else cout << a/2;
    }
    return 0;
}