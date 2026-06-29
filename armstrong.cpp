#include <cmath>
#include <iostream>
#include <string>

using namespace std;
class Armstrong {
public:
  static bool arm_num(int n) {
    int num = n;
    int k = to_string(n).length();
    int sum = 0;

    while (n > 0) {
      int ld = n % 10;
      sum += pow(ld, k);
      n /= 10;
    }
    return sum == num;
  }
};
int main() {
  cout << "Enter a number : ";
  int number;
  cin >> number;
  cout << endl;
  Armstrong arm;
  if (arm.arm_num(number)) {
    cout << number << " is an Armstrong number \n";
  } else {
    cout << "No , " << number << " is not an armstrong number";
  }
  return 0;
}