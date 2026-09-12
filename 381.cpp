#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> input(n, 0);
    for(int x = 0; x < n ; x++){
        cin >> input[x];
    }
    int i = 0;
    int j = n-1;
    int counter = 0;
    int s = 0;
    int d = 0;
    while(n--){
        if(input[i] > input[j]){
            if(counter % 2 == 0) {
                s += input[i];
                i++;
                counter++;
            }
            else{
                d += input[i];
                i++;
                counter++;
            }
        }
        else{
            if(counter % 2 == 0) {
                s += input[j];
                j--;
                counter++;
            }
            else{
                d += input[j];
                j--;
                counter++;
            }
        }
    }
    cout << s << " " << d << endl;
    return 0;
}