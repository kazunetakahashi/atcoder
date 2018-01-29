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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const ll infty = 10000000000000007;

struct edge {
  int to;
  ll cap;
  int rev;
};

vector<edge> G[100010];
bool used[100010];

void add_edge(int from, int to, ll cap) {
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){to, 0, (int)G[to].size()-1});
}

ll dfs(int v, int t, ll f) {
  if (v == t) return f;
  used[v] = true;
  for (auto& e : G[v]) {
    if (!used[e.to] && e.cap > 0) {
      ll d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

ll max_flow(int s, int t) {
  ll flow = 0;
  while (true) {
    fill(used, used+100010, false);
    ll f = dfs(s, t, infty);
    if (f == 0) return flow;
    flow += f;
  }
}

int R, C;
string S[100];
int src, dst;
int vertex = 0;

bool valid(int i, int j) {
  return (0 <= i && i < R && 0 <= j && j < C && S[i][j] == '.');
}

int num(int i, int j) {
  return i * C + j;
}

void add_edge_grid(int i, int j) {
  if (!valid(i, j)) return;
  int now = num(i, j);
  vertex++;
  if ((i+j) % 2 == 0) {
    for (auto k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (valid(x, y)) {
        add_edge(now, num(x, y), 1);
#if DEBUG == 1
        cerr << "add_edge(" << now << ", " << num(x, y) << ", 1)" << endl;
#endif
      }
    }
    add_edge(src, now, 1);
  } else {
    add_edge(now, dst, 1);
  }
}

int main () {
  cin >> R >> C;
  for (auto i = 0; i < R; ++i) {
    cin >> S[i];
  }
  src = R * C;
  dst = R * C + 1;
  for (auto i = 0; i < R; ++i) {
    for (auto j = 0; j < C; ++j) {
      add_edge_grid(i, j);
    }
  }
  ll maxi = max_flow(src, dst);
#if DEBUG == 1
  cerr << "vertex = " << vertex << endl;
  cerr << "maxi = " << maxi << endl;
#endif
  cout << vertex - maxi << endl;
}
