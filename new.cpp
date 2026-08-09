#include <iostream>
using namespace std;
 
int main(){
    int k = 0;
    int n = 0;
    int w = 0;
    cin >> k >> n >> w;
    int total_cost = 0;
    for(int x = 1; x <= w; x++){
        k *= x;
        total_cost += k;
    }
    if(n >= total_cost) cout << 0;
    else cout << total_cost - n;
    return 0;
}