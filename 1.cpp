#include <iostream>
using namespace std;

class star {
public:
  void starpatten_up(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        cout << " ";
      }
      for (int j = 0; j < 2 * i + 1; j++) {
        cout << "*";
      }
      cout << endl;
    }
  }

  void starpatten_down(int n) {
    for (int i = 0; i < n; i++) {
      // Print spaces
      for (int j = 0; j < i + 1; j++) {
        cout << " ";
      }
      // Print stars
      for (int j = 0; j < 2 * (n - i) - 1; j++) {
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
  s.starpatten_up(n);
  s.starpatten_down(n - 1);
  return 0;
}