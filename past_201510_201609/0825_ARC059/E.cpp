#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;

ll M = 1e9 + 7;

int N, C;
ll A[410], B[410];
ll x[410];

ll memo[410][410];

ll f(int k, int n) {
  if (memo[k][n] != -1) return memo[k][n];
  ll ans;
  if (k == 0) ans = 0;
  else if (n == 0) ans = 1;
  else {
    ans = x[k-1] * f(k, n-1) + f(k-1, n);
    ans %= M;
  }
  // cerr << "f(" << k << ", " << n << ") = " << ans << endl;
  return memo[k][n] = ans;
}

int main() {
  cin >> N >> C;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (auto i = 0; i < N; i++) {
    cin >> B[i];
  }
  for (auto i = 0; i < N; i++) {
    assert(A[i] == B[i]); // 部分点
    x[i] = A[i];
  }
  fill(&memo[0][0], &memo[0][0]+410*410, -1);
  cout << f(N, C) << endl;
}
