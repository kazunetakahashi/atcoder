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
const ll MOD = 1000000007;

ll dp[310][310][310];
ll N, M;

int main () {
  cin >> N >> M;
  for (auto d = 0; d <= M; ++d) {
    for (auto i = 1; i <= d+1; ++i) {
      for (auto j = 0; i+j <= d+1; ++j) {
        dp[d][i][j] = 0;
      }
    }
  }
  dp[0][1][0] = 1;
  for (auto d = 0; d <= M; ++d) {
    for (auto i = 1; i <= d+1; ++i) {
      for (auto j = 0; i+j <= d+1; ++j) {
        dp[d+1][i][j+1] += (dp[d][i][j] * (N-i-j))%MOD;
        dp[d+1][i][j+1] %= MOD;
        dp[d+1][i][j] += (dp[d][i][j] * j)%MOD;
        dp[d+1][i][j] %= MOD;
        dp[d+1][i+j][0] += (dp[d][i][j] * i) %MOD;
        dp[d+1][i+j][0] %= MOD;
      }
    }
  }
  cout << dp[M][N][0] << endl;
}
