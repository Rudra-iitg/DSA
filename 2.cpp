#include <iostream>
using namespace std;

class pattern {
public:
  void printpattern(int n) {
    for (int i = n; i >= 1; i--) {
      for (char ch = 'A'; ch <= 'A' + i - 1; ch++) {
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