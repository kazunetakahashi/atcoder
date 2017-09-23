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

int H, W, D, d;

char c[4] = {'R', 'Y', 'G', 'B'};

int area(int x, int y) {
  int cnt = x/(d+1) + y/d;
  return cnt%2;
}

int which(int x, int y) {
  int nx = x % (d+1);
  int ny = y % d;
  if (nx + ny < d) {
    return 0;
  } else {
    return 1;
  }
}

int main () {
  cin >> H >> W >> D;
  d = (D+1)/2;
  int ans[510][510];
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      ans[i][j] = area(i, j) * 2 + which(i, j);
    }
  }
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      cout << c[ans[i][j]];
      if (j == W-1) {
        cout << endl;
      }
    }
  }
}
