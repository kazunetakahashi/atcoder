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

bool f[3][3];

int main () {
  int cnt = 0;
  for (auto i = 0; i < (1 << 9); ++i) {
    fill(&f[0][0], &f[0][0]+9, false);
    for (auto j = 0; j < 3; ++j) {
      for (auto k = 0; k < 3; ++k) {
        int t = j * 3 + k;
        if (((i >> t) & 1) == 1) {
          f[j][k] = true;
        }
      }
    }
    bool ok = true;
    for (auto j = 0; j < 1; ++j) {
      for (auto k = 0; k < 3; ++k) {
        if ((f[j][k] && f[j+1][k] && f[j+2][k])
            || (!f[j][k] && !f[j+1][k] && !f[j+2][k])) {
          ok = false;
        }
      }
    }
    for (auto j = 0; j < 1; ++j) {
      for (auto k = 0; k < 3; ++k) {
        if ((f[k][j] && f[k][j+1] && f[k][j+2])
            || (!f[k][j] && !f[k][j+1] && !f[k][j+2])) {
          ok = false;
        }
      }
    }
    for (auto j = 0; j < 1; ++j) {
      for (auto k = 0; k < 1; ++k) {
        if ((f[j][k] && f[j+1][k+1] && f[j+2][k+2])
            || (!f[j][k] && !f[j+1][k+1] && !f[j+2][k+2])) {
          ok = false;
        }
      }
    }
    for (auto j = 0; j < 1; ++j) {
      for (auto k = 0; k < 1; ++k) {
        if ((f[2-j][k] && f[1-j][k+1] && f[j][k+2])
            || (!f[2-j][k] && !f[1-j][k+1] && !f[j][k+2])) {
          ok = false;
        }
      }
    }
    if (ok) {
      cerr << "cnt = " << cnt++ << endl;
      for (auto j = 0; j < 3; ++j) {
        for (auto k = 0; k < 3; ++k) {
          cerr << (f[j][k] ? '0' : '1');
        }
        cerr << endl;
      }
    }
  }
}
