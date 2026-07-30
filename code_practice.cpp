#include <iostream>
using namespace std;

class Shallow {
public:
  int *id;
  Shallow(int n) {
    cout << "Shallow constructor called;" << endl;
    id = new int(n);
  }
  ~Shallow() {
    cout << "Shallow Distructor called" << endl;
    delete id;
  }
};

class Deep {
public:
  int *id;
  Deep(int n) {
    cout << "Deep constructor is called: " << endl;
    id = new int(n);
  }
  // Deep Distructor is called;

  Deep(const Deep &other) {
    cout << "THE REAL DEEP CONSTRUCTOR IS CALLED" << endl;
    id = new int(*other.id);
  }
  ~Deep() {
    cout << "Deep Distructor is called: " << endl;
    delete id;
  }
};

int main() {

  Shallow A(7);
  Shallow B = A;

  cout << "A has the id: " << *A.id << endl;
  cout << "B has the id: " << *B.id << endl;

  *A.id = 999;

  cout << "After changing the values\n";
  cout << "A id " << *A.id << " " << endl;
  cout << "B id " << *B.id << "  <<--- B data also changed" << endl;

  // Deep constructor;

  Deep C(100);
  Deep F = C;
  cout << "C has the id: " << *C.id << endl;
  cout << "F has the id: " << *F.id << endl;

  *C.id = 56;
  cout << "After changing the values\n";
  cout << "C id " << *C.id << " " << endl;
  cout << "F id " << *F.id << "  <<--- F data not changed" << endl;

  return 0;
}