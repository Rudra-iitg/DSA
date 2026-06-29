#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// OPtimal method

int countdigit(int n) {
  int count = (int)(log10(n) + 1);
  return count;
}
int main() {
  // *******************. BRUTE FORCE METHOD ***********************
  auto num = 3445454;
  //   int count = 0;
  //   vector<int> new_vec;
  //   while (num > 0) {
  //     int x = num % 10;
  //     new_vec.push_back(x);
  //     num /= 10;
  //     count++;
  //   }
  //   reverse(new_vec.begin(), new_vec.end());
  //   for (int i = 0; i < new_vec.size(); i++) {
  //     cout << new_vec[i] << " ";
  //   }
  //   cout << '\n';
  cout << "The number of digit is " << countdigit(num);
  //   cout << endl;

  return 0;
}