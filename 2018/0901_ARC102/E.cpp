/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-1 21:54:36
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
const ll M = 998244353;

const int MAX_SIZE = 1000010;
const long long MOD = 998244353;

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

long long gcm(long long a, long long b)
{
  if (a < b)
  {
    return gcm(b, a);
  }
  if (b == 0)
    return a;
  return gcm(b, a % b);
}

ll K, N;
ll ans[10010];

void flush()
{
  for (auto i = 2; i <= 2 * K; i++)
  {
    ll c = (C(N + K - 1, K - 1) + M - (ans[i] % M)) % M;
    cout << c << endl;
  }
}

void calc(ll X)
{
  ll c = ((X / 2) * C(N + K - 3, K - 3)) % M;
  if (X % 2 == 0)
  {
    ll Y = X / 2;
    c += C(N + K - 2, K - 2);
    c %= M;
    c += C(N + K - 3, K - 2);
    c %= M;
  }
  ans[X] = c;
}

int main()
{
  init();
  cin >> K >> N;
  flush();
}