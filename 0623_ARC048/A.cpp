#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A < 0 && B > 0) {
    cout << B - A - 1 << endl; 
  } else {
    cout << B - A << endl;
  }
}
