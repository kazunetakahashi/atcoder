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

int N;
vector<string> a;

bool ok(vector<string> x) {
  for (auto y : x) {
    for (auto z : y) {
      if (z == '.') return false;
    }
  }
  return true;
}

vector<string> change(vector<string> x, int i, int j) {
  char c[100];
  for (auto k = 0; k < N; ++k) {
    c[k] = x[i][k];
  }
  for (auto k = 0; k < N; ++k) {
    x[k][j] = c[k];
  }
  return x;
}

int dfs(int d, vector<string> x) {
  if (ok(x)) return d;
  if (d > 5) return infty;
  int ans = infty;
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      vector<string> y = change(x, i, j);
      ans = min(ans, dfs(d+1, y));
    }
  }
  return ans;
}

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    string s;
    cin >> s;
    a.push_back(s);
  }
  assert(N <= 3);
  int ans = dfs(0, a);
  if (ans < infty) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}
