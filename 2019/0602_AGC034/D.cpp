#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-3 02:41:46
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

/*
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}

void No()
{
  cout << "No" << endl;
  exit(0);
}
*/

/*
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
*/

// const ll MOD = 1000000007;

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

ll C = 1000000000010;

int N;
ll S = 0;
ll RX[1010], RY[1010], RC[1010];
ll BX[1010], BY[1010], BC[1010];
MinCostFlow flow;

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> RX[i] >> RY[i] >> RC[i];
  }
  for (auto i = 0; i < N; i++)
  {
    cin >> BX[i] >> BY[i] >> BC[i];
  }
  for (auto i = 0; i < N; i++)
  {
    S += RC[i];
  }
  flow = MinCostFlow(2010);
  for (auto i = 0; i < N; i++)
  {
    flow.add_edge(2000, i, RC[i], 0);
    flow.add_edge(i, 2001, RC[i], C - (RX[i] + RY[i]));
    flow.add_edge(i, 2002, RC[i], C - (-RX[i] + RY[i]));
    flow.add_edge(i, 2003, RC[i], C - (RX[i] - RY[i]));
    flow.add_edge(i, 2004, RC[i], C - (-RX[i] - RY[i]));
    flow.add_edge(2001, 1000 + i, BC[i], C + (BX[i] + BY[i]));
    flow.add_edge(2002, 1000 + i, BC[i], C + (-BX[i] + BY[i]));
    flow.add_edge(2003, 1000 + i, BC[i], C + (BX[i] - BY[i]));
    flow.add_edge(2004, 1000 + i, BC[i], C + (-BX[i] - BY[i]));
    flow.add_edge(1000 + i, 2005, BC[i], 0);
  }
  ll K = flow.min_cost_flow(2000, 2005, S);
  cout << S * C - K << endl;
}