#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-3-30 21:18:07
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
// const ll M = 1000000007;

const int MAX_SIZE = 1000010;
const long long MOD = 1000000007;

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

int N;
ll X;
ll S[210];
ll DP[100010];

int main()
{
  init();
  cin >> N >> X;
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  sort(S, S + N);
  fill(DP, DP + 100010, 0);
  int ind = N;
  DP[N] = 1;
  for (auto i = N; i >= 0; i--)
  {
    while (S[ind - 1] > i)
    {
      ind--;
    }
    if (ind == 0)
    {
      break;
    }
    for (auto j = 0; j < ind; j++)
    {
      DP[i % S[j]] += (DP[i] * inv[ind]) % MOD;
      DP[i % S[j]] %= MOD;
    }
    DP[i] = 0;
  }
  ll ans = 0;
  for (auto i = 0LL; i <= N; i++)
  {
    ans += (i * DP[i]) % MOD;
    ans %= MOD;
  }
#if DEBUG == 1
  for (auto i = 0; i <= min(N, 10); i++)
  {
    cerr << "P[" << i << "] = " << (DP[i] * fact[N]) % MOD << endl;
  }
#endif
  ans *= fact[N];
  ans %= MOD;
  cout << ans << endl;
}