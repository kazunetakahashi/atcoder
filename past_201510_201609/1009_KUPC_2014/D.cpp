#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const int W = 100010;
const int M = 1000000007;

long long inv[W];
long long fact[W];
long long factinv[W];

void init() {
  inv[1] = 1;
  for (int i=2; i<W; i++) {
    inv[i] = ((M - inv[M%i]) * (M/i))%M;
  }
  fact[0] = factinv[0] = 1;
  for (int i=1; i<W; i++) {
    fact[i] = (i * fact[i-1])%M;
    factinv[i] = (inv[i] * factinv[i-1])%M;
  }
}

long long C(int n, int k) {
  if (n >=0 && k >= 0 && n-k >= 0) {
    return ((fact[n] * factinv[k])%M * factinv[n-k])%M;
  }
  return 0;
}

int main() {
  init();
  string S1, S2;
  int D1, D2;
  cin >> S1 >> D1 >> S2 >> D2;
  int l = S1.size();
  int a = 0;
  for (auto i=0; i<l; i++) {
    if (S1[i] == S2[i]) a++;
  }
  // cerr << "a = " << a << ", l = " << l << endl;
  int x, y;
  int tmp = l+a-D1-D2;
  if (tmp%2 == 1) {
    // cerr << "tmp = " << tmp << endl;
    cout << 0 << endl;
    return 0;
  }
  x = tmp/2;
  y = D2 - a + x;
  // cerr << "x = " << x << ", y = " << y << endl;
  cout << (C(a, x) * C(l-a, y))%M << endl;
}
