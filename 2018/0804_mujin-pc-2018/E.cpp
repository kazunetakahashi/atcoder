/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-4 22:09:58
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char ds[4] = {'D', 'R', 'U', 'L'};

typedef tuple<ll, int, int> state;

// const int C = 1e6+10;
const ll infty = 1000000007;

int N, M, K;
string D;
string S[1010];
ll dist[200010][4];
ll ans[1010][1010];

int main()
{
  cin >> N >> M >> K;
  cin >> D;
  D = D + D + D;
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  for (auto k = 0; k < 4; k++)
  {
    dist[2 * K][k] = infty;
  }
  for (int i = 2 * K - 1; i >= 0; i--)
  {
    for (auto k = 0; k < 4; k++)
    {
      if (D[i + 1] == ds[k])
      {
        dist[i][k] = 1;
      }
      else
      {
        dist[i][k] = dist[i + 1][k] + 1;
      }
    }
  }
  for (auto i = 0; i < K; i++)
  {
    for (auto k = 0; k < 4; k++)
    {
      cerr << "dist[" << i << "][" << k << "] = " << dist[i][k] << endl;
    }
  }
  int sx, sy, gx, gy;
  fill(&ans[0][0], &ans[0][0] + 1010 * 1010, -1);
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < M; j++)
    {
      if (S[i][j] == 'S')
      {
        sx = i;
        sy = j;
      }
      else if (S[i][j] == 'G')
      {
        gx = i;
        gy = j;
      }
    }
  }
  priority_queue<state, vector<state>, greater<state>> Q;
  Q.push(state(0, sx, sy));
  while (!Q.empty())
  {
    ll d = get<0>(Q.top());
    int x = get<1>(Q.top());
    int y = get<2>(Q.top());
    Q.pop();
    if (ans[x][y] == -1)
    {
      ans[x][y] = d;
      cerr << "ans[" << x << "][" << y << "] = " << ans[x][y] << endl;
      if (x == gx && y == gy)
      {
        cout << d << endl;
        return 0;
      }
      for (auto k = 0; k < 4; k++)
      {
        int new_x = x + dx[k];
        int new_y = y + dy[k];
        if (0 <= new_x && new_x < N && 0 <= new_y && new_y < M && S[new_x][new_y] != '#' && ans[new_x][new_y] == -1)
        {
          ll new_d = d + dist[d % K][k];
          if (new_d < infty)
          {
            Q.push(state(new_d, new_x, new_y));
          }
        }
      }
    }
  }
  cout << -1 << endl;
}