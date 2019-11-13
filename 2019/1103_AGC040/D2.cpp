#define DEBUG 1
/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 11/13/2019, 7:24:07 PM
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
#include <boost/rational.hpp>
using boost::rational;
using namespace std;
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
using ll = long long;
constexpr ll MOD{1000000007LL};
constexpr ll MAX_SIZE{3000010LL};
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
// for C++14
using mint = Mint<MOD>;
using combination = Combination<MOD, MAX_SIZE>;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// constexpr double epsilon{1e-10};
// constexpr ll infty{1000000000000000LL};
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}
void No()
{
  cout << "0 1" << endl;
  exit(0);
}

using Info = tuple<ll, ll>;

int main()
{
  int N;
  cin >> N;
  vector<Info> V(N);
  ll A_sum{0LL};
  for (auto i = 0; i < N; i++)
  {
    ll A, B;
    cin >> A >> B;
    V[i] = Info(max(A, B), B);
    A_sum += A;
  }
  sort(V.rbegin(), V.rend());
  vector<ll> C_sum(N + 1);
  C_sum[0] = 0;
  for (auto i = 0; i < N; i++)
  {
#if DEBUG == 1
    cerr << "C_sum[" << i + 1 << " = " << C_sum[i + 1] << endl;
#endif
    C_sum[i + 1] = C_sum[i] + get<0>(V[i]);
  }
  if (C_sum[N] == A_sum)
  {
    No();
  }
  rational<ll> ans{0, 1};
#if DEBUG == 1
  cerr << "A_sum = " << A_sum << endl;
#endif
  for (auto k = 0; k < N; k++)
  {
    ll B_k{get<1>(V[k])};
    ll ok{N}, ng{-1};
    ll tmp_sum{0};
    bool included{false};
    while (abs(ok - ng) > 1)
    {
      ll t{(ok + ng) / 2};
      ll tmp{C_sum[t]};
      if (k < t)
      {
        tmp -= B_k;
      }
      if (tmp + B_k >= A_sum)
      {
        ok = t;
        included = k < t;
        tmp_sum = tmp;
      }
      else
      {
        ng = t;
      }
    }
    rational<ll> r{A_sum - tmp_sum, B_k};
#if DEBUG == 1
    cerr << "k = " << k << ", B_k = " << B_k << ", tmp_sum = " << tmp_sum << ", r = " << r << endl;
#endif
    ll M{included ? ok - 1 : ok};
#if DEBUG == 1
    cerr << "ok = " << ok << ", included = " << included << ", M = " << M << ", r = " << r << endl;
#endif
    rational<ll> tmp_ans = (N - M - r) / N;
#if DEBUG == 1
    cerr << "tmp_ans = " << tmp_ans << endl;
#endif
    if (r < 0)
    {
      continue;
    }
    ch_max(ans, tmp_ans);
  }
  cout << ans.numerator() << " " << ans.denominator() << endl;
}
