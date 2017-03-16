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

int N, K;
int A[100010];
string S[100010];
vector<string> V, W;
string ans;

bool solve() {
  if (W.empty()) {
    ans == "";
    return true;
  }
  char c = V[0][0];
  for (auto x : V) {
    if (x[0] != c) return false;
  }
  int ub = 100010;
  int lb = 1;
  while (ub - lb > 1) {
    int t = (ub + lb) / 2;
    string X = V[0].substr(0, t);
    // cerr << X << endl;
    bool ok = false;
    for (auto x : V) {
      if ((int)x.size() < t) goto EXIT;
      if (x.substr(0, t) != X) goto EXIT;      
    }
    ok = true;
  EXIT:
    if (ok) {
      lb = t;
    } else {
      ub = t;
    }
  }
  string X = V[0].substr(0, lb);
  // cerr << X << endl;
  for (auto x : W) {
    if (x.substr(0, lb) == X) return false;
  }
  bool ok = true;
  for (auto x : W) {
    if (x[0] == X[0]) {
      ok = false;
      break;
    }
  }
  if (ok) {
    ans = X.substr(0, 1);
    return true;
  }
  ub = lb;
  lb = 1;
  while (ub - lb > 1) {
    int t = (ub + lb) / 2;
    string Y = X.substr(0, t);
    bool ok = false;
    for (auto x : W) {
      if ((int)x.size() < t) continue;
      if (x.substr(0, t) == Y) goto EXIT2;      
    }
    ok = true;
  EXIT2:
    if (ok) {
      ub = t;
    } else {
      lb = t;
    }
  }
  ans = X.substr(0, ub);
  return true;
}

int main () {
  cin >> N >> K;
  set<int> set;
  for (auto i = 0; i < K; ++i) {
    cin >> A[i];
    A[i]--;
    set.insert(A[i]);
  }
  for (auto i = 0; i < N; ++i) {
    cin >> S[i];
    if (set.find(i) != set.end()) {
      V.push_back(S[i]);
      // cerr << "V : " << S[i] << endl;
    } else {
      W.push_back(S[i]);
      // cerr << "W : " << S[i] << endl;
    }
  }
  if (solve()) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}
