#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverse_string(string s) {
        string result = "";
        vector<string> st;
        string word = "";

        // Split the string into words
        for (char w : s) {
            if (w != ' ') {
                word.push_back(w);
            }
            else if (!word.empty()) {
                st.push_back(word);
                word = "";
            }
        }

        // Add the last word
        if (!word.empty()) {
            st.push_back(word);
        }

        // Reverse the words
        int len = st.size();

        for (int i = len - 1; i >= 0; i--) {
            result.append(st[i]);

            if (i != 0) {
                result.append(" ");
            }
        }

        return result;
    }
};

int main() {
    string st = " hello world ";

    Solution sol;

    cout << sol.reverse_string(st) << endl;

    return 0;
}