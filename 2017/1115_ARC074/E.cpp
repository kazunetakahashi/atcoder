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

typedef tuple<int, int> state;

int N, M;
vector<state> V[310];

ll DP[310][310][310];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    V[r].push_back(state(l, x));
  }
  fill(&DP[0][0][0], &DP[0][0][0]+310*310*310, 0);
  DP[1][1][0] = 3;
  for (auto i = 1; i <= N; ++i) {
    for (auto e : V[i]) {
      int l = get<0>(e);
      int clr = get<1>(e);
      if (clr == 1) {
        for (auto j = l+1; j <= i; ++j) {
          for (auto k = 0; k < j; ++k) {
            DP[i][j][k] = 0;
          }
        }
      } else if (clr == 2) {
        for (auto j = 1; j <= i; ++j) {
          for (auto k = 0; k < j; ++k) {
            if (!(j > l && l >= k)) {
              DP[i][j][k] = 0;              
            }
          }
        }        
      } else {
        for (auto j = 1; j <= i; ++j) {
          for (auto k = l; k < j; ++k) {
            DP[i][j][k] = 0;
          }
        }        
      }
    }
    for (auto j = 1; j <= i; ++j) {
      for (auto k = 0; k < j; ++k) {
        cerr << "DP[" << i << "][" << j << "][" << k << "] = "
             << DP[i][j][k] << endl;
      }
    }
    if (i == N) break;
    for (auto j = 1; j <= i; ++j) {
      for (auto k = 0; k < j; ++k) {
        DP[i+1][j][k] += DP[i][j][k];
        DP[i+1][j][k] %= MOD;
        DP[i+1][i+1][k] += DP[i][j][k];
        DP[i+1][i+1][k] %= MOD;
        DP[i+1][i+1][j] += DP[i][j][k];
        DP[i+1][i+1][j] %= MOD;
      }
    }
  }
  ll sum = 0;
  for (auto j = 1; j <= N; ++j) {
    for (auto k = 0; k < j; ++k) {
      cerr << "DP[" << N << "][" << j << "][" << k << "] = "
           << DP[N][j][k] << endl;
      sum += DP[N][j][k];
      sum %= MOD;
    }
  }
  cout << sum << endl;
}
