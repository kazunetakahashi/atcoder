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

ll N, Q;

vector<ll> waru(ll x) {
  vector<ll> ans;
  ans.push_back(x);
  while (x > 0) {
    x = (x-1)/N;
    ans.push_back(x);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

ll solve(ll x, ll y) {
  vector<ll> V = waru(x);
  vector<ll> W = waru(y);
  int ind = 0;
  ll ans = 0;
  while (ind < (int)V.size() && ind < (int)W.size()) {
    if (V[ind] == W[ind]) {
      ans = V[ind];
      ind++;
    } else {
      break;
    }
  }
  return ans;
}

int main () {
  cin >> N >> Q;
  for (auto i = 0; i < Q; ++i) {
    ll v, w;
    cin >> v >> w;
    v--;
    w--;
    cout << solve(v, w) + 1 << endl;
  }
}
