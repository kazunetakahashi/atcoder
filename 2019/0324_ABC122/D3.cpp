#define DEBUG 1

/**
 * File    : D3.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-28 12:07:16
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
const ll M = 1000000007;

int N;
ll dp[110][4][4][4];

// A: 0, G: 1, C: 2, T: 3;

int main()
{
  cin >> N;
  fill(&dp[0][0][0][0], &dp[0][0][0][0] + 110 * 4 * 4 * 4, 0);
  dp[0][3][3][3] = 1;
  for (auto n = 0; n < N; n++)
  {
    for (auto i = 0; i < 4; i++)
    {
      for (auto j = 0; j < 4; j++)
      {
        for (auto k = 0; k < 4; k++)
        {
          if (dp[n][i][j][k] == 0)
          {
            continue;
          }
          for (auto a = 0; a < 4; a++)
          {
            // jia = 012, 102, 021 は continue;
            if ((j == 0 && i == 1 && a == 0) || (j == 1 && i == 0 && a == 2) || (j == 0 && i == 2 && a == 1))
            {
              continue;
            }
            // kjia = 0x12, 01x2 は continue;
            if ((k == 0 && i == 1 && a == 2) || (k == 0 && j == 1 && a == 2))
            {
              continue;
            }
            dp[n + 1][a][i][j] += dp[n][i][j][k];
            dp[n + 1][a][i][j] %= M;
          }
        }
      }
    }
  }
  ll ans = 0;
  for (auto i = 0; i < 4; i++)
  {
    for (auto j = 0; j < 4; j++)
    {
      for (auto k = 0; k < 4; k++)
      {
        ans += dp[N][i][j][k];
        ans %= M;
      }
    }
  }
  cout << ans << endl;
}