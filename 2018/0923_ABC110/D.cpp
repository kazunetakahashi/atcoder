/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-23 21:11:13
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

const int MAX_SIZE = 1000010; // 10000010でもよさそう？
bool isprime[MAX_SIZE];
vector<int> prime_num;

void init()
{
  fill(isprime, isprime + MAX_SIZE, true);
  isprime[0] = isprime[1] = false;
  for (auto i = 2; i < MAX_SIZE; i++)
  {
    if (isprime[i])
    {
      prime_num.push_back(i);
      for (auto j = 2; i * j < MAX_SIZE; j++)
      {
        isprime[i * j] = false;
      }
    }
  }
}

bool prime(long long x)
{ // 2 \leq x \leq MAX_SIZE^2
  if (x < MAX_SIZE)
  {
    return isprime[x];
  }
  for (auto e : prime_num)
  {
    if (x % e == 0)
      return false;
  }
  return true;
}

const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init2()
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

map<ll, ll> X;

int main()
{
  init();
  init2();
  ll N, M;
  cin >> N >> M;
  if (M == 1)
  {
    cout << 1 << endl;
  }
  else if (prime(M))
  {
    cout << N << endl;
  }
  else
  {
    for (auto x : prime_num)
    {
      while (M % x == 0)
      {
        M /= x;
        if (X.find(x) == X.end())
        {
          X[x] = 1;
        }
        else
        {
          X[x]++;
        }
      }
    }
    ll ans = 1;
    for (auto x : X)
    {
      // cerr << x.first << ": " << x.second << endl;
      ll k = x.second;
      ans *= C(k + N - 1, k);
      ans %= MOD;
    }
    cout << ans << endl;
  }
}