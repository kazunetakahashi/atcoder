#define DEBUG 1
/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/1/25 11:32:12
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
template <typename T>
T gcd(T x, T y) { return y ? gcd(y, x % y) : x; }
template <typename T>
T lcm(T x, T y) { return x / gcd(x, y) * y; }
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

class Sieve
{
  static constexpr ll MAX_SIZE{10000010LL};
  ll N;
  vector<ll> f;
  vector<ll> prime_nums;

public:
  Sieve(ll N = MAX_SIZE) : N{N}, f(N, 0), prime_nums{}
  {
    f[0] = f[1] = -1;
    for (auto i = 2; i < N; i++)
    {
      if (f[i])
      {
        continue;
      }
      prime_nums.push_back(i);
      f[i] = i;
      for (auto j = 2 * i; j < N; j += i)
      {
        if (!f[j])
        {
          f[j] = i;
        }
      }
    }
  }

  bool is_prime(ll x) const
  { // 2 \leq x \leq MAX_SIZE^2
    if (x < N)
    {
      return f[x];
    }
    for (auto e : prime_nums)
    {
      if (x % e == 0)
      {
        return false;
      }
    }
    return true;
  }

  vector<ll> const &primes() const
  {
    return prime_nums;
  }

  vector<ll> factor_list(ll x) const
  {
    if (x < 2)
    {
      return {};
    }
    vector<ll> res;
    auto it{prime_nums.begin()};
    if (x < N)
    {
      while (x != 1)
      {
        res.push_back(f[x]);
        x /= f[x];
      }
    }
    else
    {
      while (x != 1 && it != prime_nums.end())
      {
        if (x % *it == 0)
        {
          res.push_back(*it);
          x /= *it;
        }
        else
        {
          ++it;
        }
      }
      if (x != 1)
      {
        res.push_back(x);
      }
    }
    return res;
  }

  vector<tuple<ll, ll>> factor(ll x) const
  {
    if (x < 2)
    {
      return {};
    }
    auto factors{factor_list(x)};
    vector<tuple<ll, ll>> res{make_tuple(factors[0], 0)};
    for (auto x : factors)
    {
      if (x == get<0>(res.back()))
      {
        get<1>(res.back())++;
      }
      else
      {
        res.emplace_back(x, 1);
      }
    }
    return res;
  }
};

// ----- main() -----

using ld = long double;
using point = complex<ld>;
constexpr ld PI{3.14159265358979323846};

class Solve
{
  ld La, Lb, Lc, Na, Nb, Nc, Ne, Ma, Mb, Mc, Tc;
  int alpha;
  Sieve sieve;
  ld Ta = 0;
  ld Tb;
  point Oa{0, 900}, Ob{900, 0}, Oc{900, 900}, Oe{90, 50};
  point Aa{1, 0}, Ab{0, 1}, Ac{-1, 0};
  ld S{500}, A{3000}, D{60};

public:
  Solve(ld La, ld Lb, ld Lc, ld Na, ld Nb, ld Nc, ld Ne, ld Ma, ld Mb, ld Mc, ld Tc) : La{La}, Lb{Lb}, Lc{Lc}, Na{Na}, Nb{Nb}, Nc{Nc}, Ne{Ne}, Ma{Ma}, Mb{Mb}, Mc{Mc}, Tc{Tc} {}

  void flush()
  {
    for (auto i = 0; i < 20; ++i)
    {
      ld now{0};
      ld W{Ma};
      if (now + Ma * Na > 100)
      {
        W = 500;
      }
      flush_A(W);
      now += Na * W;
      W = Mb;
      if (now + Mb * Nb > 100)
      {
        W = 500;
      }
      flush_B(W);
      now += Nb * W;
      W = Mc;
      if (now + Mc * Nc > 100)
      {
        W = 500;
      }
      flush_C(W);
      now += Nc * W;
      flush_E(now / Ne);
    }
  }

private:
  void update_Tb()
  {
    if (alpha == 0)
    {
      Tb = 0;
    }
    else
    {
      ll p{sieve.primes()[alpha + 1]};
      ll r{p % 180};
      Tb = (r <= 90 ? r : 180 - r);
    }
  }

  point arg(ld theta) { return theta / 180 * PI * point(0, 1); }
  point Pa() { return exp(-arg(Ta)) * La + Oa; }
  point Pb() { return exp(arg(Tb)) * Lb + Ob; }
  point Pc() { return exp(arg(Tc)) * Lc + Oc; }

  void flush_simple(ld X, ld Sx, ld Ax, ld Dx, ld Y, ld Sy, ld Ay, ld Dy, ld Ta, ld Wa, ld Wb, ld Wc, ld We)
  {
    cout << fixed << setprecision(0) << X << ", " << Sx << ", " << Ax << ", " << Dx << ", " << Y << ", " << Sy << ", " << Ay << ", " << Dy << ", " << Ta << ", " << Wa << ", " << Wb << ", " << Wc << ", " << We << endl;
  }

  void flush_A(ld W)
  {
    flush_simple(Pa().real(), S, A, D, Pa().imag(), S, A, D, Ta, W, 0, 0, 0);
    alpha += W;
  }

  void flush_B(ld W)
  {
    flush_simple(Pb().real(), S, A, D, Pb().imag(), S, A, D, Ta, 0, W, 0, 0);
  }

  void flush_C(ld W)
  {
    flush_simple(Pc().real(), S, A, D, Pc().imag(), S, A, D, Ta, 0, 0, W, 0);
  }

  void flush_E(ld W)
  {
    flush_simple(Oe.real(), S, A, D, Oe.imag(), S, A, D, Ta, 0, 0, 0, W);
  }
};

int main()
{
  ld La, Lb, Lc, Na, Nb, Nc, Ne, Ma, Mb, Mc, Tc;
  cin >> La >> Lb >> Lc >> Na >> Nb >> Nc >> Ne >> Ma >> Mb >> Mc >> Tc;
  Solve solve(La, Lb, Lc, Na / 1000, Nb / 1000, Nc / 1000, Ne / 1000, Ma, Mb, Mc, Tc);
  solve.flush();
}
