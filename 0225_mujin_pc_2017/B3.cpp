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
typedef vector<vector<bool> > field;
field x;

bool minus_one() {
  for (auto y : a) {
    for (auto z : y) {
      if (z == '#') return false;
    }
  }
  return true;
}

void change(field& f, int i, int j) {
  vector<bool> c;
  for (auto k = 0; k < N; ++k) {
    c.push_back(f[i][k]);
  }
  for (auto k = 0; k < N; ++k) {
    f[k][j] = c[k];
  }
}

int answer(int k) {
  field y = x;
  bool ok = false;
  for (auto i = 0; i < N; ++i) {
    if (x[i][k]) ok = true;
  }
  if (!ok) return infty;
  for (auto i = 0; i < N; ++i) {
    
  }
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
  x = vector<vector<bool>>(N, vector<bool>(N, false));
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      x[i][j] = (a[i][j] == '#');
    }
  }
  
}
