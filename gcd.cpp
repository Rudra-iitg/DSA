#include <iostream>
using namespace std;

int gcd(int num1, int num2) {
  for (int i = min(num1, num2); i > 0; i--) {
    if (num1 % i == 0 && num2 % i == 0) {
      return i;
    }
  }
  return 0;
}

int main() {
  int num1 = 4425;
  int num2 = 545;
  cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2)
       << endl;
  return 0;
}