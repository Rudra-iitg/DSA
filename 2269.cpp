#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int x ,k;
        cin >> x >> k;
        int initial = 1;
        for(int i = 1; i <= x-k+1 ; i++){
            initial *= 2;
        }
        for(int i = 1; i <= k - 1; i++){
            initial += 2;
        }
        cout << initial << endl;
    }
    return 0;
}