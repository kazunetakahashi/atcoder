#define DEBUG 1
/**
 * File    : F3.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-30 00:41:55
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
const int MAX_SIZE = 1000010;
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
  mint &operator/=(const mint &a) { return (*this *= power(MOD - 2)); }
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
mint inv[MAX_SIZE];
mint fact[MAX_SIZE];
mint factinv[MAX_SIZE];
void init()
{
  inv[1] = 1;
  for (int i = 2; i < MAX_SIZE; i++)
  {
    inv[i] = (-inv[mint::MOD % i]) * (mint::MOD / i);
  }
  fact[0] = factinv[0] = 1;
  for (int i = 1; i < MAX_SIZE; i++)
  {
    fact[i] = mint(i) * fact[i - 1];
    factinv[i] = inv[i] * factinv[i - 1];
  }
}
mint choose(int n, int k)
{
  if (n >= 0 && k >= 0 && n - k >= 0)
  {
    return fact[n] * factinv[k] * factinv[n - k];
  }
  return 0;
}
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// const double epsilon = 1e-10;
// const ll infty = 1000000000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

ll N, K;
ll X;
mint DP[110][100010];
mint DP_sum[110][100010];
mint DP2[110][100010];
mint DP2_sum[110][100010];
mint cnt[100010];

int main()
{
  // init();
  cin >> N >> K;
  int C = -1;
  X = sqrt(N) + 10;
  for (auto i = 1; i <= X; i++)
  {
    ll ub = max(N / i, X);
    ll lb = max(N / (i + 1), X);
    cnt[i] = ub - lb;
    if (ub == X && lb == X)
    {
      C = i;
      break;
    }
  }
  DP[0][1] = 1;
  for (auto j = 1; j <= X; j++)
  {
    DP_sum[0][j] = 1;
  }
  for (auto t = 1; t <= K; t++)
  {
    for (auto j = 1; j <= X; j++)
    {
      DP[t][j] = DP_sum[t - 1][j];
      if (j < C)
      {
        DP[t][j] += DP2_sum[t - 1][C - 1] - DP2_sum[t - 1][j - 1];
      }
    }
    for (auto j = 1; j < C; j++)
    {
      DP2[t][j] = cnt[j] * DP_sum[t - 1][j];
    }
    DP_sum[t][0] = 0;
    for (auto j = 1; j <= X; j++)
    {
      DP_sum[t][j] = DP_sum[t][j - 1] + DP[t][j];
    }
    DP2_sum[t][0] = 0;
    for (auto j = 1; j < C; j++)
    {
      DP2_sum[t][j] = DP2_sum[t][j - 1] + DP2[t][j];
    }
  }
  cout << DP_sum[K][X] + DP2_sum[K][C - 1] << endl;
}