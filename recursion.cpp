#include <iostream>

using namespace std;
void repeat_name(string name, int n) {
  if (n == 0) {
    return;
  }
  cout << name << '\n';
  repeat_name(name, n - 1);
}
int main() {
  string name = "Pawan";
  repeat_name(name, 3);
  return 0;
}