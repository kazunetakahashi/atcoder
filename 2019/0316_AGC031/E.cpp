#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-31 23:21:39
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

typedef tuple<ll, int> Info;

struct Edge
{
  int to;
  ll cap, cost;
  int rev;
};

class MinCostFlow
{
  int N;
  vector<Edge> *G;
  ll *h, *dist;
  int *prev_v, *prev_e;
  ll INFTY = 10000000000000010;

public:
  MinCostFlow() {}

  MinCostFlow(int n) : N(n)
  {
    G = new vector<Edge>[n];
    h = new ll[n];
    dist = new ll[n];
    prev_v = new int[n];
    prev_e = new int[n];
  }

  void add_edge(int from, int to, ll cap, ll cost)
  {
    G[from].push_back((Edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((Edge){from, 0, -cost, (int)G[from].size() - 1});
  }

  ll min_cost_flow(int s, int t, ll f)
  {
    ll res = 0;
    fill(h, h + N, 0);
    while (f > 0)
    {
      priority_queue<Info, vector<Info>, greater<Info>> Q;
      fill(dist, dist + N, INFTY);
      dist[s] = 0;
      Q.push(Info(0, s));
      while (!Q.empty())
      {
        Info p = Q.top();
        Q.pop();
        int v = get<1>(p);
        if (dist[v] < get<0>(p))
        {
          continue;
        }
        for (auto i = 0; i < (int)G[v].size(); i++)
        {
          Edge &e = G[v][i];
          ll tmp = dist[v] + e.cost + h[v] - h[e.to];
          if (e.cap > 0 && dist[e.to] > tmp)
          {
            dist[e.to] = tmp;
            prev_v[e.to] = v;
            prev_e[e.to] = i;
            Q.push(Info(dist[e.to], e.to));
          }
        }
      }
      if (dist[t] == INFTY)
      {
        return -1;
      }
      for (auto v = 0; v < N; v++)
      {
        h[v] += dist[v];
      }
      ll d = f;
      for (auto v = t; v != s; v = prev_v[v])
      {
        d = min(d, G[prev_v[v]][prev_e[v]].cap);
      }
      f -= d;
      res += d * h[t];
      for (auto v = t; v != s; v = prev_v[v])
      {
        Edge &e = G[prev_v[v]][prev_e[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};

int N;
int x[100], y[100];
ll v[100];
int M;
char t[400];
int a[400];
int b[400];
int K;
MinCostFlow flow;
ll C = 1000000000000010;

ll ans = 0;

void solve()
{
  vector<int> lx(K, -1);
  vector<int> rx(K, 101);
  vector<int> ly(K, -1);
  vector<int> ry(K, 101);
  for (auto i = 0; i < M; i++)
  {
    if (t[i] == 'L')
    {
      for (auto j = b[i]; j < K; j++)
      {
        lx[j] = max(lx[j], a[i]);
      }
    }
    else if (t[i] == 'R')
    {
      for (auto j = 0; j < K - b[i] - 1; j++)
      {
        rx[j] = min(rx[j], a[i]);
      }
    }
    else if (t[i] == 'D')
    {
      for (auto j = b[i]; j < K; j++)
      {
        ly[j] = max(ly[j], a[i]);
      }
    }
    else if (t[i] == 'U')
    {
      for (auto j = 0; j < K - b[i] - 1; j++)
      {
        ry[j] = min(ry[j], a[i]);
      }
    }
    else
    {
      assert(false);
    }
  }
#if DEBUG == 1
  cerr << "K = " << K << endl;
  for (auto i = 0; i < K; i++)
  {
    cerr << "lx[" << i << "] = " << lx[i] << ", rx[" << i << "] = " << rx[i] << endl;
  }
  for (auto i = 0; i < K; i++)
  {
    cerr << "ly[" << i << "] = " << ly[i] << ", ry[" << i << "] = " << ry[i] << endl;
  }
#endif
  flow = MinCostFlow(402);
  for (auto i = 0; i < K; i++)
  {
    flow.add_edge(400, i, 1, 0);
  }
  for (auto i = 0; i < K; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (lx[i] < x[j] && x[j] < rx[i])
      {
        flow.add_edge(i, 100 + j, 1, 0);
      }
    }
  }
  for (auto j = 0; j < N; j++)
  {
    flow.add_edge(100 + j, 200 + j, 1, C - v[j]);
  }
  for (auto i = 0; i < K; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (ly[i] < y[j] && y[j] < ry[i])
      {
        flow.add_edge(200 + j, 300 + i, 1, 0);
      }
    }
  }
  for (auto i = 0; i < K; i++)
  {
    flow.add_edge(300 + i, 401, 1, 0);
  }
  ll X = flow.min_cost_flow(400, 401, K);
  if (X >= 0)
  {
    ans = max(ans, C * K - X);
  }
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> x[i] >> y[i] >> v[i];
  }
  cin >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> t[i] >> a[i] >> b[i];
  }
  for (K = 1; K <= N; K++)
  {
    solve();
  }
  cout << ans << endl;
}