#include <iostream>
using namespace std;

class pattern {
public:
  void printpattern(int n) {
    for (int i = 0; i <= n; i++) {
      for (int j = n; j > i; j--) {
        cout << " ";
      }
      for (char k = 'A'; k < 'A' + i; k++) {
        cout << k;
      }
      for (char l = 'A' + i - 2; l >= 'A'; l--) {
        cout << l;
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