#include <iostream>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
using namespace std;

const int MAX_SIZE = 1000010;
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

long long gcm(long long a, long long b) {
  if (a < b) {
    return gcm(b, a);
  }
  if (b == 0) return a;
  return gcm(b, a%b);
}

typedef long long ll;

ll retsu(ll l, ll s) {
  return C(s-1, l-1);
}

int main() {
  init();
  ll N, X, Y, Z;
  cin >> N >> X >> Y >> Z;
  ll ans = 0;
  for (auto x = 1; x <= X; x++) {
    for (auto y = 1; y <= Y; y++) {
      for (auto z = 1; z <= Z; z++) {
        ll R = N-(x+y+z);
        if (R < 0) continue;
        ll temp = retsu(x, X);
        // cerr << temp << endl;
        temp %= MOD;
        temp *= retsu(y, Y);
        temp %= MOD;
        temp *= retsu(z, Z);
        temp %= MOD;
        temp *= (power(10, R) * (R+1)) % MOD;
        temp %= MOD;
        ans += temp;
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}
