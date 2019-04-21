#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-4-20 21:08:04
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
const ll M = 998244353;

int N;
int a[310];
int S = 0;
ll dp[310][90010];
ll DP[310][90010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
    S += a[i];
  }
  fill(&dp[0][0], &dp[0][0] + 310 * 90010, 0);
  dp[0][0] = 1;
  for (auto i = 0; i < N; i++)
  {
    for (auto v = 0; v < 90010; v++)
    {
      if (dp[i][v] == 0)
      {
        continue;
      }
      dp[i + 1][v + a[i]] += dp[i][v];
      dp[i + 1][v + a[i]] %= M;
      dp[i + 1][v] += 2 * dp[i][v];
      dp[i + 1][v] %= M;
    }
  }
  ll K = 0;
  for (auto v = (S + 1) / 2; v <= S; v++)
  {
    K += dp[N][v];
  }
  fill(&DP[0][0], &DP[0][0] + 310 * 90010, 0);
  DP[0][0] = 1;
  for (auto i = 0; i < N; i++)
  {
    for (auto v = 0; v < 90010; v++)
    {
      if (DP[i][v] == 0)
      {
        continue;
      }
      DP[i + 1][v + a[i]] += DP[i][v];
      DP[i + 1][v + a[i]] %= M;
      DP[i + 1][v] += DP[i][v];
      DP[i + 1][v] %= M;
    }
  }
  ll L = 0;
  if (S % 2 == 0)
  {
    L = DP[N][S / 2];
  }
  ll ans = 1;
  for (auto i = 0; i < N; i++)
  {
    ans *= 3LL;
    ans %= M;
  }
  ans += M - (3 * K) % M;
  ans %= M;
  ans += 3 * L;
  ans %= M;
  cout << ans << endl;
}