#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-3-24 21:32:36
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
ll DP[4][4][110];
char chars[4] = {'A', 'C', 'G', 'T'};

int main()
{
  cin >> N;
  fill(&DP[0][0][0], &DP[0][0][0] + 4 * 4 * 110, 0);
  DP[3][3][0] = 1;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < 4; j++)
    {
      for (auto k = 0; k < 4; k++)
      {
        if (j == 0 && k == 2)
        {
          for (auto l = 0; l < 4; l++)
          {
            if (l != 1)
            {
              DP[k][l][i + 1] += DP[j][k][i];
              DP[k][l][i + 1] %= M;
            }
          }
        }
        else if (j == 2 && k == 0)
        {
          for (auto l = 0; l < 4; l++)
          {
            if (l != 1)
            {
              DP[k][l][i + 1] += DP[j][k][i];
              DP[k][l][i + 1] %= M;
            }
          }
        }
        else if (j == 0 && k == 1)
        {
          for (auto l = 0; l < 4; l++)
          {
            if (l != 2)
            {
              DP[k][l][i + 1] += DP[j][k][i];
              DP[k][l][i + 1] %= M;
            }
          }
        }
        else
        {
          for (auto l = 0; l < 4; l++)
          {
            DP[k][l][i + 1] += DP[j][k][i];
            DP[k][l][i + 1] %= M;
          }
        }
      }
    }
    if (i >= 2)
    {
      for (auto l = 0; l < 4; l++)
      {
        if (l != 1)
        {
          DP[l][1][i] += M - DP[0][2][i - 2];
          DP[l][1][i] %= M;
        }
      }
    }
  }
  ll ans = 0;
  for (auto j = 0; j < 4; j++)
  {
    for (auto k = 0; k < 4; k++)
    {
      ans += DP[j][k][N];
      ans %= M;
    }
  }
  cout << ans << endl;
}