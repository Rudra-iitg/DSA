#include <iostream>
using namespace std;
int main(){
    int n ;
    cin >> n;
    while(n--){
        long long a;
        cin >> a;
        int count = 0;
        while(a != 1){
            if(a % 3 != 0) {
                count = -1;
                break;
            }
            if(a % 6 == 0){
                a /= 6;
                count++;
            }
            else{
                a *= 2;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}