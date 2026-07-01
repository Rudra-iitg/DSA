#include <iostream>
#include <string> 
using namespace std;

bool palindrome(size_t i, const string& str){
    if(i >= str.length()/2) return true;

    if(str[i] != str[str.length() - i - 1]) return false;

    return palindrome(i+1, str);
}

int main(){
    cout << "Enter an string : ";
    string str;
    cin >> str;
    cout << endl;
    cout << boolalpha;

    cout << " The string  ' " << str << "  '  is a palindrome: " << palindrome(0,str) << '\n'; 

    return 0;
}