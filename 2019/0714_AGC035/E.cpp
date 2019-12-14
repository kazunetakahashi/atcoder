#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 12/14/2019, 10:43:31 PM
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
// ----- boost -----
#include <boost/rational.hpp>
// ----- using directives and manipulations -----
using boost::rational;
using namespace std;
using ll = long long;
ll MOD{0};
// ----- ch_max and ch_min -----
template <typename T>
void ch_max(T &left, T right)
{
  if (left < right)
  {
    left = right;
  }
}
template <typename T>
void ch_min(T &left, T right)
{
  if (left > right)
  {
    left = right;
  }
}
// ----- Mint -----
class Mint
{
public:
  ll x;
  Mint() : x{0LL} {}
  Mint(ll x) : x{x % MOD} {}
  Mint operator-() const { return x ? MOD - x : 0; }
  Mint &operator+=(const Mint &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  Mint &operator-=(const Mint &a) { return *this += -a; }
  Mint &operator*=(const Mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  Mint operator+(const Mint &a) const { return Mint(*this) += a; }
  Mint operator-(const Mint &a) const { return Mint(*this) -= a; }
  Mint operator*(const Mint &a) const { return Mint(*this) *= a; }
  bool operator<(const Mint &a) const { return x < a.x; }
  bool operator<=(const Mint &a) const { return x <= a.x; }
  bool operator>(const Mint &a) const { return x > a.x; }
  bool operator>=(const Mint &a) const { return x >= a.x; }
  bool operator==(const Mint &a) const { return x == a.x; }
  bool operator!=(const Mint &a) const { return !(*this == a); }
  const Mint power(ll N)
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
      Mint half = power(N / 2);
      return half * half;
    }
  }
};
istream &operator>>(istream &stream, Mint &a) { return stream >> a.x; }
ostream &operator<<(ostream &stream, const Mint &a) { return stream << a.x; }

// ----- main() -----

// I wrote this code referring to yataka1999-san's solution
// https://atcoder.jp/contests/agc035/submissions/6380939

Mint solve_even(ll N, ll K);
Mint solve_odd(ll N, ll K);

Mint solve_even(ll N, ll K)
{
  Mint ans{1};
  for (auto t = 0LL; t < 2; t++)
  {
    auto L{(N - t + 1) / 2};
    vector<Mint> to(L + 1), from(L + 1);
    to[0] = 1;
    for (auto i = 0LL; i < L; i++)
    {
      swap(to, from);
      to = vector<Mint>(L + 1);
      for (auto j = 0LL; j <= i; j++)
      {
        to[j + 1] += from[j];
        to[0] += from[j];
      }
      for (auto j = K / 2 + 1; j <= i + 1; j++)
      {
        to[j] = 0;
      }
    }
    Mint sum{0};
    for (auto j = 0LL; j <= L; j++)
    {
      sum += to[j];
    }
    ans *= sum;
  }
  return ans;
}

Mint solve_odd(ll N, ll K)
{
  vector<vector<vector<Mint>>> from(N + 1, vector<vector<Mint>>(N + 1, vector<Mint>(N + 1)));
  vector<vector<vector<Mint>>> to(N + 1, vector<vector<Mint>>(N + 1, vector<Mint>(N + 1)));
  to[0][0][N] = 1;
  for (auto i = 0LL; i < N; i++)
  {
    swap(to, from);
    to = vector<vector<vector<Mint>>>(N + 1, vector<vector<Mint>>(N + 1, vector<Mint>(N + 1)));
    auto even{i / 2 + 1};
    auto odd{(i + 1) / 2};
    for (auto j = 0LL; j <= even; j++)
    {
      for (auto k = 0LL; k <= odd; k++)
      {
        for (auto t = i; t <= N; t++)
        {
          if (from[j][k][t] == 0)
          {
            continue;
          }
          auto dst{(t % 2 == i % 2) ? N : t};
          to[0][j][dst] += from[j][k][t];
          if (t != i)
          {
            dst = j >= K / 2 + 1 ? min(t, i - 2 * k + K) : t;
            to[k + 1][j][dst] += from[j][k][t];
          }
        }
      }
    }
  }
  Mint ans{0};
  for (auto j = 0LL; j <= N; j++)
  {
    for (auto k = 0LL; k <= N; k++)
    {
      ans += to[j][k][N];
    }
  }
  return ans;
}

int main()
{
  ll N, K;
  cin >> N >> K >> MOD;
  if (K % 2 == 0)
  {
    cout << solve_even(N, K) << endl;
  }
  else
  {
    cout << solve_odd(N, K) << endl;
  }
}
