#define DEBUG 1
/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/8/19 0:29:57
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
// constexpr ll infty = 1000000000000000LL;
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

ll L, R;
mint dp[61][2][2][2];

int main()
{
  cin >> L >> R;
  dp[60][0][0][0] = 1;
  for (auto i = 60 - 1; i >= 0; i--)
  {
    int lb = L >> i & 1;
    int rb = R >> i & 1;
    for (auto j = 0; j < 2; j++) // j = 0: x \geq L が未確定。 j = 1: x > L が確定。
    {
      for (auto k = 0; k < 2; k++) // k = 0 : k \leq R が未確定。 k = 1: y < R が確定。
      {
        for (auto s = 0; s < 2; s++) // s = 0: 始まっていない。 s = 1: 始まっている。
        {
          mint pre{dp[i + 1][j][k][s]}; // 前の状態。
          for (auto x = 0; x < 2; x++)
          {
            for (auto y = 0; y < 2; y++)
            {
              if (x && !y) // x = 1, y = 0 はアウト。
              {
                continue;
              }
              int nj{j}, nk{k}, ns{s}; // 次の状態を計算して足しこむ。
              if (!s && x != y)        // 始まっていないのに (1, 0) or (0, 1) はアウト。
              {
                continue;
              }
              if (x && y) // (1, 1) の場合は、すでに始まっているか、ここから始まる。
              {
                ns = 1;
              }
              if (!j && !x && lb) // x \geq L が未確定なのに x = 0, lb = 1 はアウト。
              {
                continue;
              }
              if (x && !lb) // x = 1, lb = 0 の場合は x > L が確定する。
              {
                nj = 1;
              }
              if (!k && y && !rb) // y \leq R が未確定なのに y = 1, rb = 0 はアウト。
              {
                continue;
              }
              if (!y && rb) // y = 0, lb = 1 の場合は y < R が確定する。
              {
                nk = 1;
              }
              dp[i][nj][nk][ns] += pre;
            }
          }
        }
      }
    }
  }
  mint ans{0};
  for (auto j = 0; j < 2; j++)
  {
    for (auto k = 0; k < 2; k++)
    {
      for (auto s = 0; s < 2; s++)
      {
        ans += dp[0][j][k][s];
      }
    }
  }
  cout << ans << endl;
}