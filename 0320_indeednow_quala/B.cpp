#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int X[30];
int Y[30];

bool XY() {
  int *x, *y;
  x = X;
  y = Y;
  for (auto i=0; i<30; i++) {
    if (*x != *y) return false;
    x++; y++;
  }
  return true;
}

void count(int *c, string S) {
  fill(c, c+30, 0);
  auto s = S.begin();
  while (s != S.end()) {
    c[*s - 'a']++;
    s++;
  }
}

int main() {
  count(X, "indeednow");
  int N;
  cin >> N;
  for (auto i=0; i<N; i++) {
    string S;
    cin >> S;
    count(Y, S);
    cout << (XY() ? "YES" : "NO") << endl;
  }
}
