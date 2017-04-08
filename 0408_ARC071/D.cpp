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
const ll M = 1000000007;

ll length(ll z[100010], int k) {
  ll ans = 0;
  for (ll i = 0; i < k-1; ++i) {
    ll cnt = ((i+1) * (k-1-i))%M;
    ans += (cnt * (z[i+1] - z[i])) %M;
    ans %= M;
  }
  return ans;
}

int n, m;
ll x[100010], y[100010];

int main () {
  cin >> n >> m;
  for (auto i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (auto i = 0; i < m; ++i) {
    cin >> y[i];
  }
  cout << (length(x, n) * length(y, m)) % M << endl;
}
