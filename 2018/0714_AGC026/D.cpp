/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-14 22:46:09
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

const long long MOD = 1000000007;

long long power(long long x, long long n)
{
  if (n == 0)
  {
    return 1;
  }
  else if (n % 2 == 1)
  {
    return (x * power(x, n - 1)) % MOD;
  }
  else
  {
    long long half = power(x, n / 2);
    return (half * half) % MOD;
  }
}

int N;
ll h[1010];
ll DP[2][1010];

int main()
{
  cin >> N;
  h[0] = 0;
  for (auto i = 1; i <= N; i++)
  {
    cin >> h[i];
  }
  DP[0][0] = 0;
  DP[0][1] = 1;
  for (auto i = 0; i < N; i++)
  {
    if (h[i] < h[i + 1])
    {
      ll t = h[i + 1] - h[i];
      ll p = power(2, t);
      DP[i + 1][1] = (((2 * DP[i][1]) % MOD) * p) % MOD;
      DP[i + 1][0] = (DP[i][0] * p) % MOD;
    }
    else if (h[i + 1] >= 2)
    {
      DP[i + 1][1] = (2 * DP[i][1]) % MOD;
      DP[i + 1][0] = DP[i][0];
    }
    else if (h[i + 1] == 1)
    {
      DP[i + 1][1] = (((2 * DP[i][1]) % MOD) + DP[i][0]) % MOD;
      DP[i + 1][0] = 0;
    }
    else
    {
      DP[i + 1][1] = (DP[i][1] + DP[i][0]) % MOD;
      DP[i + 1][0] = 0;
    }
    cerr << "DP[" << i + 1 << "] = " << DP[i + 1][0] << " " << DP[i + 1][1] << endl;
  }
  cout << (DP[N][1] + DP[N][0]) % MOD << endl;
}