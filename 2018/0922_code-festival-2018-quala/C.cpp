/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 9/22/2018, 9:12:06 PM
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
const ll MOD = 1000000007;

int N, K;
ll A[100];
ll cnt[100];
ll DP[50][5010][2];

int main()
{
  cin >> N >> K;
  for (auto i = 1; i <= N; i++)
  {
    cin >> A[i];
  }
  for (auto i = 1; i <= N; i++)
  {
    cnt[i] = 0;
    while (A[i] > 0)
    {
      A[i] /= 2;
      cnt[i]++;
    }
  }
  DP[0][0][0] = 1;
  K = min(K, 5000);
  for (auto i = 1; i <= N; i++)
  {
    ll C = cnt[i];
    for (auto j = 0; j <= K; j++)
    {
      DP[i][j][0] = 0;
      int ind = j - 1;
      if (ind >= 0)
      {
        DP[i][j][0] += DP[i][ind][0];
        DP[i][j][0] %= MOD;
        DP[i][j][0] += MOD - DP[i - 1][ind][0];
        DP[i][j][0] %= MOD;
      }
      ind = j - 1 + C;
      if (0 <= ind && ind <= K)
      {
        DP[i][j][0] += DP[i][ind][0];
        DP[i][j][0] %= MOD;
      }
      DP[i][j][1] = 0;
      ind = j - 1;
      if (ind >= 0)
      {
        DP[i][j][1] += DP[i][ind][1];
        DP[i][j][1] %= MOD;
        DP[i][j][1] += MOD - DP[i - 1][ind][1];
        DP[i][j][1] %= MOD;
      }
      ind = j + C;
      if (0 <= ind && ind <= K)
      {
        DP[i][j][1] += DP[i][ind][1];
        DP[i][j][1] %= MOD;
      }
      ind = j - C;
      if (0 <= ind && ind <= K)
      {
        DP[i][j][1] += DP[i][ind][0];
        DP[i][j][1] %= MOD;
      }
    }
  }
  ll ans = DP[N][K][0];
  for (auto i = 0; i <= K; i++)
  {
    ans += DP[N][i][1];
    ans %= MOD;
  }
  cout << ans << endl;
}
