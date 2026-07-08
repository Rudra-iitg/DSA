#include <iostream>
#include <string>
using namespace std;

class to_roman{
    public:
    string int_to_roman(int n){
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result = "";
        for(int i = 0; i < values.size(); i++){
            while(n >= values[i]){
                result += symbols[i];
                n -= values[i];
            }
        } 
        return result;
    }
};
int main(){
    cout << "Enter a number : " ;
    int x ;
    cin >> x;
    to_roman toro; 
    cout << "The Roman is : " << toro.int_to_roman(x) << endl;
    return 0;
}