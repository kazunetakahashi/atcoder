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
// const ll M = 1000000007;

int A, B;

int solve() {
  if (A == 1 && B == 1) {
    return 2;
  }
  if (A == 1) {
    return 0;
  }
  if (B == 1) {
    return 1;
  }
  if (A == B) {
    return 2;
  }
  if (A < B) {
    return 1;
  }
  return 0;
}

int main () {
  cin >> A >> B;
  int s = solve();
  if (s == 0) {
    cout << "Alice" << endl;
  } else if (s == 1) {
    cout << "Bob" << endl;
  } else {
    cout << "Draw" << endl;
  }
}
