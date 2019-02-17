#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2/17/2019, 2:03:40 PM
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const ll MOD = 1000000007;

ll N, K;
ll memo[100010];

ll power(int x)
{
  if (x < 0)
  {
    return 0;
  }
  assert(x < 100010);
  return memo[x];
}

ll DP[5010][5010];
ll DP2[5010][5010];

void init()
{
  memo[0] = 1;
  for (auto i = 1; i < 100010; i++)
  {
    memo[i] = memo[i - 1] * 2;
    memo[i] %= MOD;
  }
  for (auto i = 0; i < N; i++)
  {
    DP[0][i] = power(i - (K - 1));
  }
  DP2[0][0] = DP[0][0];
  for (auto i = 1; i < N; i++)
  {
    DP2[0][i] = DP2[0][i - 1] + DP[0][i];
    DP2[0][i] %= MOD;
  }
}

void flush()
{
#if DEBUG == 1
  if (N <= 10)
  {
    for (auto i = 0; i < N; i++)
    {
      for (auto j = 0; j < N; j++)
      {
        cerr << "DP[" << i << "][" << j << "] = " << DP[i][j] << endl;
      }
    }
  }
#endif
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    ans += DP[i][N - 1];
    ans %= MOD;
  }
  cout << ans << endl;
}

int main()
{
  cin >> N >> K;
  init();
  for (auto i = 1; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      DP[i][j] = 0;
      if (j > 0)
      {
        DP[i][j] += (DP2[i - 1][j - 1] * power(j - i - (K - 1))) % MOD;
      }
      DP[i][j] += (DP[i - 1][j] * power(j - i - (K - 2))) % MOD;
    }
    DP2[i][0] = DP[i][0];
    for (auto j = 1; j < N; j++)
    {
      DP2[i][j] = DP2[i][j - 1] + DP[i][j];
      DP2[i][j] %= MOD;
    }
  }
  flush();
}