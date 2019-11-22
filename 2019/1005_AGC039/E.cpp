#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 11/22/2019, 4:12:54 PM
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
// ----- constexpr for Mint and Combination -----
constexpr ll MOD{1000000007LL};
// constexpr ll MOD{998244353LL}; // be careful
constexpr ll MAX_SIZE{3000010LL};
// constexpr ll MAX_SIZE{3000010LL}; // if 10^7 is needed
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
template <ll MOD = MOD>
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
  Mint &operator/=(const Mint &a)
  {
    Mint b{a};
    return *this *= b.power(MOD - 2);
  }
  Mint operator+(const Mint &a) const { return Mint(*this) += a; }
  Mint operator-(const Mint &a) const { return Mint(*this) -= a; }
  Mint operator*(const Mint &a) const { return Mint(*this) *= a; }
  Mint operator/(const Mint &a) const { return Mint(*this) /= a; }
  bool operator<(const Mint &a) const { return x < a.x; }
  bool operator==(const Mint &a) const { return x == a.x; }
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
template <ll MOD>
Mint<MOD> operator+(ll lhs, const Mint<MOD> &rhs)
{
  return rhs + lhs;
}
template <ll MOD>
Mint<MOD> operator-(ll lhs, const Mint<MOD> &rhs)
{
  return -rhs + lhs;
}
template <ll MOD>
Mint<MOD> operator*(ll lhs, const Mint<MOD> &rhs)
{
  return rhs * lhs;
}
template <ll MOD>
Mint<MOD> operator/(ll lhs, const Mint<MOD> &rhs)
{
  return Mint<MOD>{lhs} / rhs;
}
template <ll MOD>
istream &operator>>(istream &stream, Mint<MOD> &a)
{
  return stream >> a.x;
}
template <ll MOD>
ostream &operator<<(ostream &stream, const Mint<MOD> &a)
{
  return stream << a.x;
}
// ----- Combination -----
template <ll MOD = MOD, ll MAX_SIZE = MAX_SIZE>
class Combination
{
public:
  vector<Mint<MOD>> inv, fact, factinv;
  Combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i = 2LL; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[MOD % i]) * (MOD / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i = 1LL; i < MAX_SIZE; i++)
    {
      fact[i] = Mint<MOD>(i) * fact[i - 1];
      factinv[i] = inv[i] * factinv[i - 1];
    }
  }
  Mint<MOD> operator()(int n, int k)
  {
    if (n >= 0 && k >= 0 && n - k >= 0)
    {
      return fact[n] * factinv[k] * factinv[n - k];
    }
    return 0;
  }
  Mint<MOD> catalan(int x, int y)
  {
    return (*this)(x + y, y) - (*this)(x + y, y - 1);
  }
};
// ----- for C++14 -----
using mint = Mint<MOD>;
using combination = Combination<MOD, MAX_SIZE>;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// ----- frequently used constexpr -----
// constexpr double epsilon{1e-10};
// constexpr ll infty{1000000000000000LL};
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
// ----- Yes() and No() -----
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
// ----- main() -----

int N;
vector<string> S;
ll dp[40][40][40][40];
ll dp2[40][40][40][40];

bool connectable(int i, int j)
{
  return S[i][j] == '1';
}

ll calc(int A, int B, int C, int D);
ll calc_unit(int A, int B, int C, int D);
void flush();

void flush()
{
  ll res{0LL};
  if (N >= 2)
  {
    for (auto i = 2; i <= 2 * N - 2; i++)
    {
      if (connectable(0, i))
      {
        res += calc(1, i - 1, i + 1, 2 * N - 1);
      }
    }
  }
  else if (connectable(0, 1))
  {
    res = 1;
  }
  else
  {
    res = 0;
  }
  cout << res << endl;
}

ll calc(int A, int B, int C, int D)
{
  if (dp2[A][B][C][D] >= 0)
  {
    return dp2[A][B][C][D];
  }
  if (A == B || C == D)
  {
    return dp2[A][B][C][D] = calc_unit(A, B, C, D);
  }
  ll res{0LL};
  for (auto i = A + 1; i <= B; i++)
  {
    for (auto j = C; j <= D - 1; j++)
    {
      res += calc(A, i - 1, j + 1, D) * calc_unit(i, B, C, j);
    }
  }
  res += calc_unit(A, B, C, D);
  return dp2[A][B][C][D] = res;
}

ll calc_unit(int A, int B, int C, int D)
{
  if (dp[A][B][C][D] >= 0)
  {
    return dp[A][B][C][D];
  }
  if (A == B && C == D)
  {
    return dp[A][B][C][D] = (connectable(A, C) ? 1 : 0);
  }
  ll res{0LL};
  if (A == B)
  {
    for (auto j = C + 1; j <= D - 1; j++)
    {
      if (connectable(A, j))
      {
        res += calc(C, j - 1, j + 1, D);
      }
    }
  }
  else if (C == D)
  {
    for (auto i = A + 1; i <= B - 1; i++)
    {
      if (connectable(i, C))
      {
        res += calc(A, i - 1, i + 1, B);
      }
    }
  }
  else
  {
    for (auto i = A + 1; i <= B - 1; i++)
    {
      for (auto j = C + 1; j <= D - 1; j++)
      {
        if (connectable(i, j))
        {
          res += calc(A, i - 1, i + 1, B) * calc(C, j - 1, j + 1, D);
        }
      }
    }
  }
  return dp[A][B][C][D] = res;
}

int main()
{
  cin >> N;
  S.resize(2 * N);
  for (auto i = 0; i < 2 * N; i++)
  {
    cin >> S[i];
  }
  fill(&dp[0][0][0][0], &dp[0][0][0][0] + 40 * 40 * 40 * 40, -1);
  fill(&dp2[0][0][0][0], &dp2[0][0][0][0] + 40 * 40 * 40 * 40, -1);
  flush();
}
