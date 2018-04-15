/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-15 22:15:59
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

#define DEBUG 1 // change 0 -> 1 if we need debug.

typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int H, W;
ll D[777][777][4];
ll ans[777][777];
string S[777];
typedef tuple<ll, int, int, int, ll> state; // dist, x, y, d, dist_before
priority_queue<state, vector<state>, greater<state> > Q;

bool valid(int x, int y, int d)
{
  return (0 <= x && x < H && 0 <= y && y < W && D[x][y][d] < 0);
}

int main()
{
  fill(&D[0][0][0], &D[0][0][0] + 777 * 777 * 4, -1);
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  int goal_x = -1, goal_y = -1;
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      if (S[i][j] == 'G')
      {
        goal_x = i;
        goal_y = j;
      }
    }
  }
  assert(goal_x >= 0 && goal_y >= 0);
  Q.push(state(0, goal_x, goal_y, 0, 0));
  while (!Q.empty())
  {
    ll dist = get<0>(Q.top());
    int x = get<1>(Q.top());
    int y = get<2>(Q.top());
    int d = get<3>(Q.top());
    ll dist_b = get<4>(Q.top());
    Q.pop();
    if (D[x][y][d] < 0)
    {
      if (S[x][y] == '.')
      {
        D[x][y][d] = dist;
#if DEBUG == 1
        cerr << "D[" << x << "][" << y << "][" << d << "] = " << D[x][y][d] << endl;
#endif
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (valid(nx, ny, d))
        {
          Q.push(state(dist + 1, nx, ny, d, dist_b + 1));
        }
      }
      else
      {
        for (auto k = 0; k < 4; k++)
        {
          D[x][y][k] = dist;
#if DEBUG == 1
          if (k == 0)
          {
            cerr << "D[" << x << "][" << y << "] = " << D[x][y][k] << endl;
          }
#endif
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (valid(nx, ny, k))
          {
            Q.push(state(dist + dist_b + 1, nx, ny, k, dist_b + 1));
          }
        }
      }
    }
  }
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      ans[i][j] = -1;
      for (auto k = 0; k < 4; k++)
      {
        if (D[i][j][k] >= 0)
        {
          if (ans[i][j] < 0)
          {
            ans[i][j] = D[i][j][k];
          }
          else
          {
            ans[i][j] = min(ans[i][j], D[i][j][k]);
          }
        }
      }
#if DEBUG == 0
      cout << ans[i][j];
      if (j < W - 1)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
#endif
    }
  }
}