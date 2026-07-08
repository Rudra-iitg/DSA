#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Roman{
    public: 
    int rom_to_int(string s){
        unordered_map<char, int> roman_value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int total = 0;
        for(int i = 0; i < s.length()-1 ; i++){
            if(roman_value[s[i]] < roman_value[s[i + 1]] ){
                total -= roman_value[s[i]];
            }
            else{
                total += roman_value[s[i]];
            }
        }
        total += roman_value[s.back()];
        return total;
    }
};

int main(){
    string str1 = "MMCMCCXCIXCII";
    Roman rom;
    cout << "The integer value of : "  << str1 << "  is : " << rom.rom_to_int(str1);
    cout << endl;
    return 0;
}