#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 5/17/2020, 11:21:17 PM
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
ll MOD;
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
Mint operator+(ll lhs, const Mint &rhs)
{
  return rhs + lhs;
}
Mint operator-(ll lhs, const Mint &rhs)
{
  return -rhs + lhs;
}
Mint operator*(ll lhs, const Mint &rhs)
{
  return rhs * lhs;
}
Mint operator/(ll lhs, const Mint &rhs)
{
  return Mint{lhs} / rhs;
}
istream &operator>>(istream &stream, Mint &a)
{
  return stream >> a.x;
}
ostream &operator<<(ostream &stream, const Mint &a)
{
  return stream << a.x;
}
// ----- for C++14 -----
using mint = Mint;
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
// constexpr ll infty{1000000000000000LL}; // or
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

// ----- Mat and Vec -----

template <typename T = ll>
using Vec = vector<T>;
template <typename T = ll>
using Mat = vector<Vec<T>>;

// operators of Vec / Mat

template <typename T = ll>
Vec<T> operator+(Vec<T> const &A)
{
  return A;
}

template <typename T = ll>
Mat<T> operator+(Mat<T> const &A)
{
  return A;
}

template <typename T = ll>
Vec<T> operator+(Vec<T> const &A, Vec<T> const &B)
{
  assert(A.size() == B.size());
  Vec<T> C(A.size());
  for (auto i = 0u; i < A.size(); i++)
  {
    C[i] = A[i] + B[i];
  }
  return C;
}

template <typename T = ll>
Mat<T> operator+(Mat<T> const &A, Mat<T> const &B)
{
  assert(A.size() == B.size());
  assert(A[0].size() == B[0].size());
  Mat<T> C(A.size(), Vec<T>(A[0].size()));
  for (auto i = 0u; i < A.size(); i++)
  {
    for (auto j = 0u; j < A[0].size(); j++)
    {
      C[i][j] += A[i][j] + B[i][j];
    }
  }
  return C;
}

template <typename T = ll>
Vec<T> &operator+=(Vec<T> &A, Vec<T> const &B)
{
  assert(A.size() == B.size());
  for (auto i = 0u; i < A.size(); i++)
  {
    A[i] += B[i];
  }
  return A;
}

template <typename T = ll>
Mat<T> &operator+=(Mat<T> &A, Mat<T> const &B)
{
  assert(A.size() == B.size());
  assert(A[0].size() == B[0].size());
  for (auto i = 0u; i < A.size(); i++)
  {
    for (auto j = 0u; j < A[0].size(); j++)
    {
      A[i][j] += B[i][j];
    }
  }
  return A;
}

template <typename T = ll>
Vec<T> operator-(Vec<T> const &A)
{
  Vec<T> C(A.size());
  for (auto i = 0u; i < A.size(); i++)
  {
    C[i] = -A[i];
  }
  return C;
}

template <typename T = ll>
Mat<T> operator-(Mat<T> const &A)
{
  Mat<T> C(A.size(), Vec<T>(A[0].size()));
  for (auto i = 0u; i < A.size(); i++)
  {
    for (auto j = 0u; j < A[0].size(); j++)
    {
      C[i][j] = -A[i][j];
    }
  }
  return C;
}

template <typename T = ll>
Vec<T> operator-(Vec<T> const &A, Vec<T> const &B)
{
  return A + (-B);
}

template <typename T = ll>
Mat<T> operator-(Mat<T> const &A, Mat<T> const &B)
{
  return A + (-B);
}

template <typename T = ll>
Vec<T> &operator-=(Vec<T> &A, Vec<T> const &B)
{
  return A += (-B);
}

template <typename T = ll>
Mat<T> &operator-=(Mat<T> &A, Mat<T> const &B)
{
  return A += (-B);
}

template <typename T = ll>
Vec<T> operator*(T K, Vec<T> const &A)
{
  Vec<T> C(A.size());
  for (auto i = 0u; i < A.size(); i++)
  {
    C[i] + A[i] * K;
  }
  return C;
}

template <typename T = ll>
Mat<T> operator*(T K, Mat<T> const &A)
{
  Mat<T> C(A.size(), Vec<T>(A[0].size()));
  for (auto i = 0u; i < A.size(); i++)
  {
    for (auto j = 0u; j < A[0].size(); j++)
    {
      C[i][j] + A[i][j] * K;
    }
  }
  return C;
}

template <typename T = ll>
Vec<T> operator*(Vec<T> const &A, T K)
{
  return K * A;
}

template <typename T = ll>
Mat<T> operator*(Mat<T> const &A, T K)
{
  return K * A;
}

template <typename T = ll>
Vec<T> &operator*=(Vec<T> const &A, T K)
{
  for (auto i = 0u; i < A.size(); i++)
  {
    A[i] *= K;
  }
  return A;
}

template <typename T = ll>
Mat<T> operator*=(Mat<T> const &A, T K)
{
  for (auto i = 0u; i < A.size(); i++)
  {
    for (auto j = 0u; j < A[0].size(); j++)
    {
      A[i][j] *= K;
    }
  }
  return A;
}

template <typename T = ll>
Vec<T> operator/(Vec<T> const &A, T K)
{
  return A * (1 / K);
}

template <typename T = ll>
Mat<T> operator/(Mat<T> const &A, T K)
{
  return A * (1 / K);
}

template <typename T = ll>
Vec<T> &operator/=(Vec<T> &A, T K)
{
  return A *= (1 / K);
}

template <typename T = ll>
Mat<T> &operator/=(Mat<T> &A, T K)
{
  return A *= (1 / K);
}

// multiply operators

template <typename T = ll>
Mat<T> operator*(Mat<T> const &A, Mat<T> const &B)
{
  assert(A[0].size() == B.size());
  Mat<T> C(A.size(), Vec<T>(B[0].size()));
  for (auto i = 0u; i < A.size(); i++)
  {
    for (auto j = 0u; j < B[0].size(); j++)
    {
      for (auto k = 0u; k < A[0].size(); k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

template <typename T = ll>
Vec<T> operator*(Mat<T> const &A, Vec<T> const &V)
{
  assert(A[0].size() == V.size());
  Vec<T> W(A.size());
  for (auto i = 0u; i < A.size(); i++)
  {
    for (auto j = 0; j < A[0].size(); j++)
    {
      W[i] += A[i][j] * V[j];
    }
  }
  return W;
}

template <typename T = ll>
Mat<T> power(Mat<T> const &A, ll N)
{
  assert(A.size() == A[0].size());
  Mat<T> B(A.size(), Vec<T>(A.size(), 1));
  while (N > 0)
  {
    if (N & 1)
    {
      B *= A;
    }
    A *= A;
    N >>= 1;
  }
  return B;
}

// ----- main() -----

ll L, A, B;

int f(ll i)
{
  return to_string(A + B * i).size();
}

int main()
{
  cin >> L >> A >> B >> MOD;
  vector<ll> delta(19);
  delta[0] = 0;
  for (auto i = 1; i <= 18; ++i)
  {
    ll ng{delta[i - 1] - 1};
    ll ok{L};
    while (abs(ok - ng) > 1)
    {
      ll t{(ok + ng) / 2};
      if (f(t) != i)
      {
        ok = t;
      }
      else
      {
        ng = t;
      }
    }
    delta[i] = ok;
  }
  vector<ll> n(18);
  for (auto i = 0; i < 18; ++i)
  {
    n[i] = delta[i + 1] - delta[i];
  }
  vector<Mat<mint>> M(18);
}
