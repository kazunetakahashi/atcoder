/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-28 09:59:45
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
const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init() {
  inv[1] = 1;
  for (int i=2; i<MAX_SIZE; i++) {
    inv[i] = ((MOD - inv[MOD%i]) * (MOD/i))%MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i=1; i<MAX_SIZE; i++) {
    fact[i] = (i * fact[i-1])%MOD;
    factinv[i] = (inv[i] * factinv[i-1])%MOD;
  }
}

long long C(int n, int k) {
  if (n >=0 && k >= 0 && n-k >= 0) {
    return ((fact[n] * factinv[k])%MOD * factinv[n-k])%MOD;
  }
  return 0;
}

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

long long gcm(long long a, long long b) {
  if (a < b) {
    return gcm(b, a);
  }
  if (b == 0) return a;
  return gcm(b, a%b);
}

int N, M;
ll A[100];
ll DP[(1 << 16)];
ll L[100];

int main()
{
  init();
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> A[i];
    A[i]--;
  }
  fill(DP, DP + (1 << 16), 0);
  DP[0] = 1;
  for (auto k = M-1; k >= 0; k--)
  {
    for (auto i = (1 << N) - 1; i >= 0; i--)
    {
      if (DP[i] == 0)
        continue;
      for (auto j = 0; j < N; j++)
      {
        if (((i >> j) & 1) == 0)
        {
          DP[i + (1 << j)] += (C(power(2, N) - 1 - A[k] - i, power(2, j) - 1) * DP[i]) % MOD;
          DP[i + (1 << j)] %= MOD;
        }
      }
    }
  }
  for (auto i = 0; i < (1 << N); i++)
  {
    for (auto j = 0; j < N; j++)
    {
      ll R = (1 << 16) - 1 - i;
      if (((i >> j) & 1) == 0)
      {
        DP[i] *= C(R, power(2, j));
        DP[i] %= MOD;
        R -= power(2, j);
      }
    }
  }
  ll X = 0;
  for (auto i = 0; i < (1 << N); i++)
  {
    int b = 0;
    for (auto j = 0; j < N; j++)
    {
      b += (i >> j) & 1;
    }
    if (b % 2 == 0)
    {
      X += DP[i];
    }
    else
    {
      X += MOD - DP[i];
    }
    X %= MOD;
  }
  for (auto i = 0; i < N; i++)
  {
    L[i] = 1;
    for (auto j = 0; j < i; j++)
    {
      L[i] *= (C(power(2, i) - power(2, j), power(2, j)) * L[j]) % MOD;
      L[i] %= MOD;
    }
  }
  for (auto i = 0; i < N; i++)
  {
    X *= L[i];
    X %= MOD;
  }
  X *= power(2, power(2, N) - 1);
  X %= MOD;
  cout << X << endl;
}