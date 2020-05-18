#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 5/18/2020, 3:01:31 PM
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
constexpr ll infty{1000000000000000LL}; // or
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

// ----- Point -----

class Point
{
public:
  ll x, v;

  Point() {}
  Point(ll x, ll v) : x{x}, v{v} {}

  double now(double t) const { return x + v * t; }
};

double cross(Point const &p, Point const &q)
{
  if (q.v == p.v)
  {
    return 0.0;
  }
  return (static_cast<double>(p.x) - q.x) / (q.v - p.v);
}

bool operator<(Point const &p, Point const &q)
{
  assert(p.v == q.v);
  return p.x < q.x;
}

// ----- Axis -----

class Axis
{
  vector<vector<Point>> points;
  vector<Point> candidates;
  vector<double> snapshots;

public:
  Axis(vector<Point> const &V) : points(3)
  {
    for (auto const &p : V)
    {
      points[p.v].push_back(p);
    }
    for (auto i = 0; i < 3; ++i)
    {
      if (points[i].empty())
      {
        continue;
      }
      candidates.push_back(*max_element(points[i].begin(), points[i].end()));
      candidates.push_back(*min_element(points[i].begin(), points[i].end()));
    }
    for (auto it = candidates.begin(); it != candidates.end(); ++it)
    {
      for (auto it2 = it + 1; it2 != candidates.end(); ++it2)
      {
        double tmp{cross(*it, *it2)};
        if (tmp >= 0)
        {
          snapshots.push_back(tmp);
        }
      }
    }
  }

  double delta(double t) const;

  vector<double> const &timer() const { return snapshots; }
};

double Axis::delta(double t) const
{
  vector<double> V;
  for (auto const &p : candidates)
  {
    V.push_back(p.now(t));
  }
  return *max_element(V.begin(), V.end()) - *min_element(V.begin(), V.end());
}

// ----- main() -----

int main()
{
  vector<Point> PX, PY;
  int N;
  cin >> N;
  for (auto i = 0; i < N; ++i)
  {
    ll x, y;
    char c;
    cin >> x >> y >> c;
    if (c == 'R')
    {
      PX.emplace_back(x, 2);
      PY.emplace_back(y, 1);
    }
    else if (c == 'L')
    {
      PX.emplace_back(x, 0);
      PY.emplace_back(y, 1);
    }
    else if (c == 'U')
    {
      PX.emplace_back(x, 1);
      PY.emplace_back(y, 2);
    }
    else
    {
      PX.emplace_back(x, 1);
      PY.emplace_back(y, 0);
    }
  }
  Axis X(PX), Y(PY);
  vector<double> timer = {0};
  copy(X.timer().begin(), X.timer().end(), back_inserter(timer));
  copy(Y.timer().begin(), Y.timer().end(), back_inserter(timer));
  double ans{infty};
  for (auto t : timer)
  {
    ch_min(ans, X.delta(t) * Y.delta(t));
#if DEBUG == 1
    cerr << "t = " << t << ", X.delta = " << X.delta(t) << ", Y.delta = " << Y.delta(t) << endl;
#endif
  }
  cout << fixed << setprecision(15) << ans << endl;
}
