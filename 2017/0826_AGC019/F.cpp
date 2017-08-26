#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

const int MAX_SIZE = 1000010;
const long long MOD = 998244353;

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

ll N, M;
ll S[500010];
ll T[500010];
ll U[500010];
ll K[500010];
ll R[500010];
ll L[500010];
ll bunbo[500010];
ll bunshi[500010];

int main() {
  init();
  cin >> N >> M;
  if (N > M) swap(N, M);
  for (ll j = 0; j <= N+M; ++j) {
    R[j] = min(j, N);
    L[j] = max((ll)0, j-M);
  }
  S[1] = 2;
  T[1] = 2;
  for (auto j = 1; j < N+M; ++j) {
    S[j+1] = 2 * S[j] + C(j, R[j]+1) + MOD - C(j+1, L[j]-1);
    S[j+1] %= MOD;
    K[j] = T[j];
    if (R[j] == N) {
      K[j] += MOD - C(j, R[j] * max(R[j], j-R[j]));
    }
    U[j+1] = 2 * K[j] + MOD - C(j, L[j]) * (j+1) + S[j];
    T[j+1] = U[j+1];
    if ((j+1)%2 == 0 && L[j] == j-M) {
      T[j+1] += S[j+1];
    }
    if (R[j] == N) {
      T[j+1] += C(j+1, R[j+1]);
    }
    T[j+1] %= MOD;
  }
  ll ans = 0;
  for (auto j = 1; j <= N+M; ++j) {
    bunbo[j] = (S[j] * j) % MOD;
    bunshi[j] = T[j];
    cerr << "j = " << j << "; " << bunshi[j] << "/" << bunbo[j] << endl;
    ans += bunshi[j] * inv[bunbo[j]];
    ans %= MOD;
  }
  cout << ans << endl;
}
