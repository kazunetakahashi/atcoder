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

int N, K;
int a[410];

int main () {
  cin >> N >> K;
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }
  assert(N <= 400 && K <= 400);
  int ans = 0;
  for (auto i = 0; i < N; ++i) {
    bool need = false;
    bool memo[410];
    fill(memo, memo+410, false);
    memo[0] = true;
    for (auto j = 0; j < N; ++j) {
      if (i == j) continue;
      for (auto k = K-1; k >= 0; --k) {
        if (memo[k] && k + a[j] < K) {
          memo[k + a[j]] = true;
        }
      }
    }
    for (auto j = max(K - a[i], 0); j < K; ++j) {
      if (memo[j]) {
        need = true;
        // cerr << "a[" << i << "] = " << a[i] << ", " << "j = " << j << endl;
        break;
      } 
    }
    if (need) ++ans;
  }
  cout << N - ans << endl;
}
