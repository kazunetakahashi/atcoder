#define DEBUG 1

/**
 * File    : E4.cpp
 * Author  : Kazune Takahashi
 * Created : 2/23/2019, 8:45:03 PM
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

ll p[100010];

ll power(ll x)
{
  if (x < 0)
  {
    return 1;
  }
  else
  {
    assert(x < 100010);
    return p[x];
  }
}

ll N, K;
ll dp[2][5010][5010];

int main()
{
  p[0] = 1;
  for (auto i = 1; i < 100010; i++)
  {
    p[i] = (2 * p[i - 1]) % MOD;
  }
  cin >> N >> K;
  fill(&dp[0][0][0], &dp[0][0][0] + 2 * 5010 * 5010, 0);
  dp[0][0][1] = 1;
  for (auto k = 1; k <= N; k++)
  {
    for (auto j = 0; j <= k; j++)
    {
      for (auto i = 0; i < 2; i++)
      {
#if DEBUG == 1
        if (N < 100)
        {
          cerr << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
        }
#endif
        if (dp[i][j][k] == 0)
        {
          continue;
        }
        dp[1 - i][k][k + 1] += dp[i][j][k];
        dp[1 - i][k][k + 1] %= MOD;
        dp[i][j][k + 1] += (power(k - j - K) * dp[i][j][k]) % MOD;
        dp[i][j][k + 1] %= MOD;
      }
    }
  }
  ll ans = 0;
  for (auto j = 0; j <= N; j++)
  {
    ans += dp[0][j][N + 1];
    ans %= MOD;
  }
  for (auto j = 0; j <= N; j++)
  {
    ans += MOD - dp[0][j][N + 1];
    ans %= MOD;
  }
  cout << ans << endl;
}