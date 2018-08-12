/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-4 21:41:00
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

int N, M;
typedef tuple<int, int> P;
vector<P> V[1010][1010];
bool visited[1010][1010];

int rev(int k)
{
  string S = to_string(k);
  reverse(S.begin(), S.end());
  return stoi(S);
}

void path(int x, int y)
{
  int new_x = x;
  int new_y = y;
  if (x < y)
  {
    new_x = rev(new_x);
  }
  else
  {
    new_y = rev(new_y);
  }
  if (new_x < new_y)
  {
    new_y = new_y - new_x;
  }
  else
  {
    new_x = new_x - new_y;
  }
  V[new_x][new_y].push_back(P(x, y));
}

int main()
{
  cin >> N >> M;
  fill(&visited[0][0], &visited[0][0] + 1010 * 1010, false);
  for (auto i = 1; i <= 999; i++)
  {
    for (auto j = 1; j <= 999; j++)
    {
      path(i, j);
    }
  }
  queue<P> Q;
  for (auto i = 0; i <= 999; i++)
  {
    Q.push(P(i, 0));
    Q.push(P(0, i));
  }
  Q.push(P(0, 0));
  while (!Q.empty())
  {
    int x = get<0>(Q.front());
    int y = get<1>(Q.front());
    Q.pop();
    if (!visited[x][y])
    {
      visited[x][y] = true;
      for (auto e : V[x][y])
      {
        int new_x = get<0>(e);
        int new_y = get<1>(e);
        if (!visited[new_x][new_y])
        {
          Q.push(e);
        }
      }
    }
  }
  int ans = 0;
  for (auto i = 1; i <= N; i++)
  {
    for (auto j = 1; j <= N; j++)
    {
      if (!visited[i][j])
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
}