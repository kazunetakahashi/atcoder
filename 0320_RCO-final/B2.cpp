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
#include <chrono>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

random_device rd; mt19937 mt(rd());

int rand() {
  return mt()%5;
}

typedef long long ll;

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

class Point {
public:
  int x;
  int y;
  
  Point() : x(-1), y(-1) {};
  Point(int _x, int _y) : x(_x), y(_y) {};
  
  Point operator+() const { return *this; }
  Point operator-() const { return Point(-x, -y); }

  Point& operator+=(const Point& p) {
    x += p.x;
    y += p.y;
    return *this;
  }

  Point& operator-=(const Point& p) {
    x -= p.x;
    y -= p.y;
    return *this;
  }

  Point operator+(const Point& p) const {
    return Point(x + p.x, y + p.y);
  }
  
  Point operator-(const Point& p) const {
    return Point(x - p.x, y - p.y);
  }

  bool operator==(const Point& p) const {
    return (x == p.x && y == p.y);
  }

  bool operator!=(const Point& p) const {
    return !(*this == p);
  }

  bool operator<(const Point& p) const {
    if (x == p.x) return y < p.y;
    return x < p.x;
  }

  bool operator>(const Point& p) const {
    if (x == p.x) return y > p.y;
    return x > p.x;
  }

  int dist(const Point& p) const {
    return std::abs(x - p.x) + std::abs(y - p.y);
  }
  
};

class Grid : public Graph {
public:
  int H;
  int W;
  static const int dx[], dy[];
  
  Grid(int h, int w)
    : Graph(h*w), H(h), W(w) {}
  ~Grid() {}
  
  bool valid(int x, int y) {
    return (0 <= x && x < H && 0 <= y && y < W);
  }
  bool valid(Point p) {
    return valid(p.x, p.y);
  }

  int point_to_int(int x, int y) {
    return x * W + y;
  }
  int point_to_int(Point p) {
    return point_to_int(p.x, p.y);
  }
  
  static bool dammy_true(int x, int y, int z, int w) { return true; }
  static int dammy_one(int x, int y, int z, int w) { return 1; }
  
  void make_grid_graph(bool func(int, int, int, int) = dammy_true,
                       int func2(int, int, int, int) = dammy_one) {
    for (auto i = 0; i < H; ++i) {
      for (auto j = 0; j < W; ++j) {
        for (auto k = 0; k < 4; ++k) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (valid(x, y) && func(i, j, x, y)) {
            add_edge(point_to_int(i, j), point_to_int(x, y),
                     func2(i, j, x, y));
          }
        }
      }
    }
  }
};

const int Grid::dx[] = {1, 0, -1, 0};
const int Grid::dy[] = {0, 1, 0, -1};
Point DX[5] = {
  Point(1, 0),
  Point(0, 1),
  Point(-1, 0),
  Point(0, -1),
  Point(0, 0)
};
map<Point, string> PT;

// const int C = 1e6+10;
// const ll M = 1000000007;

int H, W, K, T;
Point X[450];
Point Y[450];
int L;
Point now[10010][450];
set<Point> S[10010];
string ans[10010];

std::chrono::system_clock::time_point start_t, end_t;

bool valid(Point p, int t) {
  return (0 <= p.x && p.x < H && 0 <= p.y && p.y < W
          && S[t].find(p) == S[t].end());
}

double time() {
  end_t = std::chrono::system_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end_t-start_t).count();
}

bool time_ok() {
  return (time() < 3800);
}

void make_ans(int t) {
  string& s = ans[t];
  s = "";
  for (auto i = 0; i < K; ++i) {
    Point x = now[t+1][i] - now[t][i];
    if (PT.find(x) != PT.end()) {
      s += PT[x];
    } else {
      s += "-";
    }
  }
}

void output() {
  cout << L << endl;
  for (auto i = 0; i < L; ++i) {
    cout << ans[i] << endl;
  }
}

int CARS = 29;
double MIN_P = 0.2;

int memo[10010];

void score() {
  double pd = 20;
  for (auto i = 0; i < K; ++i) {
    pd += Y[i].dist(now[L][i]);
  }
  double pt = 10 + 0.01 * L;
  memo[L] = 1e7/(pd * pt);
}

void solve() {
  set<int> moves;
  for (auto i = 0; i < CARS; ++i) {
    moves.insert(i);
  }
  for (L = 0; L < T; ++L) {
    if (!time_ok()) {
      return;
    }
    for (auto i = 0; i < K; ++i) {
      S[L+1].insert(now[L][i]);
    }
    int move_cars = 0;
    for (auto i : moves) {
      const Point& p = now[L][i];
      int d = p.dist(Y[i]);
      for (auto j = 0; j < 5; ++j) {
        Point q = p + DX[j];
        if (j == 4 || (valid(q, L+1) && q.dist(Y[i]) < d)) {
          now[L+1][i] = q;
          S[L+1].insert(q);
          if (j < 4) ++move_cars;
          break;
        }
      } 
    }
    for (auto i = 0; i < K; ++i) {
      if (moves.find(i) == moves.end()) {
        const Point& p = now[L][i];
        // int d = p.dist(Y[i]);
        bool used[5];
        fill(used, used+5, false);
        while (true) {
          int j = rand();
          Point q = p + DX[j];
          if (j == 4 || valid(q, L+1)) {
            now[L+1][i] = q;
            S[L+1].insert(q);
            break;
          }
        }
      }
    }
    make_ans(L);
    score();
    if (move_cars < CARS * MIN_P) {
      set<int> S;
      for (auto x : moves) {
        S.insert((x+CARS)%K);
      }
    }
  }
  int maxi = 0;
  int t = 0;
  for (auto i = 0; i < T; ++i) {
    if (maxi < memo[i]) {
      t = i;
    }
  }
}

int main () {
  start_t = std::chrono::system_clock::now();
  PT[Point(1, 0)] = "D";
  PT[Point(0, 1)] = "R";
  PT[Point(-1, 0)] = "U";
  PT[Point(0, -1)] = "L";
  PT[Point(0, 0)] = "-";
  cin >> H >> W >> K >> T;
  for (auto i = 0; i < K; ++i) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--; B--; C--; D--;
    X[i] = Point(A, B);
    now[0][i] = X[i];
    Y[i] = Point(C, D);
  }
  solve();
  output();
}
