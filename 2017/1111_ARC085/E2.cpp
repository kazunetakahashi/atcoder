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
const ll infty = 100000000000007;

int N;
int a[110];

const int S = 0;
const int T = 101;

struct edge {
  int to;
  ll cap;
  int rev;
};

bool visited[110];
vector<edge> V[110];

void add_edge(int from, int to, ll cap) {
  V[from].push_back(edge{to, cap, (int)V[to].size()});
  V[to].push_back(edge{from, 0, (int)V[from].size()-1});  
}

ll dfs(int src, int dst, ll f) {
  if (src == dst) return f;
  visited[src] = true;
  for (auto &x : V[src]) {
    if (!visited[x.to] && x.cap > 0) {
      ll d = dfs(x.to, dst, min(f, x.cap));
      if (d > 0) {
        x.cap -= d;
        V[x.to][x.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

ll max_flow(int src, int dst) {
  ll flow = 0;
  while (true) {
    fill(visited, visited+110, false);
    ll f = dfs(src, dst, infty);
    if (f == 0) return flow;
    flow += f;
  }
}

int main () {
  cin >> N;
  for (auto i = 1; i <= N; ++i) {
    cin >> a[i];
  }
  for (auto i = 1; i <= N; ++i) {
    for (auto j = 2; i*j <= N; ++j) {
      add_edge(i, i*j, infty);
    }
  }
  ll sum = 0;
  for (auto i = 1; i <= N; ++i) {
    if (a[i] > 0) {
      add_edge(i, T, a[i]);
      sum += a[i];
    } else if (a[i] < 0) {      
      add_edge(S, i, -a[i]);
    }
  }
  cout << sum - max_flow(S, T) << endl;
}
