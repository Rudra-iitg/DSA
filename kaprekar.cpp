// #include <iostream>
// using namespace std;

// int reverse(int n){
//     int temp = 0;
//     int num = 0;
//     while(n > 0){
//         temp = n % 10;
//         n /= 10;
//         num = 10 * num + temp; 
//     }
//     return num;
// }

// int kaprekar(int num){
//     int n = 0;
//     while (num != 6174){
//         num = num - reverse(num);
//         n++;
//     }
//     return n;
// }

// int main(){
//     cout << "The find the kaprakar number\n";
//     cout << "Enter a number: " ;
//     int num;
//     cin >> num;
//     cout << endl;
//     cout << "The number of times the number has to be subtracted to get the kaprekat numner : ";
//     cout << kaprekar(num);
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Get the 4 digits of a number
vector<int> getDigits(int n) {
    vector<int> d;
    for (int i = 0; i < 4; i++) {
        d.push_back(n % 10);
        n /= 10;
    }
    return d;
}

// Arrange digits in descending order to form the largest number
int digitsToNumDesc(vector<int> d) {
    sort(d.rbegin(), d.rend());
    int num = 0;
    for (int x : d) num = num * 10 + x;
    return num;
}

// Arrange digits in ascending order to form the smallest number
int digitsToNumAsc(vector<int> d) {
    sort(d.begin(), d.end());
    int num = 0;
    for (int x : d) num = num * 10 + x;
    return num;
}

// Kaprekar's routine: repeatedly subtract (descending - ascending)
// until reaching 6174
int kaprekar(int num) {
    int n = 0;
    while (num != 6174 && num != 0) {
        vector<int> d = getDigits(num);
        int big = digitsToNumDesc(d);
        int small = digitsToNumAsc(d);
        num = big - small;
        n++;
        if (n > 20) break; // safety net in case of invalid/edge input
    }
    return n;
}

int main() {
    cout << "Find the Kaprekar number\n";
    cout << "Enter a 4-digit number (not all same digit): ";
    int num;
    cin >> num;

    if (num < 1000 || num > 9999) {
        cout << "Please enter a 4-digit number.\n";
        return 1;
    }

    int steps = kaprekar(num);
    cout << "\nThe number of subtractions to reach 6174: " << steps << endl;
    return 0;
}