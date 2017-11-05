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

int main () {
  int N;
  cin >> N;
  ll a[100];
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  bool ok = false;
  while (!ok) {
    ok = true;
    for (auto i = 0; i < N; ++i) {
      if (a[i] <= N-1) {
        continue;
      } else {
        ok = false;
        break;
      }
    }
    if (!ok) {
      ll S = 0;
      for (auto i = 0; i < N; ++i) {
        S += a[i]/N;
      }
      for (auto i = 0; i < N; ++i) {
        a[i] = a[i] - N * (a[i]/N) + S - a[i]/N;
      }
    }
  }
  cout << ans << endl;
}
