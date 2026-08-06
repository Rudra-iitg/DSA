//================CP: 59A========================
// #include <iostream>
// #include <string>
// #include <cctype>
// using namespace std;

// int main(){
//     string st;
//     cin >> st;
//     int is_upper = 0;
//     int is_lower = 0;
//     int len = st.length();

//     for(int i = 0; i < len ; i++){
//         if((int)st[i] >= 65 && (int)st[i] <= 90){
//             is_upper++;
//         }
//         else{
//             is_lower++;
//         }
//     }
//     if(is_upper > is_lower){
//         for(int i = 0; i < len ; i++){
//             st[i] = toupper(st[i]); 
//         }
//     }
//     else{
//         for(int i = 0; i < len ; i++){
//             st[i] = tolower(st[i]); 
//         }
//     }
//     cout << st;
//     return 0;
// }


//=================CP : HULK 705A===============
// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     int n = 0;
//     cin >> n;
//     for(int i = 0; i < n ; i++){
//         if(i % 2 == 0){
//             cout << "I hate ";
//             if(i == n - 1){
//                 cout << "it";
//             }
//             else{
//                 cout << "that ";
//             }
//         }
//         else{
//             cout << "I love ";
//             if(i == n - 1){
//                 cout << "it";
//             }
//             else{
//                 cout << "that ";
//             }
//         }
//     }
//     return 0;
// }

//==================CP: 	1328A - Divisibility Problem===========
#include <iostream>
#include <vector>
int main(){
    int n = 0;
    std::cin >> n;
    std::vector<int> ans  (n , 0);
    for(int i = 0 ; i < n ; i++){
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        if(a % b == 0){
            ans[i] = 0;
            continue;
        }
        else if(a > b){
            ans[i] = b - (a % b); // 5, 3.   7, 3
            continue;
        }
        else{
            ans[i] = b - a;
        }
    }
    for(int x : ans){
        std::cout << x << "\n";
    }
    return 0;
}