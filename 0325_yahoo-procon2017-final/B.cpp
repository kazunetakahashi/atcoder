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
const ll infty = 1000000007;

int N, M;
ll K;
ll A[100010];
ll B[100010];

bool take(int p, int q, int k) {
  return (abs(p - q) <= k);
}

int cnt(int k, int x, int y) {
  if (x >= N || y >= M) return 0;
  if (take(A[x], B[y], k)) {
    return 1 + cnt(k, x+1, y+1);
  } else {
    if (A[x] < B[y]) {
      return cnt(k, x+1, y);
    } else {
      return cnt(k, x, y+1);
    }
  }
}

bool ok(int k) {
  return (cnt(k, 0, 0) >= K);
}

int main () {
  cin >> N >> M >> K;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A+N);
  for (auto i = 0; i < M; ++i) {
    cin >> B[i];
  }
  sort(B, B+M);
  ll lb = -1;
  ll ub = infty;
  while (ub - lb > 1) {
    ll t = (ub+lb)/2;
    if (ok(t)) {
      ub = t;
    } else {
      lb = t;
    }
  }
  cout << ub << endl;
}
