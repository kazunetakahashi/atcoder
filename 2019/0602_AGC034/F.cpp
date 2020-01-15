#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 1/15/2020, 2:31:58 PM
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
#include <boost/multiprecision/cpp_int.hpp>
// ----- using directives and manipulations -----
using boost::rational;
using boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
// ----- constexpr for Mint and Combination -----
// constexpr ll MOD{1000000007LL};
constexpr ll MOD{998244353LL}; // be careful
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
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
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

template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> const &V)
{
  os << "{";
  for (auto const &v : V)
  {
    os << "{";
    for (auto x : v)
    {
      os << x << ", ";
    }
    os << "}, ";
  }
  return os << "}";
}

vector<vector<mint>> next_line(vector<vector<mint>> const &V)
{
  vector<vector<mint>> W;
  for (auto const &v : V)
  {
    vector<mint> v0, v1;
    for (auto i = 0; i + 1 < static_cast<int>(v.size()); i += 2)
    {
      v0.push_back(v[i] + v[i + 1]);
      v1.push_back(v[i] - v[i + 1]);
    }
    W.push_back(v0);
    W.push_back(v1);
  }
  return W;
}

vector<vector<mint>> divide(vector<vector<mint>> const &B, vector<vector<mint>> const &C)
{
  assert(B.size() == C.size());
  vector<vector<mint>> W(B.size(), vector<mint>(1));
  for (auto i = 0; i < static_cast<int>(B.size()); i++)
  {
    assert(B[i].size() == 1);
    assert(C[i].size() == 1);
    if (B[i][0] == 0)
    {
      assert(C[i][0] == 0);
      W[i][0] = 0;
    }
    else
    {
      W[i][0] = C[i][0] / B[i][0];
    }
  }
  return W;
}

vector<vector<mint>> prev_line(vector<vector<mint>> const &V)
{
  vector<vector<mint>> W;
  for (auto i = 0; i + 1 < static_cast<int>(V.size()); i += 2)
  {
    vector<mint> w;
    assert(V[i].size() == V[i + 1].size());
    for (auto j = 0; j < static_cast<int>(V[i].size()); j++)
    {
      w.push_back((V[i][j] + V[i + 1][j]) / 2);
      w.push_back((V[i][j] - V[i + 1][j]) / 2);
    }
    W.push_back(w);
  }
  return W;
}

int main()
{
  int N;
  cin >> N;
  int B{1};
  for (auto i = 0; i < N; i++)
  {
    B *= 2;
  }
  vector<mint> A(B);
  for (auto i = 0; i < B; i++)
  {
    cin >> A[i];
  }
  mint S{accumulate(A.begin(), A.end(), mint{0})};
  vector<mint> P(B);
  for (auto i = 0; i < B; i++)
  {
    P[i] = A[i] / S;
  }
  vector<mint> X(B, -1);
  X[0] = B - 1;
  vector<vector<vector<mint>>> a(N + 1), b(N + 1), c(N + 1);
  b[0].push_back(P);
  b[0][0][0] -= 1;
  c[0].push_back(X);
  cerr << "b[" << 0 << "] = " << b[0] << endl;
  for (auto k = 0; k < N; k++)
  {
    b[k + 1] = next_line(b[k]);
    cerr << "b[" << k + 1 << "] = " << b[k + 1] << endl;
  }
  cerr << "c[" << 0 << "] = " << c[0] << endl;
  for (auto k = 0; k < N; k++)
  {
    c[k + 1] = next_line(c[k]);
    cerr << "c[" << k + 1 << "] = " << c[k + 1] << endl;
  }
  a[0] = divide(b[N], c[N]);
  for (auto k = 0; k < N; k++)
  {
    a[k + 1] = prev_line(a[k]);
  }
  auto &v{a[N][0]};
  for (auto &x : v)
  {
    x -= v[0];
  }
  for (auto x : v)
  {
    cout << x << endl;
  }
}
