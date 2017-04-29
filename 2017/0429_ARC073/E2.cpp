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
const ll infty = 1000000007;

int N;
ll x[200010];
ll y[200010];

typedef pair<ll, int> state;

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
    if (x[i] < y[i]) swap(x[i], y[i]);
  }
  ll maxi = 0;
  int maxi_ind;
  ll mini = infty;
  int mini_ind;
  for (auto i = 0; i < N; ++i) {
    if (maxi < x[i]) {
      maxi = x[i];
      maxi_ind = i;
    }
    if (mini > y[i]) {
      mini = y[i];
      mini_ind = i;
    }
  }
  ll x_mini = infty;
  ll y_maxi = 0;
  for (auto i = 0; i < N; ++i) {
    x_mini = min(x_mini, x[i]);
    y_maxi = max(y_maxi, y[i]); 
  }
  ll ans = (maxi - x_mini) * (y_maxi - mini);
  for (auto i = 0; i < N; ++i) {
    if (i == maxi_ind) continue;
    if (mini == y[i]) {
      mini_ind = i;
    }
  }
  if (maxi_ind != mini_ind) {
    set<state> hako;
    ll ub = x[mini_ind];
    ll lb = y[maxi_ind];
    if (ub < lb) swap(ub, lb);
    for (auto i = 0; i < N; ++i) {
      if (i != maxi_ind && i != mini_ind) {
        hako.insert(state(y[i], i));
      }
    }
    hako.insert(state(ub, -1));
    hako.insert(state(lb, -1));
    ll under = infty;
    while (true) {
      auto last = hako.end();
      last--;
      under = min(under, (*last).first - (*hako.begin()).first);
      int ind = (*hako.begin()).second;
      if (ind != -1) {
        hako.erase(hako.begin());
        hako.insert(state(x[ind], -1));
      } else {
        break;
      }
    }
    ans = min(ans, under * (maxi - mini));
  }
  cout << ans << endl;
}
