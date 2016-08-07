#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

const int C = 100010;
const int X = 18;
vector<int> V[C];
int parent[X][C];
int depth[C];

// http://intsawadan.hatenablog.com/entry/2014/12/24/161622 を参考にした

typedef tuple<int, int, int> state;

void init(int n) {
  stack<state> S;
  S.push(make_tuple(0, -1, 0));
  fill(depth, depth+n, -1);
  while (!S.empty()) {
    int src = get<0>(S.top());
    int p = get<1>(S.top());
    int d = get<2>(S.top());
    S.pop();
    if (depth[src] == -1) {
      depth[src] = d;
      parent[0][src] = p;
      for (auto x : V[src]) {
        if (depth[x] == -1) {
          S.push(make_tuple(x, src, d+1));
        }
      }
    }
  }
  for (auto i = 0; i < X-1; i++) {
    for (auto j = 0; j < n; j++) {
      if (parent[i][j] < 0) {
        parent[i+1][j] = -1;
      } else {
        parent[i+1][j] = parent[i][parent[i][j]];
      }
    }
  }
}

int lca(int u, int v) {
  if (depth[u] > depth[v]) {
    swap(u, v);
  }
  for (auto i = 0; i < X; i++) {
    if ((depth[v] - depth[u]) >> i & 1) {
      v = parent[i][v];
    }
  }
  if (u == v) {
    return u;
  }
  for (auto i = X-1; i >= 0; i--) {
    if (parent[i][u] != parent[i][v]) {
      u = parent[i][u];
      v = parent[i][v];
    }
  }
  return parent[0][u];
}

typedef long long ll;
ll ans[5][100010];
ll red[100010];


int main() {
  int N, M;
  cin >> N >> M;
  int A[100010], B[100010];
  for (auto i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    V[A[i]].push_back(B[i]);
    V[B[i]].push_back(A[i]);
  }
  init(N);
  for (auto i = 0; i < N; i++) {
    cerr << "parent[0][" << i << "] = " << parent[0][i] << endl;
    cerr << "depth[" << i << "] = " << depth[i] << endl;
  }
  fill(&ans[0][0], &ans[0][0]+4*100010, 0);
  for (auto i = 0; i < N; i++) {
    ans[0][i] = 1;
    ans[1][i] = V[i].size();
  }
  for (auto k = 2; k <= 4; k++) {
    for (auto i = 0; i < N; i++) {
      for (auto x : V[i]) {
        ans[k][i] += ans[k-1][x] - ans[k-2][i];
        if (k >= 3) ans[k][i] += ans[k-3][x];
        if (k >= 4) ans[k][i] -= ans[k-4][i];
      }
      cerr << "ans[" << k << "][" << i << "] = " << ans[k][i] << endl;
    }
  }
  fill(red, red+100010, 0);
  for (auto i = 0; i < M; i++) {
    if (parent[0][A[i]] == B[i] || parent[0][B[i]] == A[i]) {
      continue;
    }
    int w[3];
    w[0] = lca(A[i], B[i]);
    w[1] = A[i];
    w[2] = B[i];
    cerr << "lca(" << A[i] << ", " << B[i] << ") = " << w[0] << endl;
    int t =  depth[w[1]] + depth[w[2]] - 2 * depth[w[0]] + 1;
    cerr << "t = " << t << endl;
    if (t == 3) {
      for (auto i = 0; i < 3; i++) {
        for (auto x : V[w[i]]) {
          if (x != w[(i+1)%3] && x != w[(i+2)%3]) {
            red[x] += (ll) 2;
          } else {
            red[x] += (ll) 1;
          }
        }
        red[w[i]] += (ll) 2 * (V[w[i]].size() - 1);
      }
    } else if (t == 4) {
      for (auto i = 0; i < 3; i++) {
        red[w[i]] += (ll) 1;
      }
      for (auto i = 1; i < 3; i++) {
        if (parent[0][w[i]] != w[0]) {
          red[parent[0][w[i]]] += (ll) 2;
        }
      }
    }
  }
  for (auto i = 0; i < N; i++) {
    cerr << "ans[4][" << i << "] = " << ans[4][i]
         << ", red[" << i << "] = " << red[i] << endl;
    cout << ans[4][i] - red[i] << endl;
  }
}
