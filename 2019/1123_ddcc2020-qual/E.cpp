#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 11/23/2019, 10:01:08 PM
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

bool flush(vector<int> const &A)
{
  assert(static_cast<int>(A.size()) == N);
  cout << "? ";
  for (auto i = 0; i < N; i++)
  {
    cout << A[i] + 1;
    if (i < N - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
  string S;
  cin >> S;
  assert(S == "Red" || S == "Blue");
  return S == "Red";
}

void answer(vector<bool> const &C)
{
  assert(static_cast<int>(C.size()) == 2 * N);
  cout << "! ";
  for (auto i = 0; i < 2 * N; i++)
  {
    cout << (C[i] ? "R" : "B");
  }
  cout << endl;
}

vector<int> make_vec(int x)
{
  assert(0 <= x && x <= N);
  vector<int> ans;
  for (auto i = 0; i < x; i++)
  {
    ans.push_back(i);
  }
  for (auto i = x; i < N; i++)
  {
    ans.push_back(i + N);
  }
  return ans;
}

int main()
{
  cin >> N;
  vector<bool> C(2 * N);
  bool init_color{flush(make_vec(N))};
  int ng{0}, ok{N};
  while (abs(ok - ng) > 1)
  {
    int t{(ok + ng) / 2};
    bool c{flush(make_vec(t))};
    if (c == init_color)
    {
      ok = t;
    }
    else
    {
      ng = t;
    }
  }
  C[ok - 1] = init_color;
  C[ok - 1 + N] = !init_color;
  vector<int> unit = make_vec(ok);
  auto it{unit.begin()};
  unit.erase(it + ok - 1);
  vector<int> unit2;
  for (auto x : unit)
  {
    unit2.push_back((N + x) % (2 * N));
  }
  // unit2
  for (auto i = 0; i < ok - 1; i++)
  {
    vector<int> X = unit2;
    X.push_back(i);
    C[i] = flush(X);
  }
  for (auto i = ok; i < N; i++)
  {
    vector<int> X = unit2;
    X.push_back(i + N);
    C[i + N] = flush(X);
  }
  // unit
  for (auto i = 0; i < ok - 1; i++)
  {
    vector<int> X = unit;
    X.push_back(i + N);
    C[i + N] = flush(X);
  }
  for (auto i = ok; i < N; i++)
  {
    vector<int> X = unit;
    X.push_back(i);
    C[i] = flush(X);
  }
  answer(C);
}
