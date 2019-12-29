#define DEBUG 1
/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 12/29/2019, 11:12:55 AM
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
// constexpr ll MAX_SIZE{30000010LL}; // if 10^7 is needed
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

class Domino
{
  using board = vector<string>;
  using point = tuple<int, int>;
  vector<board> seed;

  int N;
  board answer;

public:
  Domino(int N) : N{N}
  {
    init_seed();
    stringstream SS;
    for (auto i = 0; i < N; i++)
    {
      SS << '.';
    }
    answer = board(N, SS.str());
  }

  void flush()
  {
    if (N == 2)
    {
      cout << "-1" << endl;
      return;
    }
    make_ans();
    assert(static_cast<int>(answer.size()) == N);
    for (auto i = 0; i < N; i++)
    {
      assert(static_cast<int>(answer[i].size()) == N);
      cout << answer[i] << endl;
    }
  }

  void init_seed()
  {
    seed.resize(8);
    seed[3] = {
        "aa.",
        "..a",
        "..a"};
    seed[4] = {
        "aabc",
        "ddbc",
        "bcaa",
        "bcdd"};
    seed[5] = {
        "aabba",
        "bcc.a",
        "b..cb",
        "a..cb",
        "abbaa"};
    seed[6] = {
        "aabc..",
        "ddbc..",
        "..aabc",
        "..ddbc",
        "bc..aa",
        "bc..dd"};
    seed[7] = {
        "aabbcc.",
        "dd.dd.a",
        "..d..da",
        "..d..db",
        "dd.dd.b",
        "..d..dc",
        "..d..dc"};
  }

private:
  void make_ans()
  {
    if (N == 3)
    {
      answer = seed[3];
      return;
    }
    int S{N % 4 + 4};
    int x{(N - S) / 4};
    for (auto k = 0; k < x; k++)
    {
      for (auto i = k * 4; i < (k + 1) * 4; i++)
      {
        for (auto j = k * 4; j < (k + 1) * 4; j++)
        {
          answer[i][j] = seed[4][i % 4][j % 4];
        }
      }
    }
    for (auto i = x * 4; i < N; i++)
    {
      for (auto j = x * 4; j < N; j++)
      {
        answer[i][j] = seed[S][i - x * 4][j - x * 4];
      }
    }
  }
};

int main()
{
  int N;
  cin >> N;
  Domino domino{N};
  domino.flush();
}
