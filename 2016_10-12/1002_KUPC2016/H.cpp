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
typedef pair<ll, int> P;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;
const ll infty = 10000000000000007;

struct edge {
  int to;
  ll cap;
  ll cost;
  int rev;
};

int V;
vector<edge> G[1010];
ll h[1010];
ll dist[1010];
int prevv[1010];
int preve[1010];

void add_edge(int from, int to, ll cap, ll cost) {
  G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
  G[to].push_back((edge){from, 0, -cost, (int)G[from].size()});
}

ll min_cost_flow(int s, int t, ll f) {
  int res = 0;
  fill(h, h+V, 0);
  while (f > 0) {
    priority_queue<P, vector<P>, greater<P> > Q;
    fill(dist, dist+V, infty);
    dist[s] = 0;
    Q.push(P(0, s));
    while (!Q.empty()) {
      P p = Q.top();
      Q.pop();
      int v = p.second;
      if (dist[v] < p.first) continue;
      for (auto i = 0; i < (int)G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          Q.push(P(dist[e.to], e.to));
        }
      }
    }
    if (dist[t] == infty) return -1;
    for (auto v = 0; v < V; v++) {
      h[v] += dist[v];
    }
    ll d = f;
    for (auto v = t; v != s; v = prevv[v]) {
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * h[t];
    for (auto v = t; v != s; v = prevv[v]) {
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

ll A[1010];
ll B[1010];

int main () {
  int N;
  cin >> N;
  V = N+2;
  if (N > 1010) return 0;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (auto i = 0; i < N; i++) {
    cin >> B[i];
  }
  for (auto i = 0; i < N; i++) {
    add_edge(N, i, A[i], 0);
  }
  for (auto i = 0; i < N; i++) {
    add_edge(i, N+1, B[i], 0);
  }
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < N; j++) {
      if (i == j) continue;
      add_edge(i, j, infty, abs(i - j));
    }
  }
  ll sum = 0;
  for (auto i = 0; i < N; i++) {
    sum += B[i];
  }
  cout << min_cost_flow(N, N+1, sum) << endl;
  /*
  for (auto i = 0; i < V; i++) {
    for (auto x : G[i]) {
      cerr << i << " -> " << x.to << " : " << " cap = " << x.cap
           << ", cost = " << x.cost << endl;
    }
  }
  */
}
