/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-16 21:22:53
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
#include <random> // random_device rd; mt19937 mt(rd());
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

const int MAX_SIZE = 1000010;
long long MOD = 1000000007;

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

ll N;
ll DP[3010][3010];

ll calc(ll n, ll k)
{
  if (DP[n][k] != -1)
  {
    return DP[n][k];
  }
  if (k == 0)
  {
    return DP[n][k] = 1;
  }
  else if (k == n)
  {
    return DP[n][k] = calc(n - 1, k - 1);
  }
  else
  {
    ll ans = calc(n - 1, k - 1);
    ans += ((k + 1) * calc(n - 1, k)) % MOD;
    ans %= MOD;
    return DP[n][k] = ans;
  }
}

ll f(ll k)
{
  ll ans = power(2, power(2, N - k));
  ll sum = 0;
  for (auto x = 0; x <= k; x++)
  {
    sum += (calc(k, x) * power(2, x * (N - k))) % MOD;
    sum %= MOD;
  }
  return (ans * sum) % MOD;
}

int main()
{
  init();
  cin >> N >> MOD;
  fill(&DP[0][0], &DP[0][0] + 3010 * 3010, -1);
  ll X = 0;
  for (auto k = 0; k <= N; k++)
  {
    ll t = (C(N, k) * f(k)) % MOD;
    if (N < 50)
    {
      cerr << "k = " << k << ", t = " << t << endl;
      cerr << "f(" << k << ") = " << f(k) << endl;
      cerr << "C(" << N << ", " << k << ") = " << C(N, k) << endl;
    }
    if (k % 2 == 0)
    {
      X += t;
    }
    else
    {
      X += MOD - t;
    }
    X %= MOD;
  }
  cout << X << endl;
}