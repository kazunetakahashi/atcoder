#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/12/24 20:41:23
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
void Yes(int i)
{
  cout << i << endl;
  exit(0);
}
void No()
{
  cout << "No" << endl;
  exit(0);
}
// ----- main() -----

int H, W;
vector<string> S;

void stamp(int x, int y)
{

#if DEBUG == 1
  cerr << "stamp(" << x << ", " << y << ")" << endl;
#endif
  for (auto i = x; i < min(H, x + H / 2); i++)
  {
    for (auto j = y; j < min(W, y + W / 2); j++)
    {
      S[i][j] = '#';
#if DEBUG == 1
      cerr << "S[" << i << "][" << j << "]" << endl;
#endif
    }
  }
}

int main()
{
  cin >> H >> W;
  S.resize(H);
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  set<int> X, Y;
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      if (S[i][j] == '.')
      {
        X.insert(i);
        Y.insert(j);
      }
    }
  }
  if (X.empty())
  {
    Yes(0);
  }
  auto it = X.begin();
  int ubh{*it};
  it = X.end();
  it--;
  int lbh{*it};
  it = Y.begin();
  int ubw{*it};
  it = Y.end();
  it--;
  int lbw{*it};
  int height{lbh - ubh + 1};
  int width{lbw - ubw + 1};
  if (height <= H / 2 && width <= W / 2)
  {
    Yes(1);
  }
  if (height <= H / 2)
  {
    Yes(2);
  }
  if (width <= W / 2)
  {
    Yes(2);
  }
  int cnt{0};
  for (auto k = 0; k < H + W - 1; k++)
  {
    for (auto i = 0; i <= k; i++)
    {
      auto j = k - i;
      if (!(i < H && j < W))
      {
        continue;
      }
      if (0 <= i && i < H && 0 <= j && j < W && S[i][j] == '.')
      {
        ++cnt;
        stamp(i, j);
      }
      auto ni = H - 1 - i;
      auto nj = W - 1 - j;
      if (0 <= ni && ni < H && 0 <= j && j < W && S[ni][j] == '.')
      {
        ++cnt;
        stamp(ni - H / 2 + 1, j);
      }
      if (0 <= i && i < H && 0 <= nj && nj < W && S[i][nj] == '.')
      {
        ++cnt;
        stamp(i, nj - W / 2 + 1);
      }
      if (0 <= ni && ni < H && 0 <= nj && nj < W && S[ni][nj] == '.')
      {
        ++cnt;
        stamp(ni - H / 2 + 1, nj - W / 2 + 1);
      }
    }
  }
  if (cnt > 4)
  {
    assert(false);
  }
  cout << cnt << endl;
}
