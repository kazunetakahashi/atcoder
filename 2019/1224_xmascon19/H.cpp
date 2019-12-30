#define DEBUG 1
/**
 * File    : H.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/12/30 18:11:35
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

// ----- PrimeNums -----

class PrimeNums
{
  static constexpr ll MAX_SIZE{1000010LL};
  ll N;
  vector<bool> isprime;
  vector<int> prime_nums;

public:
  PrimeNums(ll N = MAX_SIZE) : N{N}, isprime(N, true), prime_nums{}
  {
    isprime[0] = isprime[1] = false;
    for (auto i = 2; i < N; i++)
    {
      if (isprime[i])
      {
        prime_nums.push_back(i);
        for (auto j = 2 * i; j < N; j += i)
        {
          isprime[j] = false;
        }
      }
    }
  }

  bool is_prime(long long x)
  { // 2 \leq x \leq MAX_SIZE^2
    if (x < N)
    {
      return isprime[x];
    }
    for (auto e : prime_nums)
    {
      if (x % e == 0)
        return false;
    }
    return true;
  }

  vector<int> const &primes() const
  {
    return prime_nums;
  }
};

// ----- main() -----
class Solve
{
  int H, W;
  vector<string> S;
  PrimeNums pn;

public:
  Solve(int H, int W, vector<string> const &S) : H{H}, W{W}, S(S), pn{} {}

  int calc()
  {
    int ans{0};
    for (auto i = 0; i < H; i++)
    {
      ans += calc(S[i]);
    }
    return ans;
  };

private:
  int calc(string const &T)
  {
    if (is_zero(T))
    {
      return 0;
    }
    auto V{make_vec(T)};
#if DEBUG == 1
    cerr << "V = {";
    for (auto x : V)
    {
      cerr << x << ", ";
    }
    cerr << "}" << endl;
#endif
    if (is_one(V))
    {
      return 1;
    }
    if (is_two(V))
    {
      return 2;
    }
    return 3;
  }

  bool is_zero(string const &T)
  {
    for (auto x : T)
    {
      if (x == '.')
      {
        return false;
      }
    }
    return true;
  }

  vector<int> make_vec(string const &T)
  {
    int first{-1};
    vector<int> V;
    for (auto i = 0; i < W; i++)
    {
      if (T[i] == '.')
      {
        if (first == -1)
        {
          first = i;
        }
        V.push_back(i - first);
      }
    }
    return V;
  }

  bool is_one(vector<int> const &V)
  {
    if (V.size() < size_t{2})
    {
      return true;
    }
    assert(V[0] == 0);
    int g{V[1]};
    for (auto it = V.begin() + 1; it != V.end(); it++)
    {
      g = gcd(g, *it);
    }
#if DEBUG == 1
    cerr << "g = " << g << endl;
#endif
    for (auto i = 0; i < 20; i++)
    {
      if (g == 1 << i)
      {
        return false;
      }
    }
    return true;
  }

  bool is_two(vector<int> const &V)
  {
    for (auto it = pn.primes().begin() + 1; it != pn.primes().end(); it++)
    {
      int p{static_cast<int>(*it)};
      int X{static_cast<int>(V.size())};
      if (W / p + 1 < X / 2)
      {
        return false;
      }
      for (auto k = 0; k < 2; k++)
      {
        int m{V[k]};
        int first{-1};
        vector<int> W;
        for (auto x : V)
        {
          if ((x - m) % p == 0)
          {
            continue;
          }
          if (first == -1)
          {
            first = x;
          }
          W.push_back(x - first);
        }
#if DEBUG == 1
        cerr << "p = " << p << ", m = " << m << endl;
        cerr << "W = {";
        for (auto x : W)
        {
          cerr << x << ", ";
        }
        cerr << "}" << endl;
#endif
        if (is_one(W))
        {
          return true;
        }
      }
    }
    assert(false);
    return false;
  }
};

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  Solve solve(H, W, S);
  cout << solve.calc() << endl;
}
