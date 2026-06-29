#include <iostream>
#include <vector>
using namespace std;

vector<int> divisors;
int factors(int n) {
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
    }
  }
  return 0;
}

int main() {

  cout << "Enter a numebr : ";
  int num;
  cin >> num;
  cout << endl;
  factors(num);
  cout << "The divisors are: ( ";
  for (int i = 0; i < divisors.size(); i++) {
    cout << divisors.at(i) << "  ";
  }
  cout << ")\n";
  return 0;
}