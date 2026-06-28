#include <iostream>
using namespace std;

class pattern {
public:
  void printpattern(int n) {
    int space = 2 * n - 2;
    for (int i = 1; i <= n; i++) {
      // num
      for (int j = 1; j <= i; j++) {
        cout << j;
      }
      // space
      for (int j = 1; j <= space; j++) {
        cout << " ";
      }
      // rev num
      for (int j = i; j >= 1; j--) {
        cout << j;
      }
      cout << endl;
      space = space - 2;
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