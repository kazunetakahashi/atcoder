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
int A[2][110];
int sum[2][110];

int main () {
  cin >> N;
  for (auto i = 0; i < 2; ++i) {
    for (auto j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
  for (auto i = 0; i < 2; ++i) {
    for (auto j = 0; j < N; ++j) {
      sum[i][j] = A[i][j];
    }
  }
  for (auto j = 0; j < N-1; ++j) {
    sum[0][j+1] += sum[0][j];
  }
  for (auto j = 1; j < N; ++j) {
    sum[0][N-1-j] += sum[0][N-1-j+1];
  }
  int ans = 0;
  for (auto j = 0; j < N; ++j) {
    ans = max(ans, sum[0][j] + sum[1][j]);
  }
  cout << ans << endl;
}
