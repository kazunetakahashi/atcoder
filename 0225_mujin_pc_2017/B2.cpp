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

bool minus_one() {
  for (auto y : a) {
    for (auto z : y) {
      if (z == '#') return false;
    }
  }
  return true;
}

bool is_black(int k) {
  for (auto i = 0; i < N; ++i) {
    if (a[i][k] == '.') return false;
  }
  return true;
}

int need(int k) {
  bool ok = false;
  for (auto i = 0; i < N; ++i) {
    if (a[i][k] == '#') {
      ok = true;
      break;
    }
  }
  if (!ok) return infty;
  int ans = 0;
  for (auto i = 0; i < N; ++i) {
    if (a[k][i] == '.') ++ans;
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
  if (minus_one()) {
    cout << -1 << endl;
    return 0;
  }
  int black = 0;
  for (auto i = 0; i < N; ++i) {
    if (is_black(i)) ++black;
  }
  int n = infty;
  for (auto i = 0; i < N; ++i) {
    n = min(n, need(i));
  }
  assert(n < infty);
  cout << n + (N - black) << endl;
}
