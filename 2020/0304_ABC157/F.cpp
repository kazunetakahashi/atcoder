#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/18/2020, 4:39:27 AM
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
  cout << "No" << endl;
  exit(0);
}

// ----- Geometry Library -----
// http://www.prefield.com/algorithm/index.html

// ----- Basic Classes -----

constexpr ld EPSILON{1e-12};

// ----- Point -----

using Point = complex<ld>;
bool operator<(Point const &p, Point const &q)
{
  return real(p) != real(q) ? real(p) < real(q) : imag(p) < imag(q);
}
istream &operator>>(istream &is, Point &p)
{
  ld x, y;
  is >> x >> y;
  p = Point{x, y};
  return is;
}

ld OuterProduct(Point const &p, Point const &q)
{
  return imag(conj(p) * q);
}
ld InnerProduct(Point const &p, Point const &q)
{
  return real(conj(p) * q);
}

Point Normalize(Point const &p)
{
  return p / abs(p);
}

// ---- ccw -----

int ccw(Point a, Point b, Point c)
{
  b -= a;
  c -= a;
  auto tmp{OuterProduct(b, c)};
  if (tmp > 0)
  {
    return +1; // counter clockwise
  }
  if (tmp < 0)
  {
    return -1; // clockwise
  }
  if (InnerProduct(b, c) < 0)
  {
    return +2; // c--a--b on line
  }
  if (norm(b) < norm(c))
  {
    return -2; // a--b--c on line
  }
  return 0;
}

// ----- Geom -----

using Geom = vector<Point>;

Geom &operator+=(Geom &g, Point const &p)
{
  for (auto &q : g)
  {
    q += p;
  }
  return g;
}
Geom operator+(Geom const &g, Point const &p)
{
  Geom h{g};
  return h += p;
}
Geom &operator-=(Geom &g, Point const &p)
{
  return g += (-p);
}
Geom operator-(Geom const &g, Point const &p)
{
  return g + (-p);
}

// ----- Line -----

struct Segment;

struct Line : public Geom
{
  Line(Point const &p, Point const &q)
  {
    push_back(p);
    push_back(q);
  }
};

// ----- Segment -----

struct Segment : public Line
{
};

// ----- Circle -----

struct Circle
{
  Point p;
  ld r;

  Circle(Point const &p, ld r) : p(p), r(r) {}
};

// ----- Functions -----

// ----- Rotate -----

Point Rotate(Point const &p, ld radian = M_PI / 2)
{
  return p * Point{cos(radian), sin(radian)};
}
Geom Rotate(Geom g, ld radian = M_PI / 2)
{
  for (auto &p : g)
  {
    p = Rotate(p, radian);
  }
  return g;
}

// ----- Projection and Reflection (Point and Line) -----

Point Projection(Line const &l, Point const &p)
{
  ld t{InnerProduct(p - l[0], l[0] - l[1]) / norm(l[0] - l[1])};
  return l[0] + t * (l[0] - l[1]);
}

Point Reflection(Line const &l, Point const &p)
{
  return p + ld{2} * (Projection(l, p) - p);
}

// ----- Intersect -----

