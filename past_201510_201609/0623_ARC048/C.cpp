#include <iostream>
#include <cmath>
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
const ll infty = 1e9+10;

int main() {
  init();
  int N;
  cin >> N;
  ll L[100010];
  for (auto i = 0; i < N; i++) {
    cin >> L[i];
  }
  ll mini = infty;
  for (auto i = 0; i < N; i++) {
    mini = min(L[i], mini);
  }
  for (auto i = 0; i < N; i++) {
    L[i] -= mini;
  }
  ll g = L[0];
  for (auto i = 1; i < N; i++) {
    g = gcm(L[i], g);
  }
  cout << power(2, mini + (g+1)/2) << endl;
}
