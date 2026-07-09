#include <iostream>
#include <vector>
#include <string>
using namespace std;
class solution{
    public:
    string common_prefix(vector<string> &strs){
        if (strs.empty()) {
            return "";
        }
        string str = "";
        int smallest_string_len = strs[0].length();
        for(string x : strs){
            if(x.length() < smallest_string_len){
                smallest_string_len = x.length();
            }
        }  
        for(int i = 0; i < smallest_string_len; i++){
            char current = strs[0][i];
            for(size_t j = 1; j < strs.size(); j++){
                if(strs[j][i] != current){
                    return str;
                }
            }
            str.push_back(current);
        }
        return str;
    }
};
int main(){
    vector<string> strs = {"flower","flow","flight"};
    solution sol;
    cout << "The common prefix is : " <<  sol.common_prefix(strs) << endl;
    return 0;
}