bool Intersect(Line const &l, Line const &m)
{
  return abs(OuterProduct(l[1] - l[0], m[1] - m[0])) > EPSILON || // non-parallel
         abs(OuterProduct(l[1] - l[0], m[0] - l[0])) < EPSILON;   // same line
}
bool Intersect(Line const &l, Segment const &s)
{
  return OuterProduct(l[1] - l[0], s[0] - l[0]) * OuterProduct(l[1] - l[0], s[1] - l[0]) < EPSILON;
}
bool Intersect(Segment const &s, Line const &l)
{
  return Intersect(l, s);
}
bool Intersect(Line const &l, Point const &p)
{
  return abs(OuterProduct(l[1] - p, l[0] - p)) < EPSILON;
}
bool Intersect(Point const &p, Line const &l)
{
  return Intersect(l, p);
}
bool Intersect(Segment const &s, Segment const &t)
{
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
bool Intersect(Segment const &s, Point const &p)
{
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPSILON; // triangle inequality
}
bool Intersect(Point const &p, Segment const &s)
{
  return Intersect(s, p);
}
bool Intersect(Circle const &a, Circle const &b)
{
  return a.r + b.r + EPSILON < abs(a.p - b.p);
}

// ----- Dist -----

ld Dist(Point const &p, Point const &q)
{
  return abs(p - q);
}
ld Dist(Line const &l, Point const &p)
{
  return abs(p - Projection(l, p));
}
ld Dist(Point const &p, Line const &l)
{
  return Dist(l, p);
}
ld Dist(Line const &l, Line const &m)
{
  return Intersect(l, m) ? 0 : Dist(l, m[0]);
}
ld Dist(Line const &l, Segment const &s)
{
  if (Intersect(l, s))
  {
    return 0;
  }
  return min(Dist(l, s[0]), Dist(l, s[1]));
}
ld Dist(Segment const &s, Line const &l)
{
  return Dist(l, s);
}
ld Dist(Segment const &s, Point const &p)
{
  auto r{Projection(static_cast<Line>(s), p)};
  if (Intersect(s, r))
  {
    return abs(r - p);
  }
  return min(abs(s[0] - p), abs(s[1] - p));
}
ld Dist(Point const &p, Segment const &s)
{
  return Dist(s, p);
}
ld Dist(Segment const &s, Segment const &t)
{
  if (Intersect(s, t))
  {
    return 0;
  }
  return min({Dist(s, t[0]), Dist(s, t[1]), Dist(t, s[0]), Dist(t, s[1])});
}

// ----- IntersectionPoints ------

vector<Point> IntersectionPoints(Circle const &a, Circle const &b)
{
  auto d{Dist(a.p, b.p)};
  if (a.r + b.r + EPSILON < d)
  {
    return {};
  }
  auto l{(a.r * a.r - b.r * b.r + d * d) / (2 * d)};
  auto tmp{a.r * a.r - l * l};
  if (tmp <= 0)
  {
    return {};
  }
  auto h{sqrt(tmp)};
  vector<Point> res;
  auto v{Normalize(b.p - a.p)};
  auto w{Rotate(v)};
  res.push_back(a.p + v * l + w * h);
  res.push_back(a.p + v * l - w * h);
  return res;
}

vector<Point> IntersectionPoints(Line const &l, Line const &m)
{
  auto A{OuterProduct(l[1] - l[0], m[1] - m[0])};
  auto B{OuterProduct(l[1] - l[0], l[1] - m[0])};
  if (abs(A) < EPSILON && abs(B) < EPSILON)
  {
    return {m[0], m[1], l[0], l[1]}; // same line
  }
  if (abs(A) < EPSILON)
  {
    assert(false); // Precondition is not satisfied.
  }
  return {m[0] + B / A * (m[1] - m[0])};
}

// ----- Contains -----

enum class ContainState
{
  OUT,
  ON,
  IN
};

ContainState Contains(Geom const &g, Point const &p)
{
  bool in{false};
  for (auto i{size_t{0}}; i < g.size(); ++i)
  {
    auto a{g[i] - p};
    auto b{g[(i + 1) % g.size()] - p};
    if (imag(a) > imag(b))
    {
      swap(a, b);
    }
    if (imag(a) <= 0 && 0 < imag(b) && OuterProduct(a, b) < 0)
    {
      in = !in;
    }
    if (abs(OuterProduct(a, b)) < EPSILON && InnerProduct(a, b) < EPSILON)
    {
      return ContainState::ON;
    }
  }
  return in ? ContainState::IN : ContainState::OUT;
}

ContainState Contains(Circle const &c, Point const &p)
{
  auto d{Dist(c.p, p)};
  if (abs(d - c.r) < EPSILON)
  {
    return ContainState::ON;
  }
  if (d > c.r)
  {
    return ContainState::OUT;
  }
  return ContainState::IN;
}

bool ContainStateToBool(ContainState s)
{
  return s == ContainState::IN || s == ContainState::ON;
}

template <typename T, typename U>
bool DoesContain(T const &a, U const &b)
{
  return ContainStateToBool(Contains(a, b));
}

// ----- Solve -----

class Solve
{
  int N;
  vector<Point> P;
  vector<ld> c;
  vector<Circle> C;
  vector<Point> X;

public:
  Solve(int N) : N{N}, P(N), c(N)
  {
    for (auto i{0}; i < N; ++i)
    {
      cin >> P[i] >> c[i];
    }
  }

  void flush()
  {
    cout << fixed << setprecision(12) << binary_search() << endl;
  }

private:
  bool burn(ld T)
  {
    C.clear();
    X.clear();
    for (auto i{0}; i < N; ++i)
    {
      C.push_back(Circle{P[i], T / c[i]});
    }
    for (auto i{0}; i < N; ++i)
    {
      for (auto j{i + 1}; j < N; ++j)
      {
        auto tmp{IntersectionPoints(C[i], C[j])};
        copy(tmp.begin(), tmp.end(), back_inserter(X));
      }
    }
    for (auto const &p : X)
    {
      bool ok{true};
      for (auto i{0}; i < N; ++i)
      {
        if (!DoesContain(C[i], p))
        {
          ok = false;
          break;
        }
      }
      if (ok)
      {
        return true;
      }
    }
    return false;
  }

  ld binary_search()
  {
    ld lb{0};
    ld ub{100000};
    for (auto q{0}; q < 100; ++q)
    {
      ld t{(lb + ub) / 2};
      if (burn(t))
      {
        lb = t;
      }
      else
      {
        ub = t;
      }
    }
    return lb;
  }
};

// ----- main() -----

int main()
{
  int N;
  Solve solve(N);
  solve.flush();
}
