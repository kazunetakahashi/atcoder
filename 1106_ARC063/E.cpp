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

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
const int infty = 1000000007;

int N;
vector<int> V[100010];
int K;
int X[100010];

struct condition {
  int max;
  int min;
  bool is_odd;
};

vector<condition> C[100010];
condition D[100010];

int parent[100010];
vector<int> children[100010];

bool ok_cond(int x, condition c) {
  bool odd = (x%2 == 1);
  if (c.is_odd != odd) {
    return false;
  }
  return (c.max >= x && x >= c.min);
}

bool ok(int t) {
  for (auto x : children[t]) {
    if (D[x].max == infty) {
      continue;
    } else {
      condition c;
      c.max = D[x].max + 1;
      c.min = D[x].min - 1;
      c.is_odd = !D[x].is_odd;
      C[t].push_back(c);
    }
  }
  if (X[t] != infty) {
    for (auto c : C[t]) {
      if (!ok_cond(X[t], c)) {
        return false;
      }
    }
    condition c;
    c.max = X[t];
    c.min = X[t];
    c.is_odd = (X[t]%2 == 1);
    D[t] = c;
    return true;
  } else if (C[t].empty()) {
    condition c;
    c.max = infty;
    c.min = infty;
    c.is_odd = true;
    D[t] = c;
    return true;
  } else {
    int maxi = C[t][0].max;
    int mini = C[t][0].min;
    bool is_odd = C[t][0].is_odd;
    for (auto c : C[t]) {
      maxi = min(maxi, c.max);
      mini = max(mini, c.min);
      if (is_odd != c.is_odd) return false;
    }
    if (maxi < mini) {
      return false;
    }
    condition c;
    c.max = maxi;
    c.min = mini;
    c.is_odd = is_odd;
    D[t] = c;    
    return true;
  }
}

int main () {
  cin >> N;
  for (auto i = 0; i < N-1; i++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    V[A].push_back(B);
    V[B].push_back(A);
  }
  cin >> K;
  fill(X, X+N, infty);
  for (auto i = 0; i < K; i++) {
    int v, p;
    cin >> v >> p;
    v--;
    X[v] = p;
  }
  fill(parent, parent+N, infty);
  stack< pair<int, int> > SS;
  SS.push(make_pair(0, -1));
  while (!SS.empty()) {
    pair<int, int> x = SS.top();
    int now = x.first;
    int par = x.second;
    SS.pop();
    if (parent[now] == infty) {
      parent[now] = par;
      if (par >= 0) children[par].push_back(now);
      for (auto y : V[now]) {
        if (parent[y] == infty) {
          SS.push(make_pair(y, now));
        }
      }
    }
  }
  vector<int> chi;
  for (auto i = 0; i < N; i++) {
    if (children[i].empty()) chi.push_back(i);
  }
  queue<int> Q;
  for (auto x : chi) {
    Q.push(x);
  }
  while(!Q.empty()) {
    
  }
}
