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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
const ll M = 1000000007;
ll N;
ll K;

const int MAX_SIZE = 100010; // 10000010でもよさそう？
bool isprime[MAX_SIZE];
vector<ll> prime_num;
map<ll, set<ll> > yakusu;

void init() {
  fill(isprime, isprime+MAX_SIZE, true);
  isprime[0] = isprime[1] = false;
  for (auto i=2; i<MAX_SIZE; i++) {
    if (isprime[i]) {
      prime_num.push_back(i);
      for (auto j=2; i*j<MAX_SIZE; j++) {
        isprime[i*j] = false;
      }
    }
  }
  for (auto x : prime_num) {
    set<ll> s;
    s.insert(1);
    s.insert(x);
    yakusu[x] = s;
  }
}

bool prime(long long x) { // 2 \leq x \leq MAX_SIZE^2
  if (x < MAX_SIZE) {
    return isprime[x];
  }
  for (auto e : prime_num) {
    if (x%e == 0) return false;
  }
  return true;
}

set<ll> get_yakusu(ll x) {
  if (yakusu.find(x) != yakusu.end()) {
    return yakusu[x];
  }
  set<ll> s;
  s.insert(1);
  s.insert(x);
  if (prime(x)) {
    yakusu[x] = s;
    return s;
  }
  for (auto y : prime_num) {
    if (x % y == 0) {
      set<ll> t = get_yakusu(x/y);
      for (auto z : t) {
        s.insert(z);
        s.insert(z * y);
      }
      break;
    }
  }
  yakusu[x] = s;
  return s;
}

const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init2() {
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

map<ll, ll> unit;

ll unit_kaibun(ll n) {
  // cerr << n << endl;
  if (unit.find(n) != unit.end()) {
    return unit[n];
  }
  ll ans = power(K, (n+1)/2);
  set<ll> s = get_yakusu(n);
  for (auto x : s) {
    if (x == n) continue;
    ans += M - unit_kaibun(x);
    ans %= M;
  }
  return unit[n] = ans;
}

int main() {
  init();
  init2();
  ll ans = 0;
  cin >> N >> K;
  unit[1] = K;
  for (auto i = 0; i <= N; i++) {
    ans += (power(K, (i+1)/2) * power(K, ((N-i)+1)/2)) %M;
    ans %= M;
    // cerr << ans << endl;
  }
  set<ll> s = get_yakusu(N);
  for (auto x : s) {
    ll k = unit_kaibun(x);
    cerr << x << " " << k << endl;
    ll tot = k * (N/x);
    cerr << x << " " << k << " " << tot << endl;
    tot %= M;
    ans += M - tot;
    ans %= M;
  }
  cout << ans << endl;
}
