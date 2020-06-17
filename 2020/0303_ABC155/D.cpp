#define DEBUG 1
/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 6/17/2020, 5:57:07 PM
 * Powered by Visual Studio Code
 */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// ----- boost -----
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/rational.hpp>
// ----- using directives and manipulations -----
using namespace std;
using boost::rational;
using boost::integer::gcd; // for C++14 or for cpp_int
using boost::integer::lcm; // for C++14 or for cpp_int
using boost::multiprecision::cpp_int;
using ll = long long;
using ld = long double;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
// ----- constexpr for Mint and Combination -----
constexpr ll MOD{1'000'000'007LL};
// constexpr ll MOD{998'244'353LL}; // be careful
constexpr ll MAX_SIZE{3'000'010LL};
// constexpr ll MAX_SIZE{30'000'010LL}; // if 10^7 is needed
// ----- ch_max and ch_min -----
template <typename T>
bool ch_max(T &left, T right)
{
  if (left < right)
  {
    left = right;
    return true;
  }
  return false;
}
template <typename T>
bool ch_min(T &left, T right)
{
  if (left > right)
  {
    left = right;
    return true;
  }
  return false;
}
// ----- Mint -----
template <ll MOD = MOD>
class Mint
{
public:
  ll x;
  Mint() : x{0LL} {}
  Mint(ll x) : x{(x % MOD + MOD) % MOD} {}
  Mint operator-() const { return x ? MOD - x : 0; }
  Mint &operator+=(Mint const &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  Mint &operator-=(Mint const &a) { return *this += -a; }
  Mint &operator++() { return *this += 1; }
  Mint operator++(int)
  {
    Mint tmp{*this};
    ++*this;
    return tmp;
  }
  Mint &operator--() { return *this -= 1; }
  Mint operator--(int)
  {
    Mint tmp{*this};
    --*this;
    return tmp;
  }
  Mint &operator*=(Mint const &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  Mint &operator/=(Mint const &a)
  {
    Mint b{a};
    return *this *= b.power(MOD - 2);
  }
  Mint operator+(Mint const &a) const { return Mint(*this) += a; }
  Mint operator-(Mint const &a) const { return Mint(*this) -= a; }
  Mint operator*(Mint const &a) const { return Mint(*this) *= a; }
  Mint operator/(Mint const &a) const { return Mint(*this) /= a; }
  bool operator<(Mint const &a) const { return x < a.x; }
  bool operator<=(Mint const &a) const { return x <= a.x; }
  bool operator>(Mint const &a) const { return x > a.x; }
  bool operator>=(Mint const &a) const { return x >= a.x; }
  bool operator==(Mint const &a) const { return x == a.x; }
  bool operator!=(Mint const &a) const { return !(*this == a); }
  Mint power(ll N) const
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
Mint<MOD> operator+(ll lhs, Mint<MOD> const &rhs) { return rhs + lhs; }
template <ll MOD>
Mint<MOD> operator-(ll lhs, Mint<MOD> const &rhs) { return -rhs + lhs; }
template <ll MOD>
Mint<MOD> operator*(ll lhs, Mint<MOD> const &rhs) { return rhs * lhs; }
template <ll MOD>
Mint<MOD> operator/(ll lhs, Mint<MOD> const &rhs) { return Mint<MOD>{lhs} / rhs; }
template <ll MOD>
istream &operator>>(istream &stream, Mint<MOD> &a) { return stream >> a.x; }
template <ll MOD>
ostream &operator<<(ostream &stream, Mint<MOD> const &a) { return stream << a.x; }
// ----- Combination -----
template <ll MOD = MOD, ll MAX_SIZE = MAX_SIZE>
class Combination
{
public:
  vector<Mint<MOD>> inv, fact, factinv;
  Combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i{2LL}; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[MOD % i]) * (MOD / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i{1LL}; i < MAX_SIZE; i++)
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
// ----- for C++17 -----
template <typename T, typename enable_if<is_integral<T>::value>::type * = nullptr>
size_t popcount(T x) { return bitset<64>(x).count(); }
size_t popcount(string const &S) { return bitset<200010>{S}.count(); }
// ----- Infty -----
template <typename T>
constexpr T Infty() { return numeric_limits<T>::max() / 3; }
template <typename T>
constexpr T mInfty() { return numeric_limits<T>::min() / 3; }
// ----- frequently used constexpr -----
// constexpr double epsilon{1e-10};
// constexpr ll infty{1'000'000'000'000'010LL}; // or
// constexpr int infty{1'000'000'010};
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

// ----- Solve -----

class Solve
{
  ll N, K;
  ll M, P;
  ll SM, SZ, SP;
  vector<ll> minus, plus;

public:
  Solve(ll N, ll K) : N{N}, K{K}
  {
    for (auto i{0}; i < N; ++i)
    {
      ll A;
      cin >> A;
      if (A < 0)
      {
        minus.push_back(A);
      }
      else if (A > 0)
      {
        plus.push_back(A);
      }
      M = minus.size();
      P = plus.size();
      SM = M * P;
      SP = M * (M - 1) / 2 + P * (P - 1) / 2;
      SZ = N * (N - 1) / 2 - SM - SP;
    }
  }

  void flush()
  {
    if (K <= SM)
    {
      sort(minus.begin(), minus.end());
      sort(plus.rbegin(), plus.rend());
      cout << answer_minus() << endl;
    }
    else if (K > SM + SZ)
    {
      sort(minus.rbegin(), minus.rend());
      sort(plus.begin(), plus.end());
      cout << answer_plus() << endl;
    }
    else
    {
      cout << 0 << endl;
    }
  }

private:
  ll answer_plus()
  {
    assert(false);
  }

  ll answer_minus()
  {
    ll ok{mInfty<ll>()};
    ll ng{0};
    while (abs(ok - ng) > 1)
    {
      ll t{(ok + ng) / 2};
      if (count_minus(t) < K)
      {
        ok = t;
      }
      else
      {
        ng = t;
      }
    }
    return ok;
  }

  ll count_minus(ll T)
  {
    ll ans{0};
    for (auto e : minus)
    {
      ans += count_minus(T, e);
    }
    return ans;
  }

  ll count_minus(ll T, ll x)
  {
    ll ok{-1};
    ll ng{P};
    while (abs(ok - ng) > 1)
    {
      ll t{(ok + ng) / 2};
      if (plus[t] * x < T)
      {
        ok = t;
      }
      else
      {
        ng = t;
      }
    }
    return ok + 1;
  }
};

// ----- main() -----

int main()
{
  ll N, K;
  cin >> N >> K;
  Solve solve(N, K);
  solve.flush();
}
