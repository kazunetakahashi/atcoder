#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 6/3/2020, 10:54:31 PM
 * Powered by Visual Studio Code
 */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
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
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>
// ----- using directives and manipulations -----
using namespace std;
using boost::rational;
using boost::multiprecision::cpp_int;
using ll = long long;
using ld = long double;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
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
Mint<MOD> operator+(ll lhs, Mint<MOD> const &rhs)
{
  return rhs + lhs;
}
template <ll MOD>
Mint<MOD> operator-(ll lhs, Mint<MOD> const &rhs)
{
  return -rhs + lhs;
}
template <ll MOD>
Mint<MOD> operator*(ll lhs, Mint<MOD> const &rhs)
{
  return rhs * lhs;
}
template <ll MOD>
Mint<MOD> operator/(ll lhs, Mint<MOD> const &rhs)
{
  return Mint<MOD>{lhs} / rhs;
}
template <ll MOD>
istream &operator>>(istream &stream, Mint<MOD> &a)
{
  return stream >> a.x;
}
template <ll MOD>
ostream &operator<<(ostream &stream, Mint<MOD> const &a)
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
template <typename T>
T gcd(T x, T y) { return y ? gcd(y, x % y) : x; }
template <typename T>
T lcm(T x, T y) { return x / gcd(x, y) * y; }
// ----- for C++17 -----
template <typename T>
int popcount(T x) // C++20
{
  int ans{0};
  while (x != 0)
  {
    ans += x & 1;
    x >>= 1;
  }
  return ans;
}
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
// ----- main() -----

// ----- Permutation -----

struct Permutation
{
  vector<int> V;

  Permutation() {}
  Permutation(vector<int> const &V) : V{V} {}

  static Permutation unit(size_t N)
  {
    vector<int> X(N);
    for (auto i = 0; i < static_cast<int>(N); ++i)
    {
      X[i] = i;
    }
    return Permutation{X};
  }

  size_t size() const { return V.size(); }
  int operator[](size_t i) const { return V[i]; }

  Permutation inverse() const
  {
    vector<int> Q(size());
    for (auto i = 0; i < static_cast<int>(size()); ++i)
    {
      Q[(*this)[i]] = i;
    }
    return Permutation{Q};
  }

  Permutation operator*(Permutation const &Q) const
  {
    assert(size() == Q.size());
    vector<int> R(size());
    for (auto i = 0; i < static_cast<int>(size()); ++i)
    {
      R[i] = (*this)[Q[i]];
    }
    return Permutation{R};
  }

  Permutation &operator*=(Permutation const &Q)
  {
    return *this = *this * Q;
  }

  Permutation power(int n)
  {
    if (n == 0)
    {
      return unit(size());
    }
    else if (n % 2 == 0)
    {
      auto W{power(n / 2)};
      return W * W;
    }
    else
    {
      return *this * power(n - 1);
    }
  }
};

int main()
{
  int N;
  cin >> N;
  vector<int> V(N);
  for (auto i = 0; i < N; ++i)
  {
    cin >> V[i];
    V[i]--;
  }
  Permutation P{V};
  auto to_ind{P.inverse()};
  multiset<ll> S;
  S.insert(-1);
  S.insert(-1);
  S.insert(N);
  S.insert(N);
  ll ans{0};
  for (auto x = N - 1; x >= 0; --x)
  {
    ll ind{to_ind[x]};
    S.insert(ind);
    auto it{S.find(ind)};
    --it;
    auto l0{*it};
    --it;
    auto l1{*it};
    it = S.find(ind);
    ++it;
    auto r0{*it};
    ++it;
    auto r1{*it};
    ans += (x + 1) * ((l0 - l1) * (r0 - ind) + (r1 - r0) * (ind - l0));
  }
  cout << ans << endl;
}
