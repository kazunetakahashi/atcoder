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
const ll infty = (ll)1e18*4 + 10;

int N, K;
ll x[100];
ll y[100];

set<ll> Sx, Sy;

int ok(int k, ll X0, ll X1, ll Y0, ll Y1) {
  if (X0 <= x[k] && x[k] <= X1 && Y0 <= y[k] && y[k] <= Y1) {
    return 1;
  }
  return 0;
}

int cnt(ll X0, ll X1, ll Y0, ll Y1) {
  int ans = 0;
  for (auto i = 0; i < N; ++i) {
    ans += ok(i, X0, X1, Y0, Y1);
  }
  return ans;
}

ll area(ll X0, ll X1, ll Y0, ll Y1) {
  if (cnt(X0, X1, Y0, Y1) >= K) {
    return (Y1 - Y0) * (X1 - X0);
  }
  return infty;
}

int main () {
  cin >> N >> K;
  for (auto i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
    Sx.insert(x[i]);
    Sy.insert(y[i]);
  }
  ll ans = infty;
  for (auto itx0 = Sx.begin(); itx0 != Sx.end(); ++itx0) {
    for (auto itx1 = itx0; itx1 != Sx.end(); ++itx1) {
      for (auto ity0 = Sy.begin(); ity0 != Sy.end(); ++ity0) {
        for (auto ity1 = ity0; ity1 != Sy.end(); ++ity1) {
          ans = min(ans, area(*itx0, *itx1, *ity0, *ity1));
        }
      }
    }
  }
  cout << ans << endl;
}
