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

const int UFSIZE = 100010;
int union_find[UFSIZE];

void init() {
  for (auto i=0; i<UFSIZE; i++) {
    union_find[i] = i;
  }
}

int root(int a) {
  if (a == union_find[a]) return a;
  return (union_find[a] = root(union_find[a]));
}

bool issame(int a, int b) {
  return root(a) == root(b);
}

void unite(int a, int b) {
  union_find[root(a)] = root(b);
}

bool isroot(int a) {
  return root(a) == a;
}

int N, M;
int a[100010];
int b[100010];
int Q;
int x[100010];
int y[100010];
tuple<int, int> parent[100010];
int d[100010][20];
int depth[100010];
vector<int> V[100010];

int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (auto k = 0; k < 20; ++k) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = d[v][k];
    }
  }
  if (u == v) return u;
  for (auto k = 19; k >= 0; --k) {
    if (d[k][u] != d[k][v]) {
      u = d[u][k];
      v = d[v][k];
    }
  }
  return d[u][0];
}

int main() {
  // initが必要
  init();
  fill(&d[0][0], &d[0][0]+100010*20, -1);
  fill(parent, parent+100010, make_tuple(-1, 0));
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  cin >> Q;
  for (auto i = 0; i < Q; ++i) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  for (auto i = 0; i < M; ++i) {
    parent[root(a[i])] = make_tuple(root(b[i]), i);
    V[root(b[i])].push_back(root(a[i]));
    unite(a[i], b[i]);
  }
  for (auto i = 0; i < N; ++i) {
    d[i][0] = get<0>(parent[i]);
  }
  for (auto i = 1; i < 20; ++i) {
    for (auto j = 0; j < N; ++j) {
      if (d[j][i-1] >= 0) {
        d[j][i] = d[d[j][i-1]][i-1];
      }
    }
  }
  fill(depth, depth+100010, -1);
  for (auto i = 0; i < N; ++i) {
    if (d[i][0] == -1) {
      stack<tuple<int, int> > S;
      S.push(make_tuple(i, 0));
      while (!S.empty()) {
        int now = get<0>(S.top());
        int dep = get<1>(S.top());
        S.pop();
        if (depth[now] == -1) {
          depth[now] = dep;
          for (auto x : V[now]) {
            if (depth[x] == -1) {
              S.push(make_tuple(x, dep+1));
            }
          }
        }
      }
    }
  }
  for (auto i = 0; i < Q; ++i) {
    if (!issame(x[i], y[i])) {
      cout << -1 << endl;
    } else {
      int c = lca(x[i], y[i]);
      cout << get<1>(parent[c])+1 << endl;
    }
  }
}
