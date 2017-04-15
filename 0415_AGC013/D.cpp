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
const ll C = 1000000007;

int N, M;
ll dp[3010][3010][2];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    for (auto j = 0; j <= N; ++j) {
      for (auto k = 0; k < 2; ++k) {
        dp[i][j][k] = 0;
      }
    }
  }
  for (auto j = 0; j <= N; ++j) {
    if (j == 0) {
      dp[0][j][0] = 0;
      dp[0][j][1] = 1;        
    } else {
      dp[0][j][0] = 1;
      dp[0][j][1] = 0;
    }
  }
  for (auto i = 0; i < M; ++i) {
    for (auto j = 0; j <= N; ++j) {
      if (j == 1) {
        dp[i+1][j-1][1] += dp[i][j][0];
        dp[i+1][j-1][1] %= C;        
      } else if (j > 0) {
        dp[i+1][j-1][0] += dp[i][j][0];
        dp[i+1][j-1][0] %= C;    
      }
      if (j < N) {
        dp[i+1][j+1][0] += dp[i][j][0];
        dp[i+1][j+1][0] %= C;        
      }
      if (j == 1) {
        dp[i+1][j][1] += dp[i][j][0];
        dp[i+1][j][1] %= C;      
      } else if (j > 0) {
        dp[i+1][j][0] += dp[i][j][0];
        dp[i+1][j][0] %= C;        
      }
      if (j < N) {
        dp[i+1][j][0] += dp[i][j][0];
        dp[i+1][j][0] %= C;
      }
      if (j > 0) {
        dp[i+1][j-1][1] += dp[i][j][1];
        dp[i+1][j-1][1] %= C;        
      }
      if (j < N) {
        dp[i+1][j+1][1] += dp[i][j][1];
        dp[i+1][j+1][1] %= C;        
      }
      if (j > 0) {
        dp[i+1][j][1] += dp[i][j][1];
        dp[i+1][j][1] %= C;
      }
      if (j < N) {
        dp[i+1][j][1] += dp[i][j][1];
        dp[i+1][j][1] %= C;
      }
    }
  }
  ll ans = 0;
  for (auto j = 0; j <= N; ++j) {
    ans += dp[M][j][1];
    ans %= M;
  }
  cout << ans << endl;
}
