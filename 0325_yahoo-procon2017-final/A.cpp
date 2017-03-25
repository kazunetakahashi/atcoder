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

string Y = "yahoo";
string S;

int dp[5][100010];

void f5(int i, int j, int ii, int jj, int val) {
  dp[i%5][j] = min(dp[i%5][j], dp[ii%5][jj] + val);
}

int main() {
  cin >> S;
  int M = S.size();
  for (auto i = 0; i < 5; ++i) {
    for (auto j = 0; j < 100010; ++j) {
      dp[i][j] = infty;
    }
  }
  dp[0][0] = 0;
  for (auto j = 0; j < M; ++j) {
    for (auto i = 0; i < 11; ++i) {
      if (S[j] == Y[i%5]) {
        f5(i+1, j+1, i, j, 0);
      }
      f5(i+1, j+1, i, j, 1);
      f5(i+1, j, i, j, 1);
      f5(i, j+1, i, j, 1);
    }
  }
  cout << dp[0][M] << endl;
}
