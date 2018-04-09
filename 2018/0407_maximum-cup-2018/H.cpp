/**
 * File    : H.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-9 14:31:17
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const ll infty = 10000000000007;

int N, M;
ll d[310][310];
int K;
int a[310];
int Q;
int b[310];

struct edge {
  int to;
  ll cap;
  int rev;
};

const int start = 690;
const int goal = 691;

bool visited[700];
vector<edge> V[700];

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
    fill(visited, visited+700, false);
    ll f = dfs(src, dst, infty);
    if (f == 0) return flow;
    flow += f;
  }
}

bool solve(ll T)
{
  for (auto i = 0; i < 700; i++)
  {
    V[i].clear();
  }
  ll cnt = 0;
  for (auto i = 0; i < K - 1; i++)
  {
    add_edge(start, i, 1);
    if (d[a[i]][a[i+1]] > T)
    {
#if DEBUG == 1
      cerr << "d[" << a[i] << "][" << a[i + 1] << "] = "
           << d[a[i]][a[i + 1]] << endl;
#endif
      cnt++;
      for (auto j = 0; j < Q; j++)
      {
        if (d[a[i+1]][b[j]] <= T)
        {
          add_edge(i, j + K, 1);
        }
      }
    }
  }
  for (auto j = 0; j < Q; j++)
  {
    add_edge(j + K, goal, 1);
  }
  ll maxi = max_flow(start, goal);
#if DEBUG == 1
  cerr << "T = " << T << ", maxi = "
       << maxi << ", cnt = " << cnt << endl;
#endif
  return (maxi == cnt);
}

int main()
{
  cin >> N >> M;
  fill(&d[0][0], &d[0][0]+310*310, infty);
  for (auto i = 0; i < N; i++)
  {
    d[i][i] = 0;
  }
  for (auto i = 0; i < M; i++)
  {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    d[u][v] = d[v][u] = w;
  }
  cin >> K;
  for (auto i = 0; i < K; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  cin >> Q;
  bool have[310];
  fill(have, have+310, false);
  for (auto i = 0; i < Q; i++)
  {
    cin >> b[i];
    b[i]--;
    have[b[i]] = true;
  }
  bool zero = true;
  for (auto i = 1; i < K; i++)
  {
    if (!have[a[i]])
    {
      zero = false;
      break;
    }
  }
  if (zero)
  {
    cout << 0 << endl;
    return 0;
  }
  for (auto k = 0; k < N; k++)
  {
    for (auto i = 0; i < N; i++)
    {
      for (auto j = 0; j < N; j++)
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
#if DEBUG == 1
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cerr << "d[" << i << "][" << j << "] = " << d[i][j] << endl;
    }
  }
#endif
  ll ub = infty;
  ll lb = 0;
  while (ub - lb > 1)
  {
    ll T = (ub + lb) / 2;
    if (solve(T))
    {
      ub = T;
    }
    else
    {
      lb = T;
    }
  }
  cout << ub << endl;
}