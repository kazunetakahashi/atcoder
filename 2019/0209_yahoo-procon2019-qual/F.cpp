/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2/9/2019, 10:35:35 PM
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
const ll MOD = 998244353;
const int MAX_SIZE = 1000010;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init()
{
  inv[1] = 1;
  for (int i = 2; i < MAX_SIZE; i++)
  {
    inv[i] = ((MOD - inv[MOD % i]) * (MOD / i)) % MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i = 1; i < MAX_SIZE; i++)
  {
    fact[i] = (i * fact[i - 1]) % MOD;
    factinv[i] = (inv[i] * factinv[i - 1]) % MOD;
  }
}

long long C(int n, int k)
{
  if (n >= 0 && k >= 0 && n - k >= 0)
  {
    return ((fact[n] * factinv[k]) % MOD * factinv[n - k]) % MOD;
  }
  return 0;
}

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

long long gcd(long long x, long long y)
{
  return y ? gcd(y, x % y) : x;
}

string S;
int N;
ll DP[2010][4010];
int R[2010];
int B[2010];

int main()
{
  init();
  cin >> S;
  N = S.size();
  for (auto i = 0; i < 4010; i++)
  {
    DP[0][i] = 0;
  }
  DP[0][0] = 1;
  R[0] = B[0] = 0;
  for (auto i = 1; i <= N; i++)
  {
    if (S[i - 1] == 0)
    {
      R[i] = R[i - 1] + 2;
    }
    else if (S[i - 1] == 1)
    {
      R[i] = R[i - 1] + 1;
      B[i] = B[i - 1] + 1;
    }
    else
    {
      B[i] = B[i - 1] + 2;
    }
  }
  for (auto i = 0; i < N; i++)
  {
    cerr << "R[" << i + 1 << "] = " << R[i + 1] << ", B[" << i + 1 << "] = " << B[i + 1] << endl;
    for (auto j = 0; j <= i; j++)
    {
      if (DP[i][j] == 0)
      {
        continue;
      }
      cerr << "DP[" << i << "][" << j << "] = " << DP[i][j] << endl;
      int r = j;
      int b = i - r;
      if (R[i + 1] - r > 0)
      {
        DP[i + 1][j + 1] += DP[i][j];
        DP[i + 1][j + 1] %= MOD;
      }
      if (B[i + 1] - b > 0)
      {
        DP[i + 1][j] += DP[i][j];
        DP[i + 1][j] %= MOD;
      }
    }
  }
  ll ans = 0;
  for (auto i = 0; i <= N; i++)
  {
    if (DP[N][i] == 0)
    {
      continue;
    }
    int r = i;
    int b = N = i;
    int res_r = R[N] - r;
    int res_b = B[N] - b;
    ans += (DP[N][i] * C(res_r + res_b, res_r)) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}