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

typedef tuple<double, ll, ll> person;

int N;
ll P;
person V[100010];

bool ok(int k) {
  ll white = 0;
  ll blue = 0;
  for (auto i = 0; i < k; ++i) {
    white += get<1>(V[i]);
  }
  for (auto i = k; i < N; ++i) {
    blue += get<2>(V[i]);
  }
  return (white * 100 >= P * (white + blue));
}

int main () {
  cin >> N >> P;
  for (auto i = 0; i < N; ++i) {
    ll w, b;
    cin >> w >> b;
    V[i] = person((double)w/(w+b), w, b);
  }
  sort(V, V+N);
  reverse(V, V+N);
  int lb = 0;
  int ub = N;
  while (ub - lb > 1) {
    int t = (ub+lb)/2;
    if (ok(t)) {
      ub = t;
    } else {
      lb = t;
    }
  }
  cout << ub << endl;
}
