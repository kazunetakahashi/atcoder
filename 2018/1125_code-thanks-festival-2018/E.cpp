/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 11/25/2018, 12:14:31 PM
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
const ll M = 1000000007;

int T;
ll a[310];
ll DP[310][1000];

ll cnt(ll i, ll l)
{
  if (0 <= l && l <= a[i])
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  cin >> T;
  for (auto i = 1; i <= T; i++)
  {
    cin >> a[i];
  }
  for (auto i = 0; i < 1000; i++)
  {
    DP[0][i] = 0;
  }
  DP[0][0] = 1;
  for (auto i = 1; i <= T; i++)
  {
    for (auto j = 0; j < 1000; j++)
    {
      DP[i][j] = 0;
      for (auto k = 0; k <= min(2 * j, 999); k++)
      {
        DP[i][j] += DP[i - 1][k] * cnt(i, 2 * j - k);
        DP[i][j] %= M;
      }
    }
  }
  for (auto i = 0; i < 4; i++)
  {
    for (auto j = 0; j < 1000; j++)
    {
      cerr << "DP[" << i << "][" << j << "] = " << DP[i][j] << endl;
    }
  }
  ll ans = 0;
  for (auto i = 1; i <= T; i++)
  {
    if (a[i] > 0)
    {
      ans++;
    }
  }
  for (auto i = 1; i <= T; i++)
  {
    ans += DP[i][1];
    ans %= M;
  }
  cout << ans << endl;
}