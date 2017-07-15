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
const int infty = 1000000007;

int N, M;
int edge[15][15];
int setcost[1 << 15];
int dp[1 << 15][15];

int main() {
  cin >> N >> M;
  fill(&edge[0][0], &edge[0][0]+15*15, infty);
  for (auto i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edge[a][b] = c;
    edge[b][a] = c;
  }
  for (auto i = 0; i < (1 << N); ++i) {
    for (auto j = 0; j < N; ++j) {
      if (((i >> j) & 1) == 0) continue;
      for (auto k = 0; k < N; ++k) {
        if (((i >> k) & 1) == 0) continue;
        setcost[i] += edge[j][k];
      }
    }
  }
  fill(&dp[0][0], &dp[0][0]+(1 << 15)*15, infty);
  dp[1][0] = 0;
  for (auto x = 0; x < (1 << N); ++x) {
    for (auto i = 0; i < N; ++i) {
      if (dp[x][i] >= infty) continue;
      for (auto j = 0; j < N; ++j) {
        if (((x >> j) & 1) == 1 ||
            edge[i][j] == infty) {
          continue;
        }
        int z = x | (1 << j);
        dp[z][j] = min(dp[z][j],
                       dp[x][i] + setcost[z] - setcost[x] - edge[i][j]);
      }
      int z = (((1 << N)-1)^x) & ((1 << N)-1); // all \setminus x
      int w = x - (1 << i); // x \setminus \{ i \} 
      for (auto y = z; y >= 0; --y) {
        y &= z;
        dp[x | y][i] = min(dp[x | y][i],
                           dp[x][i] + setcost[w | y] - setcost[w] - setcost[y]);
      }
    }
  }
  cout << dp[(1 << N)][N-1] << endl;
}
