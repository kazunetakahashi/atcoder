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

int H, W;
ll A, B;
bool f[210][210];

ll solve() {
  bool x[210][210];
  for (auto i = 0; i < 210; ++i) {
    for (auto j = 0; j < 210; ++j) {
      x[i][j] = f[i][j];
    }
  }
  for (auto i = 0; i < H/2; ++i) {
    for (auto j = 0; j < W; ++j) {
      if (x[i][j] == x[H-1-i][j]) {
        x[i][j] = false;
        x[H-1-i][j] = false;
      }
    }
  }
  ll ans = 0;
  for (auto i = 0; i < H/2; ++i) {
    for (auto j = 0; j < W; ++j) {
      if (x[i][j]) {
        ans += A;
      }
    }
  }
  for (auto i = 0; i < H/2; ++i) {
    for (auto j = 0; j < W/2; ++j) {
      if (x[i][j] != x[i][W-1-j]) {
        x[i][j] = false;
        x[i][W-1-j] = false;
      }
    }
  }
  for (auto i = 0; i < H/2; ++i) {
    for (auto j = 0; j < W/2; ++j) {
      if (x[i][j]) {
        ans += B;
      }
    }
  }
  return ans;
}

void rev() {
  bool t[210][210];
  fill(&t[0][0], &t[0][0]+210*210, false);
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      t[j][i] = f[i][j];
    }
  }
  for (auto i = 0; i < 210; ++i) {
    for (auto j = 0; j < 210; ++j) {
      f[i][j] = t[i][j];
    }
  }
  swap(H, W);
  swap(A, B);
}

int main () {
  cin >> H >> W >> A >> B;
  string m[210];
  for (auto i = 0; i < H; ++i) {
    cin >> m[i];
  }
  fill(&f[0][0], &f[0][0]+210*210, false);
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      f[i][j] = (m[i][j] == 'S');
    }
  }
  ll ans = solve();
  rev();
  ans = max(ans, solve());
  cout << ans << endl;
}
