#include <iostream>
using namespace std;

const int W = 200010;
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
  int n, k;
  cin >> n >> k;
  cout << C(n+k-1, k) << endl;
}
