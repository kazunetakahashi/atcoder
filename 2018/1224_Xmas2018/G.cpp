/**
 * File    : G.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-12-24 20:39:21
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

int T;
int H, W;
bool used[50][50];
typedef tuple<int, int> P;
map<P, P> M;
set<P> S;

void solve_subtask()
{
  cout << "Second" << endl;
  int r, c;
  while (cin >> r >> c && r >= 0 && c >= 0)
  {
    cout << H - r - 1 << " " << W - c - 1 << endl;
  }
}

void solve_normal()
{
  fill(&used[0][0], &used[0][0] + 50 * 50, false);
  M.clear();
  S.clear();
  if (H * W % 2 == 0)
  {
    cout << "Second" << endl;
  }
  else
  {
    cout << "First" << endl;
    cout << 0 << " " << 0 << endl;
    used[0][0] = true;
  }
  if (H % 2 == 1)
  {
    for (auto j = 0; j < W; j++)
    {
      for (auto i = 0; i < H; i++)
      {
        if (i % 2 != j % 2)
        {
          M[P(i, j)] = P(i + 1, j);
          M[P(i + 1, j)] = P(i, j);
          used[i][j] = true;
          used[i + 1][j] = true;
        }
      }
    }
  }
  else
  {
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        if (i % 2 != j % 2)
        {
          M[P(i, j)] = P(i, j + 1);
          M[P(i, j + 1)] = P(i, j);
          used[i][j] = true;
          used[i][j + 1] = true;
        }
      }
    }
  }
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      if (!used[i][j])
      {
        S.insert(P(i, j));
      }
    }
  }
  int r, c;
  while (cin >> r >> c && r >= 0 && c >= 0)
  {
    used[r][c] = true;
    P p = P(r, c);
    if (M.find(p) == M.end())
    {
      S.erase(S.find(p));
      auto q = S.begin();
      int x = get<0>(*q);
      int y = get<1>(*q);
      cout << x << " " << y << endl;
      used[x][y] = true;
      S.erase(q);
    }
    else
    {
      P q = M[p];
      int x = get<0>(q);
      int y = get<1>(q);
      cout << x << " " << y << endl;
      used[x][y] = true;
    }
  }
}

void solve()
{
  cin >> H >> W;
  if (H % 2 == 0 && W % 2 == 0)
  {
    solve_subtask();
  }
  else
  {
    solve_normal();
  }
}

int main()
{
  cin >> T;
  for (auto i = 0; i < T; i++)
  {
    solve();
  }
}