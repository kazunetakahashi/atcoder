#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string A;
  cin >> A;
  string B = A;
  reverse(B.begin(), B.end());
  int x = 0;
  // cerr << B << endl;
  for (unsigned i = 0; i < A.size(); i++) {
    if (A[i] != B[i]) x++;
  }
  // cerr << x << endl;
  int X = 0;
  int l = A.size();
  if (l%2 == 0) {
    if (x == 0) {
      X = 0;
    } else if (x == 2) {
      X = 2;
    } else {
      X = 0;
    }
  } else {
    if (x == 0) {
      X = 25;
    } else if (x == 2) {
      X = 2;
    } else {
      X = 0;
    }
  }
  cout << 25 * l - X << endl;
}
