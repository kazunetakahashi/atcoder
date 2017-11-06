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

int N;
int s[120];

int memo[120][10];

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> s[i];
  }
  fill(&memo[0][0], &memo[0][0]+120*10, 0);
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < 10; ++j) {
      memo[i+1][j] = memo[i][j];
    }
    for (auto j = 0; j < 10; ++j) {
      int score = memo[i][j] + s[i];
      int shimo = score % 10;
      memo[i+1][shimo] = max(memo[i+1][shimo], score);
    }
  }
  memo[N][0] = 0;
  int maxi = 0;
  for (auto i = 0; i < 10; ++i) {
    maxi = max(maxi, memo[N][i]);
  }
  cout << maxi << endl;
}
