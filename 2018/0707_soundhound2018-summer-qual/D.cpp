/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-7 21:58:13
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
// const ll M = 1000000007;

typedef tuple<ll, int> P;

int N, M;
int S[2];
vector<P> V[2][100010];
priority_queue<P, vector<P>, greater<P>> Q[2];
ll dist[2][100010];
ll ans[100010];

int main()
{
  cin >> N >> M >> S[0] >> S[1];
  S[0]--;
  S[1]--;
  for (auto i = 0; i < M; i++)
  {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    V[0][u].push_back(P(a, v));
    V[1][v].push_back(P(b, u));
  }
  fill(&dist[0][0], &dist[0][0] + 2 * 100010, -1);
  for (auto k = 0; k < 2; k++)
  {
    Q[k].push(P(0, S[k]));
    while (!Q[k].empty())
    {
      ll d = get<0>(Q[k].top());
      int now = get<1>(Q[k].top());
      Q[k].pop();
      if (dist[k][now] == -1)
      {
        dist[k][now] = d;
        for (auto x : V[2][now])
        {
          ll new_d = get<0>(x);
          int dst = get<1>(x);
          if (dist[k][dst] == -1)
          {
            Q[k].push(P(d + new_d, dst));
          }
        }
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    ans[i] = dist[0][i] + dist[1][i];
  }
  for (auto i = N - 1; i >= 1; i--)
  {
    ans[i - 1] = min(ans[i - 1], ans[i]);
  }
  ll shoki = 1000000000000000;
  for (auto i = 0; i < N; i++)
  {
    cout << shoki - ans[i] << endl;
  }
}