#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n ; i++){
        int a;
        cin >> a;
        int count  = 0;
        vector<int> arr;
        int power = 1;
        while(a > 0){
            
            if( a % 10 != 0){
                int b = (a % 10) * power;
                arr.push_back(b);
                power *= 10;
                count++;
                a/=10;
            }
            else{
                a /= 10;
                power *= 10;
            }
        }
        cout << count << endl;
        for(int x : arr){
            cout << x << "\t";
        }
        cout << endl;
    }
    return 0;
}