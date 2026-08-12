#include <iostream>
#include <string>
// #include <cctype>
// using namespace std;
// int main(){
//     string str1;
//     string str2;
//     cin >> str1 >> str2;
//     for (char &c : str1){
//         c = toupper(c);
//     }
//     for (char &c : str2){
//         c = toupper(c);
//     }
//     for(int i = 0 ; i < str1.size(); i++){
//         if(str1[i] == str2[i]){
//             if(i == str2.size() - 1){
//                 cout << 0;
//                 break;
//             }
//             else{
//                 continue;
//             }    
//         }
//         else if(str1[i] < str2[i]){
//             cout << -1;
//             break;
//         }
//         else{
//             cout << 1;
//             break;
//         }
//     }
//     return 0;
// }

// +++++++++++++734A==================
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string st;
    cin >> n;
    cin >> st;
    int a = 0, d = 0;
    for(int i = 0 ; i < n; i++){
        if(st[i] == 'A') a++;
        else d++;
    }
    if(a > d){
        cout << "Anton";
    }
    else if(d > a){
        cout << "Danik";
    }
    else {
        cout << "Friendship";
    }
    return 0;
}