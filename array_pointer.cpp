#include <iostream>
using namespace std;
int main(){
    int C[3][2][2] = {{{4,6},{23,5}},
                      {{22,7},{11,34}},
                      {{41,53},{21,5}}};
    cout << C << endl;
    cout << *C[0] << endl;
    int (*p)[2][2] = C;
    cout << p << endl;
    cout << *(C[0][1] + 1) << endl;
    cout << *(*(C[1] + 1 + 2)) << endl;
    cout << &C[1][1][0] << endl;
    cout << endl;
    return 0;
}