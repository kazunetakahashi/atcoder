#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 6/14/2020, 3:06:06 AM
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
constexpr ll MOD{1'000'000'007LL};
// constexpr ll MOD{998'244'353LL}; // be careful
constexpr ll MAX_SIZE{3'000'010LL};
// constexpr ll MAX_SIZE{30'000'010LL}; // if 10^7 is needed
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
// ----- Infty -----
template <typename T>
constexpr T Infty() { return numeric_limits<T>::max(); }
template <typename T>
constexpr T mInfty() { return numeric_limits<T>::min(); }
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
  cout << "0" << endl;
  exit(0);
}

// ----- Solve -----

constexpr int C{18};

ll comb(ll n, ll k)
{
  ll ans{1};
  for (auto i{0LL}; i < k; ++i)
  {
    ans *= n - i;
    ans /= i + 1;
  }
  return ans;
}

class Solve
{
  int N, S, T;
  int M;
  ll K;
  vector<int> A;

public:
  Solve(int N) : N{N}, A(N)
  {
    cin >> K >> S >> T;
    for (auto i{0}; i < N; ++i)
    {
      cin >> A[i];
    }
#if DEBUG == 1
    cerr << "N = " << N << endl;
    for (auto i{0}; i < N; ++i)
    {
      cerr << "A[" << i << "] = " << A[i] << endl;
    }
#endif
    normalize();
#if DEBUG == 1
    cerr << "N = " << N << endl;
    for (auto i{0}; i < N; ++i)
    {
      cerr << "A[" << i << "] = " << A[i] << endl;
    }
    cerr << "M = " << M << endl;
#endif
  }

  void flush()
  {
    ll ans{0};
    for (auto mask{0}; mask < 1 << M; ++mask)
    {
      if (popcount(mask) & 1)
      {
        ans -= calc(mask);
      }
      else
      {
        ans += calc(mask);
      }
    }
    cout << ans << endl;
  }

private:
  ll calc(int mask)
  {
    map<int, ll> X;
    for (auto i{0}; i < N; ++i)
    {
      int tmp{A[i] & mask};
      X[tmp];
      X[tmp]++;
    }
    ll ans{1};
    for (auto [mask, cnt] : X)
    {
      for (auto i{1}; i <= min(K, cnt); ++i)
      {
        ans += comb(cnt, i);
      }
    }
    return ans;
  }

  void normalize()
  {
    vector<bool> ok(N, true);
    for (auto i{0}; i < C; ++i)
    {
      auto s{static_cast<bool>(S >> i & 1)};
      auto t{static_cast<bool>(T >> i & 1)};
      if (s && !t)
      {
        No();
      }
      if (s ^ !t)
      {
        for (auto j{0}; j < N; ++j)
        {
          if ((A[j] >> i & 1) != static_cast<int>(s))
          {
            ok[j] = false;
          }
        }
      }
    }
    vector<int> B;
#if DEBUG == 1
    cerr << "B.size() = " << B.size() << endl;
#endif
    for (auto i{0}; i < C; ++i)
    {
      if (ok[i])
      {
        B.push_back(A[i]);
      }
    }
#if DEBUG == 1
    cerr << "B.size() = " << B.size() << endl;
#endif
    swap(A, B);
    N = static_cast<int>(A.size());
    int k{0};
    B = vector<int>(N, 0);
    for (auto i{0}; i < C; ++i)
    {
      auto s{static_cast<bool>(S >> i & 1)};
      auto t{static_cast<bool>(T >> i & 1)};
      if (!(!s && t))
      {
        continue;
      }
      for (auto j{0}; j < N; ++j)
      {
        B[j] |= (A[j] >> i & 1) << k;
      }
      ++k;
    }
    swap(A, B);
    M = k;
  }
};

// ----- main() -----

int main()
{
  int N;
  cin >> N;
  Solve solve(N);
  solve.flush();
}
