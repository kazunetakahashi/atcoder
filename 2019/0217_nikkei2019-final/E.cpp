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
ll L;
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

ll power2(int x)
{
  if (x < 0)
  {
    return 1;
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
  L = N - K;
  for (auto i = 0; i < L; i++)
  {
    DP[0][i] = power(i);
  }
  DP2[0][0] = DP[0][0];
  for (auto i = 1; i < L; i++)
  {
    DP2[0][i] = DP2[0][i - 1] + DP[0][i];
    DP2[0][i] %= MOD;
  }
}

void flush()
{
#if DEBUG == 1
  if (L <= 10)
  {
    for (auto i = 0; i < L; i++)
    {
      for (auto j = 0; j < L; j++)
      {
        cerr << "DP[" << i << "][" << j << "] = " << DP[i][j] << endl;
      }
    }
  }
#endif
  cout << DP[L - 1][L - 1] << endl;
}

int main()
{
  cin >> N >> K;
  init();
  for (auto i = 1; i < L; i++)
  {
    for (auto j = 0; j < L; j++)
    {
      DP[i][j] = 0;
      if (j < i)
      {
        continue;
      }
      DP[i][j] += (DP2[i - 1][j - 1] * power(j - i)) % MOD;
      DP[i][j] += (DP[i - 1][j] * power2(j - i + 1)) % MOD;
      DP[i][j] %= MOD;
    }
    for (auto j = 0; j < i; j++)
    {
      DP2[i][j] = 0;
    }
    DP2[i][i] = DP[i][i];
    for (auto j = i + 1; j < L; j++)
    {
      DP2[i][j] = DP2[i][j - 1] + DP[i][j];
      DP2[i][j] %= MOD;
    }
  }
  flush();
}