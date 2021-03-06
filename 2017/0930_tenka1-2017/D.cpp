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

ll N, K;
ll A[100010];
ll B[100010];

int main () {
  cin >> N >> K;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  if (K == 0) {
    ll ans = 0;
    for (auto i = 0; i < N; ++i) {
      if (A[i] == 0) ans += B[i];
    }
    cout << ans << endl;
    return 0;
  }
  ll ans = 0;
  ll t = 0;
  int mb = 0;
  for (auto i = 0; i < 40; ++i) {
    ll x = (K >> i);
    if (x == 1) {
      mb = i;
      break;
    }
  }
  ll sup = ((ll)1 << mb) - 1;
  for (auto i = 0; i < N; ++i) {
    if (A[i] <= sup) t += B[i];
    // cerr << "t = " << t << endl;
  }
  ans = max(ans, t);
  for (auto k = 0; k < 40; ++k) {
    sup = 0;
    for (auto j = k; j < 40; ++j) {
      sup += ((ll)1 << j);
    }
    sup = (K & sup);
    if (sup == 0) continue;
    sup -= 1;
    cerr << "sup = " << sup << endl;
    t = 0;
    for (auto i = 0; i < N; ++i) {
      bool ok = true;
      for (auto j = 0; j < 40; ++j) {
        if ((((sup >> j) & 1) == 0)
            && (((A[i] >> j) & 1) == 1)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        t += B[i];
      }
    }
    ans = max(ans, t);
  }
  sup = K;
  cerr << "sup = " << sup << endl;
  t = 0;
  for (auto i = 0; i < N; ++i) {
    bool ok = true;
    for (auto j = 0; j < 40; ++j) {
      if ((((sup >> j) & 1) == 0)
          && (((A[i] >> j) & 1) == 1)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      t += B[i];
    }
  }
  ans = max(ans, t);
  cout << ans << endl;
}
