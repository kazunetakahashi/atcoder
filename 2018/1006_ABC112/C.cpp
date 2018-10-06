/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-6 21:04:55
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

int N;
int x[100010];
int y[100010];
int h[100010];

void solve(int X, int Y)
{
  int ans = -1;
  for (auto i = 0; i < N; i++)
  {
    int t = h[i] + abs(x[i] - X) + abs(y[i] - Y);
    if (t <= 0)
    {
      return;
    }
    if (h[i] > 0)
    {
      if (ans != -1)
      {
        if (ans != t)
        {
          return;
        }
      }
      else
      {
        ans = t;
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    int t = h[i] + abs(x[i] - X) + abs(y[i] - Y);
    if (h[i] == 0)
    {
      if (ans > t)
      {
        return;
      }
    }
  }
  cout << X << " " << Y << " " << ans << endl;
  exit(0);
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> x[i] >> y[i] >> h[i];
  }
  for (auto i = 0; i <= 100; i++)
  {
    for (auto j = 0; j <= 100; j++)
    {
      solve(i, j);
    }
  }
  assert(false);
}