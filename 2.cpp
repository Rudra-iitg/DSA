#include <iostream>
using namespace std;

class pattern {
public:
  void printpattern(int n) {
    for (int i = 1; i <= n; i++) {
      char ch = 'A' + i - 1;
      for (int j = 1; j <= i; j++) {
        cout << ch << " ";
      }
      cout << endl;
    }
  }
};
int main() {
  int n;
  cout << "Enter the number of rows: ";
  cin >> n;
  pattern p;
  p.printpattern(n);
  return 0;
}