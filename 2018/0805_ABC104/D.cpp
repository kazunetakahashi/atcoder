/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-5 21:32:38
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
const ll M = 1000000007;
string S;
int N;

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
  if (n < 0)
  {
    return 0;
  }
  else if (n == 0)
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

ll cnt_A[100010];
ll cnt_q[100010];
ll cnt_C[100010];
ll sum_A = 0;
ll sum_q = 0;
ll sum_C = 0;

int main()
{
  init();
  cin >> S;
  N = S.size();
  fill(cnt_A, cnt_A + 100010, 0);
  fill(cnt_q, cnt_q + 100010, 0);
  fill(cnt_C, cnt_C + 100010, 0);
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == 'A')
    {
      cnt_A[i] = 1;
    }
    else if (S[i] == '?')
    {
      cnt_q[i] = 1;
    }
    else if (S[i] == 'C')
    {
      cnt_C[i] = 1;
    }
  }
  for (auto i = 1; i < N; i++)
  {
    cnt_A[i] += cnt_A[i - 1];
    cnt_q[i] += cnt_q[i - 1];
    cnt_C[i] += cnt_C[i - 1];
  }
  sum_A = cnt_A[N - 1];
  sum_q = cnt_q[N - 1];
  sum_C = cnt_C[N - 1];
  ll ans = 0;
  for (auto i = 1; i < N - 1; i++)
  {
    if (S[i] == 'B')
    {
      ans += (cnt_A[i - 1] * (sum_C - cnt_C[i]) * power(3, sum_q)) % M;
      ans %= M;
      ans += (cnt_A[i - 1] * (sum_q - cnt_q[i]) * power(3, sum_q - 1)) % M;
      ans %= M;
      ans += (cnt_q[i - 1] * (sum_C - cnt_C[i]) * power(3, sum_q - 1)) % M;
      ans %= M;
      ans += (cnt_q[i - 1] * (sum_q - cnt_q[i]) * power(3, sum_q - 2)) % M;
      ans %= M;
    }
    else if (S[i] == '?')
    {
      ans += (cnt_A[i - 1] * (sum_C - cnt_C[i]) * power(3, sum_q - 1)) % M;
      ans %= M;
      ans += (cnt_A[i - 1] * (sum_q - cnt_q[i]) * power(3, sum_q - 2)) % M;
      ans %= M;
      ans += (cnt_q[i - 1] * (sum_C - cnt_C[i]) * power(3, sum_q - 2)) % M;
      ans %= M;
      ans += (cnt_q[i - 1] * (sum_q - cnt_q[i]) * power(3, sum_q - 3)) % M;
      ans %= M;
    }
  }
  cout << ans << endl;
}
