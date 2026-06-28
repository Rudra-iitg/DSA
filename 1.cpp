#include <iostream>
using namespace std;

class star {
public:
  void starpatten(int n) {
    for (int i = 0; i < n; i++) {
      // Print spaces
      for (int j = 0; j < i; j++) {
        cout << " ";
      }
      // Print stars
      for (int j = 1; j <= 2 * (n - i) - 1; j++) {
        cout << "*";
      }
      cout << endl;
    }
  }
};

int main() {
  int n;
  cout << "Enter the number of rows: ";
  cin >> n;
  star s;
  s.starpatten(n);
  return 0;
}