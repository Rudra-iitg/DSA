#include <iostream>

using namespace std;

class Reverse {
public:
  int rev_num(int n) {
    int new_num = 0;
    while (n > 0) {
      int num1 = n % 10;
      new_num = 10 * new_num + num1;
      n /= 10;
    }
    return new_num;
  }
};
int main() {
  cout << "Enter a number: ";
  int given_num;
  cin >> given_num;

  cout << endl;

  Reverse number;
  cout << number.rev_num(given_num) << '\n';
  return 0;
}
