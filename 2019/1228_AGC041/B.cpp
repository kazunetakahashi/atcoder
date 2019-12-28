#define DEBUG 1
/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 12/28/2019, 10:05:50 PM
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

class Solve
{
  ll N, M, V, P;
  vector<ll> A;
  vector<ll> sum;

public:
  Solve(ll N, ll M, ll V, ll P, vector<ll> A) : N{N}, M{M}, V{V}, P{P}, A(A), sum(N + 1, 0LL)
  {
    sum[P - 1] = A[P - 1];
    for (auto i = P; i < N; i++)
    {
      sum[i] = A[i] + sum[i - 1];
    }
  }

  ll answer()
  {
    if (V <= P)
    {
      return answer0();
    }
    else
    {
      return answer1();
    }
  }

private:
  ll answer0()
  {
    // correct
    ll ans{0};
    for (auto i = P; i < N; i++)
    {
      if (A[P - 1] <= A[i] + M)
      {
        ans++;
      }
    }
    return ans + P;
  }

  ll answer1()
  {
    ll ok{P - 1};
    ll ng{N};
#if DEBUG == 1
    for (auto i = P - 1; i < N; i++)
    {
      cerr << "text(" << i << ") = " << test(i) << endl;
    }
#endif
    while (abs(ok - ng) > 1)
    {
      ll t{(ok + ng) / 2};
      if (test(t))
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

  bool test(ll i)
  {
    ll K{V - (P - 1) - (N - i)};
#if DEBUG == 1
    cerr << "i = " << i << ", K = " << K << endl;
#endif
    if (K <= 0)
    {
      return A[i] + M >= A[P - 1];
    }
#if DEBUG == 1
    cerr << "A[" << i << "] = " << A[i] << endl;
    cerr << "M = " << M << endl;
    cerr << "i - (P - 1) = " << i - (P - 1) << endl;
    cerr << "sum[" << i - 1 << "] = " << sum[i - 1] << endl;
    cerr << "K * M = " << K * M << endl;
    cerr << (A[i] + M) * (i - (P - 1)) << " >=? " << sum[i - 1] + K * M << endl;
#endif
    return (A[i] + M) * (i - (P - 1)) >= sum[i - 1] + K * M;
  }
};

int main()
{
  ll N, M, V, P;
  cin >> N >> M >> V >> P;
  vector<ll> A(N);
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sort(A.rbegin(), A.rend());
  Solve solve(N, M, V, P, A);
  cerr << solve.answer() << endl;
}
