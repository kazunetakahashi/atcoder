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

const int C = 410;
const int infty = 1000000007;

int N, Ma, Mb;
int a[100], b[100], c[100];

int DP[410][410];

int main () {
  cin >> N >> Ma >> Mb;
  for (auto i = 0; i < N; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (auto i = 0; i < C; ++i) {
    for (auto j = 0; j < C; ++j) {
      DP[i][j] = infty;
    }
  }
  DP[0][0] = 0;
  for (auto t = 0; t < N; ++t) {
    for (auto i = C-1; i >= 0; --i) {
      for (auto j = C-1; j >= 0; --j) {
        if (DP[i][j] < infty) {
          int newi = i + a[t];
          int newj = j + b[t];
          if (newi < C && newj < C) {
            DP[newi][newj] = min(DP[newi][newj], DP[i][j] + c[t]);
          }
        }
      }
    }
  }
  int ans = infty;
  for (auto i = 1; i < C; ++i) {
    for (auto j = 1; j < C; ++j) {
      if (i * Mb == j * Ma) {
        ans = min(ans, DP[i][j]);
      }
    }
  }
  for (auto i = 0; i < 40; ++i) {
    for (auto j = 0; j < 40; ++j) {
      cerr << DP[i][j] << " "; 
    }
    cerr << endl;
  }
  if (ans == infty) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
