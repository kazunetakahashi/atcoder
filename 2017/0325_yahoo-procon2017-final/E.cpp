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

class UnionFind {
public:
  int N;
  int* root;
  int* rank;

  UnionFind(int n) : N(n) {
    root = new int[N];
    rank = new int[N];
    for (auto i = 0; i < N; ++i) {
      root[i] = i;
      rank[i] = 0;
    }
  }

  ~UnionFind() {
    delete[] root;
    delete[] rank;
  }

  int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      root[x] = y;
    } else {
      root[y] = x;
      if (rank[x] == rank[y]) ++(rank[x]);
    }
  }

  bool same(int x, int y) {
    return (find(x) == find(y));
  }
};

class Edge {
public:
  int src, dst;
  ll cost;
  Edge(int s, int d, ll c)
    : src(s), dst(d), cost(c) {}
  friend bool operator<(const Edge& x, const Edge& y) {
    return x.cost < y.cost;
  }
  friend bool operator>(const Edge& x, const Edge& y) {
    return x.cost > y.cost;
  }
};

typedef Edge State;

class Graph {
public:
  static const ll infty = 100000000000000000;
  int N;
  vector<Edge>* V;
  vector<Edge> edges;
  // dfs
  vector<int> dfs_start;
  int* dfs_visited;
  int* dfs_from;
  int dfs_time;
  int* dfs_time_d;
  int* dfs_time_f;
  // dfs で 連結成分を求める
  int* component;
  vector< vector<int> > c_components;
  // bfs
  vector<int> bfs_start;
  int* bfs_visited;
  int* bfs_from;
  ll* bfs_dist;
  // kruskal
  ll kruskal_cost;
  vector<Edge>* kruskal_V;
  vector<Edge> kruskal_W;
  // bellman_ford, dijkstra
  set<int> sh_start;
  ll** sh_dist;
  int** sh_prev;

  Graph(int n)
    : N(n), dfs_time(0), kruskal_cost(-1) {
    V = new vector<Edge>[N];
    component = new int[N];
    dfs_visited = new int[N];
    fill(dfs_visited, dfs_visited+N, 0);
    dfs_from = new int[N];
    dfs_time_d = new int[N];
    dfs_time_f = new int[N];
    bfs_visited = new int[N];
    fill(bfs_visited, bfs_visited+N, 0);
    bfs_from = new int[N];    
    bfs_dist = new ll[N];
    kruskal_V = new vector<Edge>[N];
    sh_dist = new ll*[N];
    sh_prev = new int*[N];    
  }
  ~Graph() {
    delete[] V;
    delete[] component;
    delete[] dfs_visited;
    delete[] dfs_from;
    delete[] dfs_time_d;
    delete[] dfs_time_f;
    delete[] bfs_visited;
    delete[] bfs_from;
    delete[] bfs_dist;
    delete[] kruskal_V;
    for (auto x : sh_start) {
      delete[] sh_dist[x];
      delete[] sh_prev[x];
    }
    delete[] sh_dist;
    delete[] sh_prev;
  }

  void add_edge(int src, int dst, ll cost = 1) {
    Edge e(src, dst, cost);
    V[src].push_back(e);
    edges.push_back(e);
  }
  
  vector<int> dfs(int start) {
    vector<int> ans;
    stack<State> S;
    S.push(State(-1, start, 0));
    dfs_start.push_back(start);
    while (!S.empty()) {
      State s = S.top();
      S.pop();
      if (dfs_visited[s.dst] == 0) {
        dfs_visited[s.dst] = 1;
        dfs_time_d[s.dst] = dfs_time++;
        dfs_from[s.dst] = s.src;
        component[s.dst] = start;
        ans.push_back(s.dst);
        S.push(s);
        for (auto x : V[s.dst]) {
          if (dfs_visited[x.dst] == 0) {
            S.push(State(s.dst, x.dst, s.cost + x.cost));
          }
        }
      } else if (dfs_visited[s.dst] == 1) {
        dfs_visited[s.dst] = 2;
        dfs_time_f[s.dst] = dfs_time++;
      }
    }
    return ans;
  }

  void make_c_components() {
    for (auto i = 0; i < N; ++i) {
      if (dfs_visited[i] > 0) continue;
      c_components.push_back(dfs(i));
    }
  }

  bool is_connected(int s, int t) {
    if (dfs_visited[s] == 0 || dfs_visited[t] == 0) {
      make_c_components();
    }
    return (component[s] == component[t]);
  }
  
  void bfs() {
    assert(!bfs_start.empty());
    queue<State> Q;
    for (auto x : bfs_start) {
      Q.push(State(-1, x, 0));
    }
    while (!Q.empty()) {
      State s = Q.front();
      Q.pop();
      if (bfs_visited[s.dst] == 0) {
        bfs_visited[s.dst] = 1;
        bfs_from[s.dst] = s.src;
        bfs_dist[s.dst] = s.cost;
        for (auto x : V[s.dst]) {
          if (bfs_visited[x.dst] == 0) {
            Q.push(State(s.dst, x.dst, s.cost + x.cost));
          }
        }
      }
    }
  }

  int kruskal() {
    if (kruskal_cost != -1) return kruskal_cost;
    sort(edges.begin(), edges.end());
    UnionFind u(N);
    int kruskal_cost = 0;
    for (auto e : edges) {
      if (!u.same(e.src, e.dst)) {
        kruskal_V[e.src].push_back(e);
        kruskal_W.push_back(e);
        u.unite(e.src, e.dst);
        kruskal_cost += e.cost;
      }
    }
    return kruskal_cost;
  }

