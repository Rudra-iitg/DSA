#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n ;
    cin >> n;
    vector<int> record (n,0);
    for(int x = 0; x < n ; x++){
        cin >> record[x];
    }
    int crime = 0;
    for(int i = n - 1; i >=0; i--){
        if(record[i] == -1) crime++;
        else {
            if(crime > record[i]) crime -= record[i];
            else {
                crime = 0;
            }
        }
    }
    cout << crime;
    return 0;
}
