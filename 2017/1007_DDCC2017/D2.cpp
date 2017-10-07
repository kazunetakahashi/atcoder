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
  bool x[110][110][4];
  for (auto i = 1; i < H/2+1; ++i) {
    for (auto j = 1; j < W/2+1; ++j) {
      x[i][j][0] = f[i-1][j-1];
      x[i][j][1] = f[H-1-i+1][j-1];
      x[i][j][2] = f[i-1][W-1-j+1];
      x[i][j][3] = f[H-1-i+1][W-1-j+1];
    }
  }
  for (auto k = 0; k < 4; ++k) {
    cerr << "k = " << k << endl;
    for (auto i = 1; i < H/2+1; ++i) {
      for (auto j = 1; j < W/2+1; ++j) {
        cerr << (x[i][j][k] ? 'S' : '.');
      }
      cerr << endl;
    }
  }
  ll dp[110][110];
  fill(&dp[0][0], &dp[0][0]+110*110, 0);
  for (auto i = 1; i < H/2+1; ++i) {
    for (auto j = 1; j < W/2+1; ++j) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1];
      int cnt = 0;
      for (auto k = 0; k < 4; ++k) {
        if (x[i][j][k]) cnt++;
      }
      if (cnt == 4) {
        dp[i][j] += A + B + max(A, B);
      } else if (cnt == 3) {
        dp[i][j] += max(A, B);
      } else if (cnt == 2) {
        if (x[i][j][0] == x[i][j][1] && x[i][j][2] == x[i][j][3]) {
          dp[i][j] += A;          
        } else if (x[i][j][0] == x[i][j][2] && x[i][j][1] == x[i][j][3]) {
          dp[i][j] += B;          
        }
      }
      cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    }
  }
  ll amari = 0;
  bool taisho[2] = {true, true};
  for (auto i = 0; i < H/2; ++i) {
    for (auto j = 0; j < W; ++j) {
      if (f[i][j] != f[H-i-1][j]) {
        taisho[0] = false;
      }
    }
  }
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W/2; ++j) {
      if (f[i][j] != f[i][W-j-1]) {
        taisho[1] = false;
      }
    }
  }
  if (taisho[0]) amari += A;
  if (taisho[1]) amari += B;
  return dp[H/2][W/2] - amari;
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
  cout << ans << endl;
}
