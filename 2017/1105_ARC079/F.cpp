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
int p[200010];
vector<int> V[200010];
bool visited[200010];
bool isloop[200010];
int memo[200010];

int calc(int v) {
  cerr << "v = " << v << endl;
  if (memo[v] != -1) return memo[v];
  set<int> S;
  for (auto x : V[v]) {
    S.insert(calc(x));
  }
  for (auto i = 0; ; ++i) {
    if (S.find(i) == S.end()) {
      return (memo[v] = i);
    }
  }
}

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> p[i];
    p[i]--;
  }
  for (auto i = 0; i < N; ++i) {
    V[p[i]].push_back(i);
  }
  fill(visited, visited+200010, false);
  int now = 0;
  while (!visited[now]) {
    visited[now] = true;
    now = p[now];
  }
  fill(isloop, isloop+200010, false);
  while (!isloop[now]) {
    isloop[now] = true;
    now = p[now];
  }
  cerr << "now = " << now << endl;
  fill(memo, memo+200010, -1);
  for (auto i = 0; i < N; ++i) {
    if (!isloop[i]) calc(i);
    cerr << "calc(" << i << ") = " << calc(i) << endl;
  }
  vector<int> kouho;
  set<int> S;
  for (auto x : V[now]) {
    if (!isloop[x]) {
      S.insert(calc(x));
    }
  }  
  for (auto i = 0; ; ++i) {
    if (S.find(i) == S.end()) {
      kouho.push_back(i);
      if (kouho.size() == 2) break;
    }
  }
  cerr << "kouho: ";
  for (auto x : kouho) {
    cerr << x << " ";
  }
  cerr << endl;
  for (auto z : kouho) {
    for (auto i = 0; i < N; ++i) {
      if (isloop[i]) memo[now] = -1;
    }
    memo[now] = z;
    for (auto i = 0; i < N; ++i) {
      if (isloop[i] && i != now) calc(i);
    }
    memo[now] = -1;
    if (calc(now) == z) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
