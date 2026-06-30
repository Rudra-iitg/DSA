#include <iostream>
#include <string>

using namespace std;

int main() {
  string name;
  cout << "Enter the string : ";
  cin >> name;

  // precompute;

  int hash[26] = {0};
  for (int i = 0; i < name.size(); i++) {
    hash[name[i] - 'a'] += 1;
  }

  cout << "enter the character to find the hash : ";
  char c;
  cin >> c;
  cout << hash[c - 'a'] << '\n';
  return 0;
}