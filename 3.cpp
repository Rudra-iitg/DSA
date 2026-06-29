#include <iostream>
using namespace std;

class pattern {
public:
  void printpattern(int n) {
    for (int i = 0; i <= n; i++) {
      for (char j = 'A' + n - i - 1; j <= 'A' + n - 1; j++) {
        cout << j << " ";
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