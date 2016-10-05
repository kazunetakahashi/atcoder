#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main() {
  int A1, A2;
  int B1, B2;
  int C;
  cin >> A1 >> A2 >> B1 >> B2 >> C;
  set<int> S;
  if (C == A1 || C == A2) {
    S.insert(B1);
    S.insert(B2);
  }
  if (C == B1 || C == B2) {
    S.insert(A1);
    S.insert(A2);
  }
  cout << S.size() << endl;
  for (auto x : S) {
    cout << x << endl;
  }
}