  void new_sh_dist(int i) {
    if (sh_start.find(i) == sh_start.end()) {
      sh_dist[i] = new ll[N];
      sh_prev[i] = new int[N];
      sh_start.insert(i);
    }
  }
  
  void bellman_ford(int s) {
    new_sh_dist(s);
    for (auto i = 0; i < N; ++i) {
      sh_dist[s][i] = infty;
    }
    sh_dist[s][s] = 0;
    sh_prev[s][s] = -1;
    while (true) {
      bool update = false;
      for (auto e : edges) {
        if (sh_dist[s][e.src] != infty
            && sh_dist[s][e.dst] > sh_dist[s][e.src] + e.cost) {
          sh_dist[s][e.dst] = sh_dist[s][e.src] + e.cost;
          sh_prev[s][e.dst] = e.src;
          update = true;
        }
      }
      if (!update) break;
    }
  }

  void dijkstra(int s) {
    new_sh_dist(s);
    for (auto i = 0; i < N; ++i) {
      sh_dist[s][i] = infty;
    }
    priority_queue<Edge, vector<Edge>, greater<Edge> > Q;
    Q.push(State(-1, s, 0));
    while (!Q.empty()) {
      State now = Q.top();
      Q.pop();
      if (sh_dist[s][now.dst] == infty) {
        sh_dist[s][now.dst] = now.cost;
        sh_prev[s][now.dst] = now.src;
        for (auto e : V[now.dst]) {
          if (sh_dist[s][e.dst] == infty) {
            Q.push(State(e.src, e.dst, e.cost + now.cost));
          }
        }
      }
    }
  }

  vector<int> get_shortest_path(int s, int t) {
    vector<int> path;
    for (; t != -1; t = sh_prev[s][t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
  }
  
};

typedef tuple<int, int> query;
const int infty = 1000000007;

ll N, M, Q;
int a[100010];
int b[100010];
int c[100010];
int d[100010];

map<query, int> ans;
typedef tuple<int, int> pass;

void solve1();
void solve2();

void solve1() {
  Graph g(N);
  for (auto i = 0; i < N; ++i) {
    for (auto j = i+1; j < N; ++j) {
      if (ans.find(query(i, j)) == ans.end()) {
        g.add_edge(i, j);
        g.add_edge(j, i);
      }
    }
  }
  for (auto i = 0; i < N; ++i) {
    g.bfs_start = {i};
    fill(g.bfs_visited, g.bfs_visited, 0);
    fill(g.bfs_dist, g.bfs_dist, infty);
    g.bfs();
    for (auto j = i+1; j < N; ++j) {
      query q(i, j);
      if (ans.find(q) != ans.end()) {
        ans[q] = g.bfs_dist[j];
        if (ans[q] == infty) ans[q] = -1;
      }
    }
  }
}

void solve2() {
  set<pass> S;
  for (auto i = 0; i < N; ++i) {
    S.insert(pass(i, i));
  }
  for (auto i = 0; i < M; ++i) {
    S.insert(pass(a[i], b[i]));
    S.insert(pass(b[i], a[i]));
  }
  for (auto x : ans) {
    vector< vector<int> > V[2];
    V[0][0] = { get<0>(x.first) };
    V[1][0] = { get<1>(x.first) };
    vector<int> unused;
    int nokori = M;
    for (auto j = 0; j < N; ++j) {
      if (j != get<0>(x.first) && j != get<1>(x.first)) unused.push_back(j);
    }
    for (auto t = 0; ; ++t) {
      if (unused.empty()) {
        ans[x.first] = -1;
        break;
      }
      if (nokori < (ll)V[0][t].size() * (ll)V[1][t].size()) {
        ans[x.first] = t * 2;
        break;
      }
      for (auto y : V[0][t]) {
        for (auto z : V[1][t]) {
          if (S.find(pass(y, z)) == S.end()) {
            ans[x.first] = t * 2;
            goto EXIT;
          } else {
            --nokori;
          }
        }
      }
      if (nokori < (ll)unused.size() * (ll)(V[0][t].size() + V[1][t].size())) {
        ans[x.first] = t * 2 + 1;
        break;
      }
      for (auto z : unused) {
        for (auto k = 0; k < 2; ++k) {
          V[k][t+1] = {};
          for (auto y : V[k][t]) {
            if (S.find(pass(y, z)) == S.end()) {
              ans[x.first] = t * 2 + 1;
              goto EXIT;
            } else {
              --nokori;
              V[k][t+1].push_back()
            }            
          }
        }
      }
    }
  EXIT:
    continue;
  }
}

void puts_ans() {
  for (auto i = 0; i < Q; ++i) {
    cout << ans[query(c[i], d[i])] << endl;
  }
}

int main () {
  cin >> N >> M >> Q;
  for (auto i = 0; i < M; ++i) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    if (a[i] > b[i]) swap(a[i], b[i]);
  }
  for (auto i = 0; i < Q; ++i) {
    cin >> c[i] >> d[i];
    c[i]--;
    d[i]--;
    ans[query(c[i], d[i])] = infty;
  }
  if (N * (N-1)/2 - M < 100000) {
    solve1();
  } else {
    solve2();
  }
  puts_ans();
}
