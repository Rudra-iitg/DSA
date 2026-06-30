#include <iostream>
using namespace std;

int main() {
  int array[] = {1, 2, 4, 3, 2, 3, 7};
  int hash[8] = {0};
  for (int x : array) {
    hash[x]++;
  }
  cout << hash[3] << '\n';
  return 0;
}