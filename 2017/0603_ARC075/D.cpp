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

int main () {
  int N;
  ll A, B;
  ll h[100010];
  cin >> N >> A >> B;
  for (auto i = 0; i < N; ++i) {
    cin >> h[i];
  }
  ll ub = M;
  ll lb = 0;
  ll base = B;
  ll add = A - B;
  while (ub - lb > 1) {
    ll t = (ub + lb) / 2;
    ll death = base * t;
    ll need = 0;
    for (auto i = 0; i < N; ++i) {
      if (h[i] <= death) {
        continue;
      } else {
        ll nokori = h[i] - death;
        need += (nokori + (add - 1)) / add;
      }
    }
    if (need <= t) {
      ub = t;
    } else {
      lb = t;
    }
  }
  cout << ub << endl;
}
