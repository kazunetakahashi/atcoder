/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-6-10 21:11:33
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

int N, C;
ll D[40][40];
ll c[510][510];
ll total[3][40];

int main()
{
  cin >> N >> C;
  for (auto i = 0; i < C; i++)
  {
    for (auto j = 0; j < C; j++)
    {
      cin >> D[i][j];
    }
  }
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  fill(&total[0][0], &total[0][0] + 3 * 40, 0);
  for (auto i = 0; i < C; i++)
  {
    for (auto x = 0; x < N; x++)
    {
      for (auto y = 0; y < N; y++)
      {
        total[(x + y) % 3][i] += D[c[x][y]][i];
      }
    }
  }
  ll ans = 100000009907;
  for (auto i = 0; i < C; i++)
  {
    for (auto j = 0; j < C; j++)
    {
      if (i == j)
        continue;
      for (auto k = 0; k < C; k++)
      {
        if (i == k || j == k)
          continue;
        ll sum = 0;
        sum = total[0][i] + total[1][j] + total[2][k];
        ans = min(ans, sum);
      }
    }
  }
  cout << ans << endl;
}