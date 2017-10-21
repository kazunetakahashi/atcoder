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

int N;
int P[1010];
int X[1010];
vector<int> children[1010];

typedef pair<int, int> fruit;
fruit F[1010];
fruit empty = fruit(-1, -1);

bool judged = false;

fruit calc(int v) {
  if (F[v] != empty) return F[v];
  if (children[v].empty()) {
    F[v] = fruit(X[v], 0);
    // cerr << "F[" << v << "] = " << F[v].first << " " << F[v].second << endl;
    return F[v];
  }
  // cerr << "now = " << v << endl;
  int sum = 0;
  int allsum = 0;
  for (auto x : children[v]) {
    if (calc(x) == empty) return F[v] = empty;
    sum += calc(x).second;
    allsum += calc(x).first + calc(x).second;
  }
  if (sum > X[v]) {
    judged = true;
    return F[v] = empty;
  }
  int s = children[v].size();
  vector< set<int> > S(s+1);
  S[0].insert(0);
  for (auto i = 0; i < s; ++i) {
    int fir = calc(children[v][i]).first;
    int sec = calc(children[v][i]).second;
    for (auto x : S[i]) {
      if (x > X[v]) break;
      S[i+1].insert(x + fir);
      S[i+1].insert(x + sec);
    }
  }
  /*
  for (auto x : S[s]) {
    cerr << x << " ";
  }
  */
  auto it = S[s].upper_bound(X[v]);
  it--;
  F[v] = fruit(X[v], allsum-*it);
  if (F[v].first < F[v].second) swap(F[v].first, F[v].second);
  // cerr << "F[" << v << "] = " << F[v].first << " " << F[v].second << endl;
  return F[v];
}

int main () {
  cin >> N;
  for (auto i = 0; i < N-1; ++i) {
    cin >> P[i];
    P[i]--;
    children[P[i]].push_back(i+1);
  }
  /*
  for (auto i = 0; i < N; ++i) {
    cerr << "children[" << i << "] : ";
    for (auto x : children[i]) {
      cerr << x << " ";
    }
    cerr << endl;
  }
  */
  for (auto i = 0; i < N; ++i) {
    cin >> X[i];
  }
  for (auto i = 0; i < N; ++i) {
    F[i] = empty;
  }
  calc(0);
  if (judged) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << "POSSIBLE" << endl;
  }
}
