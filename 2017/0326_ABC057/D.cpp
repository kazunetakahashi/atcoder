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

ll C(ll n, ll k) {
  if (k == 0) return 1;
  return (C(n, k-1) * (n+1-k)) / k;
}

int N, A, B;
ll v[60];
ll maxi, mini;

int cnt(ll x) {
  int ans = 0;
  for (auto i = 0; i < N; ++i) {
    if (v[i] == x) ++ans;
  }
  return ans;
}

int gre(ll x) {
  int ans = 0;
  for (auto i = 0; i < N; ++i) {
    if (v[i] > x) ++ans;
  }
  return ans;  
}

void solve1() {
  int c = cnt(maxi);
  // cerr << c << endl;
  ll ans = 0;
  for (ll i = A; i <= min(c, B); ++i) {
    ans += C(c, i);
  }
  cout << ans << endl;
}

void solve2() {
  int c = cnt(mini);
  int d = gre(mini);
  cout << C(c, A-d) << endl;
}

int main() {
  cin >> N >> A >> B;
  for (auto i = 0; i < N; ++i) {
    cin >> v[i];
  }
  sort(v, v+N);
  reverse(v, v+N);
  maxi = v[0];
  mini = v[A-1];
  if (maxi == mini) {
    cout << maxi << endl;
    solve1();
  } else {
    double sum = 0;
    for (auto i = 0; i < A; ++i) {
      sum += v[i];
    }
    cout << fixed << setprecision(10) << sum/A << endl;
    solve2();
  }
}
