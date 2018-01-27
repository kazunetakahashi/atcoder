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

int R, C;
string S[50];

vector<vector<bool> > V[50];

void make_V() {
  vector<bool> emp;
  V[0].push_back(emp);
  for (auto k = 0; k < C; ++k) {
    if (S[0][k] == '.') {
      for (auto x : V[k]) {
        x.push_back(true);
        x.push_back(false);
        V[x.size()].push_back(x);
      }
    } else {
      for (auto x : V[k]) {
        x.push_back(false);
        V[x.size()].push_back(x);
      }
    }
  }
}
  
int main () {
  cin >> R >> C;
  for (auto i = 0; i < R; ++i) {
    cin >> S[i];
  }
  make_V();
  int ans = 0;
  for (auto x : V[C]) {
    bool f[50][50];
    for (auto i = 0; i < C; ++i) {
      f[0][i] = x[i];
    }
    for (auto i = 1; i < R; ++i) {
      for (auto j = 0; j < C; ++j) {
        if (!f[i-1][j] && (j == 0 || !f[i][j-1]) && S[i][j] == '.') {
          f[i][j] = true;
        } else {
          f[i][j] = false;
        }
      }
    }
    int tans = 0;
    for (auto i = 0; i < R; ++i) {
      for (auto j = 0; j < C; ++j) {
        if (f[i][j]) tans++;
      }
    }
    ans = max(ans, tans);
  }
  cout << ans << endl;
}
