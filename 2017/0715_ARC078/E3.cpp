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

bool flush(ll n) {
  assert(1 <= n && n <= 1000000000000000000);
  cout << "? " << n << endl;
  char c;
  cin >> c;
  return (c == 'Y');
}

void answer(ll n) {
  assert(1 <= n && n <= 1000000000);
  cout << "! " << n << endl;
}

void solve1() {
  ll ask = 2;
  while (true) {
    if (flush(ask)) {
      answer(ask/2);
      return;
    } else {
      ask *= 10;
    }
  }
}

void solve2() {
  ll ask = 1e8;
  while (true) {
    if (flush(ask)) {
      break;
    } else {
      ask /= 10;
    }
  }
  ll lb = ask;
  ll ub = ask * 10 - 1;
  while (ub - lb > 1) {
    ll t = (ub + lb) / 2;
    if (flush(t * 10)) {
      ub = t;
    } else {
      lb = t;
    }
  }
  answer(ub);
}

int main () {
  if (flush(1e9)) {
    solve1();
  } else {
    solve2();
  }
}
