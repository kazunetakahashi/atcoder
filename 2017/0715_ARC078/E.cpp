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
  cout << "? " << n << endl;
  char c;
  cin >> c;
  return (c == 'Y');
}

void answer(ll n) {
  cout << "! " << n << endl;
}

int main () {
  ll N = 0;
  while (N < 1000000000) {
    int ub = 9;
    int lb = ((N == 0) ? 0 : -1);
    while (ub - lb > 1) {
      int t = (ub + lb)/2;
      string str = to_string(N) + to_string(t) + "99999999";
      ll now = stoll(str);
      if (flush(now)) {
        ub = t;
      } else {
        lb = t;
      }
    }
    N = stoll(to_string(N) + to_string(ub));
  }
  while (N % 10 == 0) {
    if (flush(N/10 + 1)) {
      N = N/10;
    } else {
      break;
    }
  }
  answer(N);
}
