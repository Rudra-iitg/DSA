#include <iostream>
using namespace std;

int main() {
  // CREATE AN ARRAY OF DESIRED SIZE
  int n;
  cout << "Enter the number of elemetns required in the array: ";
  cin >> n;
  cout << endl;
  int arr[n];
  cout << "Enter the array emements : ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << endl;
  cout << "Your array is: [ ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << '\t';
  }
  cout << " ]\n";

  // PRECOMPUTE:

  int hash[11] = {0};
  for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }

  cout << "Enter the number: ";
  int q;
  cin >> q;
  while (q--) {
    int number;
    cin >> number;
    cout << number << " appeared" << hash[number] << " times" << endl;
  }
  return 0;
}