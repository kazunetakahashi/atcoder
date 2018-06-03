/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-6-3 21:04:40
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

const int MAX_SIZE = 1000010;
const long long MOD = 998244353;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

typedef long long ll;

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

ll N, A, B, K;

ll calc(ll k, ll l)
{
  return (C(N, k) * C(N, l)) % MOD;
}

int main()
{
  cin >> N >> A >> B >> K;
  ll g = gcm(A, B);
  if (K % g != 0)
  {
    cout << 0 << endl;
    return 0;
  }
  A /= g;
  B /= g;
  K /= g;
  ll ans = 0;
  for (ll k = 0; k <= N; k++)
  {
    ll BL = K - A * k;
    if (BL % B == 0)
    {
      ll l = BL / B;
      if (0 <= l && l <= N)
      {
        ans += calc(k, l);
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}