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

int N, X, Y, Z;
int haiku;
const int nagasa = (1 << 17) - 1;

ll dp[50][nagasa];

bool ishaiku(int bit) {
  return ((bit & haiku) == haiku);
}

int main() {
  init();
  //cerr << (1 << 1) << endl;
  //cerr << (1 << 2) << endl;
  cin >> N >> X >> Y >> Z;
  haiku = 0;
  haiku += (1 << (X+Y+Z-1));
  haiku += (1 << (Y+Z-1));
  haiku += (1 << (Z-1));
  fill(&dp[0][0], &dp[0][0]+50*nagasa, 0);
  dp[0][0] = 1;
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < nagasa; j++) {
      if (dp[i][j] == 0) continue;
      for (auto k = 1; k <= 10; k++) {
        int ind = (((j << k) + (1 << (k-1))) & nagasa);
        if (!ishaiku(ind)) {
          dp[i+1][ind] += dp[i][j];
          dp[i+1][ind] %= MOD;
        }
      }
    }
  }
  ll negative = 0;
  for (auto i = 0; i < nagasa; i++) {
    negative += dp[N][i];
    negative %= MOD;
  }
  ll ans = ((power(10, N) + (MOD - negative)))%MOD;
  cout << ans << endl;
}
