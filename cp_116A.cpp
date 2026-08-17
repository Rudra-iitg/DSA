#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int current_pass = 0;
    int max_pass = 0;
    for(int i = 0 ; i < n ; i++){
        int exit , enter;
        cin >> exit >> enter;
        current_pass -= exit;
        current_pass += enter;
        max_pass = max(max_pass, current_pass);
    }
    cout << max_pass;
    return 0;
}