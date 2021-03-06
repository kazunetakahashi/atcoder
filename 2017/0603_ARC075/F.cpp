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

ll S;
ll M;

ll rev(ll n) {
  string s = to_string(n);
  while ((ll)s.size() < S) {
    s = '0' + s;
  }
  reverse(s.begin(), s.end());
  return stoll(s);
}

ll rev2(ll n) {
  string s = to_string(n);
  reverse(s.begin(), s.end());
  return stoll(s); 
}

int main () {
  ll D;
  cin >> D;
  S = to_string(D).size();
  M = 1;
  for (auto i = 0; i < (S+1)/2; ++i) {
    M *= 10;
  }
  bool ok = false;
  ll base;
  for (auto i = 1; i < M; ++i) {
    // cerr << "i = " << i << ", rev(" << i << ") = " << rev(i) << endl;
    if (i + D == rev(i)) {
      base = i;
      ok = true;
      break;
    }
  }
  // cerr << "base = " << base << endl;
  set<ll> S;
  if (ok) {
    ll ans = 0;
    for (auto i = 0; i < M * 10; ++i) {
      ll add = i + rev(i);
      if (S.find(add) == S.end()) {
        S.insert(add);
        ll t = base + add;
        if (t + D == rev2(t)) {
          ++ans;
        }
      }
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}
