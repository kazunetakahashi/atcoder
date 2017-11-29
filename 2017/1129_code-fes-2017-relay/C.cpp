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

int N;
ll K;
ll w[100010];
ll d[100010];

ll count(int ind, ll x) {
  return (x - w[ind])/d[ind] + 1;
}

ll count(ll x) {
  ll ans = 0;
  for (auto i = 0; i < N; ++i) {
    ans += count(i, x);
  }
  return ans;
}

ll heikin(ll x, ll y) {
  ll ans = 0;
  ll amari = 0;
  ans += x/2;
  ans += y/2;
  amari += x%2;
  amari += y%2;
  ans += amari/2;
  return ans;
}

int main () {
  cin >> N >> K;
  for (auto i = 0; i < N; ++i) {
    cin >> w[i] >> d[i];
  }
  ll lb = 0;
  ll ub = 1999999999000000000+10;
  while (ub - lb > 1) {
    ll t = heikin(lb, ub);
    if (count(t) >= K) {
      ub = t;
    } else {
      lb = t;
    }
  }
  cout << ub << endl;
}
