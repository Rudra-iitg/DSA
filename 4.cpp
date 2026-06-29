#include <iostream>
using namespace std;
int main() {
  auto num = 34454545326;
  int count = 0;
  vector<int> new_vec;
  while (num > 0) {
    int x = num % 10;
    new_vec.push_back(x);
    num /= 10;
    count++;
  }
  reverse(new_vec.begin(), new_vec.end());
  for (int i = 0; i < new_vec.size(); i++) {
    cout << new_vec[i] << " ";
  }
  cout << '\n';
  cout << "The number of digit is " << count;
  cout << endl;

  return 0;
}