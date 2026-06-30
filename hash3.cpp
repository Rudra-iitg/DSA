#include <iostream>
using namespace std;
class frequency {
public:
  void maps(int arr[], int n) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
      map[arr[i]]++;
    }
    int maxfriq = 0, minfriq = n;
    int maxEle = 0, minEle = 0;

    for (auto x : map) {
      int element = x.first;
      int count = x.second;

      if (count > maxfriq) {
        maxfriq = count;
        maxEle = element;
      }
      if (count < minfriq) {
        minfriq = count;
        minEle = element;
      }
    }
    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
  }
};

int main() {
  frequency fy;
  int arr[] = {3, 3, 5, 2, 4, 3, 4, 5, 8, 3, 5, 8, 5, 6, 7, 7, 4, 9, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  fy.maps(arr, n);
  return 0;
}