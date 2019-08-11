#define DEBUG 1
/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 8/11/2019, 8:49:37 PM
 * Powered by Visual Studio Code
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using ll = long long;
class mint
{
public:
  static ll MOD;
  ll x;
  mint() : x(0) {}
  mint(ll x) : x(x % MOD) {}
  mint operator-() const { return x ? MOD - x : 0; }
  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  mint &operator-=(const mint &a) { return *this += -a; }
  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint &operator/=(const mint &a)
  {
    mint b{a};
    return *this *= b.power(MOD - 2);
  }
  mint operator+(const mint &a) const { return mint(*this) += a; }
  mint operator-(const mint &a) const { return mint(*this) -= a; }
  mint operator*(const mint &a) const { return mint(*this) *= a; }
  mint operator/(const mint &a) const { return mint(*this) /= a; }
  bool operator<(const mint &a) const { return x < a.x; }
  bool operator==(const mint &a) const { return x == a.x; }
  const mint power(ll N)
  {
    if (N == 0)
    {
      return 1;
    }
    else if (N % 2 == 1)
    {
      return *this * power(N - 1);
    }
    else
    {
      mint half = power(N / 2);
      return half * half;
    }
  }
};
ll mint::MOD = 1e9 + 7;
istream &operator>>(istream &stream, mint &a) { return stream >> a.x; }
ostream &operator<<(ostream &stream, const mint &a) { return stream << a.x; }
class combination
{
public:
  vector<mint> inv, fact, factinv;
  static int MAX_SIZE;
  combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i = 2; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[mint::MOD % i]) * (mint::MOD / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i = 1; i < MAX_SIZE; i++)
    {
      fact[i] = mint(i) * fact[i - 1];
      factinv[i] = inv[i] * factinv[i - 1];
    }
  }
  mint operator()(int n, int k)
  {
    if (n >= 0 && k >= 0 && n - k >= 0)
    {
      return fact[n] * factinv[k] * factinv[n - k];
    }
    return 0;
  }
};
int combination::MAX_SIZE = 3000010;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// constexpr double epsilon = 1e-10;
constexpr ll infty = 1000000000000000LL;
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}
void No()
{
  cout << "No" << endl;
  exit(0);
}

int N;
ll A[510][510];
ll dp[510][510];
ll sum0[510][510];
ll sum1[510][510];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (i == j)
      {
        continue;
      }
      cin >> A[i][j];
    }
  }
  for (auto j = 0; j < N; j++)
  {
    for (auto x = 0; x < N; x++)
    {
      for (auto y = j + 1; y <= x - 1; y++)
      {
        sum0[j][x] += A[y][x];
      }
#if DEBUG == 1
      cerr << "sum0[" << j << "][" << x << "] = " << sum0[j][x] << endl;
#endif
    }
  }
  for (auto x = 0; x < N; x++)
  {
    for (auto i = 0; i < x; i++)
    {
      for (auto y = 0; y <= i; y++)
      {
        sum1[i][x] += A[x][y];
      }
#if DEBUG == 1
      cerr << "sum1[" << i << "][" << x << "] = " << sum1[i][x] << endl;
#endif
    }
  }
  fill(&dp[0][0], &dp[0][0] + 510 * 510, infty);
  dp[0][0] = 0;
  for (auto j = 0; j < N; j++)
  {
    for (auto i = 0; i <= j; i++)
    {
      if (dp[i][j] == infty)
      {
        continue;
      }
      ll tmp0 = 0;
      ll tmp1 = 0;
      for (auto k = j + 1; k <= N; k++)
      {
        tmp0 += sum0[j][k];
        tmp1 += sum1[i][k];
        ll t = dp[i][j] + tmp0 + tmp1;
#if DEBUG == 1
        cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << " -> dp[" << j << "][" << k << "] = " << t << endl;
#endif
        mins(dp[j][k], t);
      }
    }
  }
  ll ans = infty;
  for (auto i = 0; i < N; i++)
  {
    mins(ans, dp[i][N]);
  }
  cout << ans << endl;
}