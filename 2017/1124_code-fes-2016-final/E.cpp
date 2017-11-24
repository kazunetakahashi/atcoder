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

ll power(ll a, ll n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 0) {
    ll x = power(a, n/2);
    return x * x;
  } else {
    return power(a, n-1) * a;
  }
}

ll N, A;

int main () {
  cin >> N >> A;
  ll ub = sqrt(N)+1;
  ll lb = 2;
  ll ans = N;
  for (auto i = 2; i < 1000; ++i) {
    if (power(2, i) > N) break;
    while (ub - lb > 1) {
      ll t = (ub + lb)/2;
      if (power(t, i) > N) {
        ub = t;
      } else {
        lb = t;
      }
    }
    // cerr << "i = " << i << ", lb = " << lb << endl;
    for (auto j = 0; j <= i; ++j) {
      if (power(lb, i-j) * power(lb+1, j) >= N) {
        ans = min(ans, lb * (i-j) + (lb+1) * j + A * (i-1));
        break;
      }
    }
    ub = lb;
    lb = 2;
  }
  cout << ans << endl;
}
