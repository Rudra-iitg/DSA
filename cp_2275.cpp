#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int x , y , r;
        cin >> x >> y >> r;
        int x1 = 0;
        int y1 = 0;
        double dist = 0;
        bool flag = true;
        while(dist <= r){
            dist = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
            if(flag == true){
                x1++;
                flag = false;
            }
            else{
                y1++;
                flag = true;
            }
        }
        cout << x1 << " " << y1 << endl;
    }
    return 0;
}