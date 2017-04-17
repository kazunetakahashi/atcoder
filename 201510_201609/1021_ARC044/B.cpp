#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll ans[100010];
ll b[100010];

const int MAX_SIZE = 100010;
const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init() {
  inv[1] = 1;
  for (int i=2; i<MAX_SIZE; i++) {
    inv[i] = ((MOD - inv[MOD%i]) * (MOD/i))%MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i=1; i<MAX_SIZE; i++) {
    fact[i] = (i * fact[i-1])%MOD;
    factinv[i] = (inv[i] * factinv[i-1])%MOD;
  }
}

long long C(int n, int k) {
  if (n >=0 && k >= 0 && n-k >= 0) {
    return ((fact[n] * factinv[k])%MOD * factinv[n-k])%MOD;
  }
  return 0;
}

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

const int M = MOD;

int main() {
  init();
  int N;
  cin >> N;
  int A[100010];
  fill(b, b+100010, 0);
  int sup = 0;
  for (auto i=0; i<N; i++) {
    cin >> A[i];
    b[A[i]]++;
    sup = max(sup, A[i]);
  }
  if ((A[0] != 0) || (b[0] != 1)) {
    cout << 0 << endl;
    return 0;
  }
  ans[0] = 1;
  for (auto i=0; i<sup; i++) {
    ans[i+1] = ans[i];
    ll tei = (power(2, b[i]) + M - 1)%M;
    ans[i+1] *= power(tei, b[i+1]);
    ans[i+1] %= M;
    ans[i+1] *= power(2, (b[i+1] * (b[i+1]-1)) / 2);
    ans[i+1] %= M;
    // cerr << "ans[" << i+1 << "] = " << ans[i+1] << endl;
  }
  cout << ans[sup] << endl;
}
