#include <iostream>
#include <string>
using namespace std;

int main() {
  int A[2], B[2];
  cin >> A[0] >> A[1];
  cin >> B[0] >> B[1];
  bool x = false;
  for (auto i = 0; i < 2; i++) {
    for (auto j = 0; j < 2; j++) {
      if (A[i] == B[j]) {
        x = true;
      }
    }
  }
  cout << (x ? "YES" : "NO") << endl;
}
