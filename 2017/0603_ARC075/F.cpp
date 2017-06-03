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

int S;

int rev(int n) {
  string s = to_string(n);
  while ((int)s.size() < S) {
    s = '0' + s;
  }
  reverse(s.begin(), s.end());
  return stoi(s);
}

int main () {
  int D;
  cin >> D;
  S = to_string(D).size();
  bool ok = false;
  int base;
  for (auto i = 1; i < 10000; ++i) {
    cerr << "i = " << i << ", rev(" << i << ") = " << rev(i) << endl;
    if (i + D == rev(i)) {
      base = i;
      ok = true;
    }
  }
  if (ok) {
    int ans = 0;
    for (auto i = 1; i < 10000; ++i) {
      int add = i + rev(i);
      int t = base + add;
      if (t + D == rev(t)) {
        ++ans;
      }
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}
