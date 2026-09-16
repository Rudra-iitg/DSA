// #include <iostream>
// using namespace std;
// // void inc(int *a){
// //     *a += 1;
// // }
// int main(){
//     int a = 5;
//     inc(&a);
//     cout << a;
//     return 0;
// }
#include <iostream>
using namespace std;
void print(char *C){
    *C = 'J';
    while(*C != '\0'){
        cout << *C;
        C++;
    }
}
int main(){
    char C[10];
    C[0] = 'H';
    C[1] = 'U';
    C[2] = 'N';
    C[3] = 'G';
    C[4] = '\0';
    cout << (string)C << endl;
    char str[20] = "Hello";
    print(str);
    return 0;
}
