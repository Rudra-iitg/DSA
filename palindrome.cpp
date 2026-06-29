#include <iostream>
using namespace std;

class Palindrome {
public:
  bool real_palindrome(int n) {
    int revnum = 0;
    int duplicate = n;
    while (n > 0) {
      int lastdigit = n % 10;
      revnum = revnum * 10 + lastdigit;
      n /= 10;
    }
    if (revnum == duplicate) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  cout << "Enter a number : ";
  int number;
  cin >> number;
  cout << endl;
  Palindrome reverse_number;
  if (reverse_number.real_palindrome(number)) {
    cout << "The number is a palindrome" << '\n';
  } else {
    cout << "The number is not a palindrome \n";
  }
  return 0;
}