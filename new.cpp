#include <iostream>
#include <string>
#include <cctype> // Required for tolower()

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of characters (we don't actually need to use 'n')
    
    string s;
    cin >> s; // Read the string
    
    // Step 1: Create our "checklist" of 26 letters, all starting as false (not seen)
    bool seen[26] = {false};
    
    // Step 2: Loop through every character in the string
    for (int i = 0; i < s.length(); i++) {
        // Step 3: Convert character to lowercase
        char lower_c = tolower(s[i]);
        
        // Step 4 & 5: Find its position (0 to 25) and mark it as seen
        // By subtracting 'a' from a lowercase letter, we get its 0-25 index.
        // E.g., 'c' - 'a' = 2
        int index = lower_c - 'a';
        seen[index] = true;
    }
    
    // Step 6: Check if all 26 letters were seen
    bool is_pangram = true;
    for (int i = 0; i < 26; i++) {
        if (seen[i] == false) {
            is_pangram = false; // We found a missing letter!
            break; // We can stop checking now
        }
    }
    
    // Output the result
    if (is_pangram) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}