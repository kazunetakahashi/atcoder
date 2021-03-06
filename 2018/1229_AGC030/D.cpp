/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 12/29/2018, 10:01:22 PM
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

ll N;
ll Q;
ll A[3010];
int X[3010];
int Y[3010];
ll T[3010][3010];
ll t_half[3010];
ll t_half_rev[3010];

void flush()
{
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = i + 1; j < N; j++)
    {
      ans += T[i][j];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}

int main()
{
  init();
  cin >> N >> Q;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < Q; i++)
  {
    cin >> X[i] >> Y[i];
    X[i]--;
    Y[i]--;
  }
  fill(&T[0][0], &T[0][0] + 3010 * 3010, 0);
  ll initial = power(2, Q);
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (A[i] > A[j])
      {
        T[i][j] = initial;
      }
    }
  }
  /*
  for (auto j = 0; j < N; j++)
  {
    for (auto k = 0; k < N; k++)
    {
      cerr << "T[" << j << "][" << k << "] = " << T[j][k] << endl;
    }
  }
  */
  ll two_inv = inv[2];
  for (auto i = 0; i < Q; i++)
  {
    int x = X[i];
    int y = Y[i];
    for (auto j = 0; j < N; j++)
    {
      if (j != x && j != y)
      {
        t_half[j] = (T[j][x] + T[j][y]) * two_inv;
        t_half[j] %= MOD;
        // cerr << "t_half[" << j << "] = " << t_half[j] << endl;
        t_half_rev[j] = (T[x][j] + T[y][j]) * two_inv;
        t_half_rev[j] %= MOD;
      }
    }
    for (auto j = 0; j < N; j++)
    {
      if (j != x && j != y)
      {
        T[j][x] = t_half[j];
        T[j][y] = t_half[j];
        T[x][j] = t_half_rev[j];
        T[y][j] = t_half_rev[j];
      }
    }
    ll t = (T[x][y] + T[y][x]) * two_inv;
    t %= MOD;
    T[x][y] = t;
    T[y][x] = t;
    /*
    cerr << "i = " << i << endl;
    for (auto j = 0; j < N; j++)
    {
      for (auto k = 0; k < N; k++)
      {
        cerr << "T[" << j << "][" << k << "] = " << T[j][k] << endl;
      }
    }
    */
  }
  flush();
}