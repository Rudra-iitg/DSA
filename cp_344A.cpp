// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int group = 0;
//     int first_mag ;
//     int second_mag = 0;
//     for(int i = 0 ; i < n ; i++){
//         cin >> first_mag;
//         if(first_mag != second_mag) group++;
//         second_mag = first_mag;
//     }
//     cout << group;
//     return 0;
// }

//=================. 200B ===================
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     double sum = 0;
//     for(int  i = 0; i < n ; i++){
//         int a;
//         cin >> a;
//         sum += a;
//     }
//     cout << sum /n;
//     return 0;
// }

//=============== 228A=================

// #include <iostream>
// #include <set>
// using namespace std;
// int main(){
//     set<int> color;
//     for(int i = 0 ; i < 4; i++){
//         int a;
//         cin >> a;
//         color.insert(a);
//     }
//     cout << 4 - color.size();
//     return 0;
// }
//=================136A=================

// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i = 0; i < n ; i++){
//         int a;
//         cin >> a;
//         arr[a - 1] = i + 1;
//     }
//     for(int x : arr){
//         cout << x << " ";
//     }
//     return 0;
// }

//======================61A================
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    // The problem guarantees they are the same length, so we just loop through 'a'
    for (int i = 0; i < a.length(); i++) {
        
        // If the characters at this index are different, print '1'
        if (a[i] != b[i]) {
            cout << '1';
        } 
        // If they are the same, print '0'
        else {
            cout << '0';
        }
    }
    cout << endl;
    
    return 0;
}