/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-7 20:57:37
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
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
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
const ll infty = 1000000000000007;

typedef tuple<bool, ll> I;
typedef tuple<int, ll> P;
int n, m;
vector<P> V[100010];
I info[100010];
I nil = I(true, infty);
set<ll> value;

int main()
{
  cin >> n >> m;
  for (auto i = 0; i < m; i++)
  {
    int u, v;
    ll s;
    cin >> u >> v >> s;
    u--;
    v--;
    V[u].push_back(P(v, s));
    V[v].push_back(P(u, s));
  }
  fill(info, info + 100010, nil);
  info[0] = I(true, 0);
  queue<int> Q;
  Q.push(0);
  bool visited[100010];
  fill(visited, visited + 100010, false);
  while (!Q.empty())
  {
    int x = Q.front();
    Q.pop();
    if (!visited[x])
    {
      visited[x] = true;
      bool pm = get<0>(info[x]);
      ll v = get<1>(info[x]);
      for (auto e : V[x])
      {
        int y = get<0>(e);
        ll w = get<1>(e);
        if (info[y] == nil)
        {
          info[y] = I(!pm, w - v);
          Q.push(y);
        }
        else
        {
          bool pm2 = get<0>(info[y]);
          ll v2 = get<1>(info[y]);
          if (pm == pm2)
          {
            ll tmp = w - (v + v2);
            if (tmp % 2 != 0)
            {
              cout << 0 << endl;
              return 0;
            }
            tmp = tmp / 2;
            if (!pm)
            {
              tmp = -tmp;
            }
            if (tmp > 0)
            {
              value.insert(tmp);
              if ((int)value.size() > 1)
              {
                cout << 0 << endl;
                return 0;
              }
            }
          }
          else
          {
            if (info[y] != I(!pm, w - v))
            {
              cout << 0 << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  ll p_mini = infty;
  ll m_mini = infty;
  if ((int)value.size() == 1)
  {
    cout << 1 << endl;
    return 0;
  }
  for (auto i = 0; i < n; i++)
  {
    bool pm = get<0>(info[i]);
    ll v = get<1>(info[i]);
    // cerr << "info[" << i << "] = (" << pm << ", " << v << ")" << endl;
    if (pm)
    {
      p_mini = min(p_mini, v);
    }
    else
    {
      m_mini = min(m_mini, v);
    }
  }
  cerr << p_mini << " " << m_mini << endl;
  ll ans;
  if (p_mini >= 0)
  {
    ans = m_mini;
  }
  else
  {
    ans = m_mini + p_mini + 1;
  }
  cout << max(0ll, ans) << endl;
}