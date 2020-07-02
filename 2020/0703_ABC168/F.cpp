#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/7/3 5:48:55
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
// ----- Yes() and No() -----
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}
void No()
{
  cout << "INF" << endl;
  exit(0);
}

// ----- 2D, 3D, 4D vectors -----
// Referring to ymatsux-san's source code: https://atcoder.jp/contests/abc138/submissions/7018300

template <typename T>
vector<vector<T>> Make2DVector(size_t d0, size_t d1, T v = T{})
{
  return vector<vector<T>>(d0, vector<T>(d1, v));
}

template <typename T>
vector<vector<vector<T>>> Make3DVector(size_t d0, size_t d1, size_t d2, T v = T{})
{
  return vector<vector<vector<T>>>(d0, Make2DVector(d1, d2, v));
}

template <typename T>
vector<vector<vector<vector<T>>>> Make4DVector(size_t d0, size_t d1, size_t d2, size_t d3, T v = T{})
{
  return vector<vector<vector<vector<T>>>>(d0, Make3DVector(d1, d2, d3, v));
}

// ----- Compressor -----
// referring to ymatsux-san's code:
// https://atcoder.jp/contests/abc168/submissions/13337691

template <typename T = ll>
class Compressor
{
  vector<T> raw;
  map<T, int> index;

public:
  Compressor() {}

  template <typename Container>
  Compressor(Container const &V) { append(V); }

  template <typename Iter>
  Compressor(Iter first, Iter last) { append(first, last); }

  template <typename Container>
  void append(Container const &V) { append(V.begin(), V.end()); }

  template <typename Iter>
  void append(Iter first, Iter last)
  {
    set<T> S(first, last);
    raw = vector<T>(S.begin(), S.end());
    sort(raw.begin(), raw.end());
    for (auto i = size_t{0}; i < raw.size(); ++i)
    {
      index[raw[i]] = i;
    }
  }

  T to_raw(int i) { return raw[i]; }
  int to_index(T t) { return index[t]; }
  size_t size() { return raw.size(); }
};

constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

// ----- Solve -----

struct Point
{
  int x, y;
};

class Solve
{
  int n, m;
  vector<ll> a, b, c, d, e, f;
  Compressor<ll> x, y;
  vector<vector<bool>> visited;
  vector<vector<vector<bool>>> dir;
  int size_x, size_y;

public:
  Solve(int n, int m) : n{n}, m{m}, a(n), b(n), c(n), d(n), e(n), f(n)
  {
    for (auto i{0}; i < n; ++i)
    {
      cin >> a[i] >> b[i] >> c[i];
    }
    for (auto i{0}; i < m; ++i)
    {
      cin >> d[i] >> e[i] >> f[i];
    }
    vector<ll> xs{mInfty<ll>(), 0LL, Infty<ll>()}, ys{mInfty<ll>(), 0LL, Infty<ll>()};
    copy(a.begin(), a.end(), back_inserter(xs));
    copy(b.begin(), b.end(), back_inserter(xs));
    copy(c.begin(), c.end(), back_inserter(ys));
    copy(d.begin(), d.end(), back_inserter(xs));
    copy(e.begin(), e.end(), back_inserter(ys));
    copy(f.begin(), f.end(), back_inserter(ys));
    x.append(xs);
    y.append(ys);
    size_x = x.size() - 1;
    size_y = y.size() - 1;
    visited = Make2DVector<bool>(size_x, size_y, false);
    dir = Make3DVector<bool>(size_x, size_y, 4, true);
    set_segment();
  }

  void flush()
  {
    bfs();
    cout << answer() << endl;
  }

private:
  void bfs()
  {
    queue<Point> q;
    {
      int i{x.to_index(0)};
      int j{y.to_index(0)};
      q.push(Point{i, j});
    }
    while (!q.empty())
    {
      auto p{q.front()};
      q.pop();
      for (auto k{0}; k < 4; ++k)
      {
        if (!dir[p.x][p.y][k])
        {
          continue;
        }
        auto nx{p.x + dx[k]};
        auto ny{p.y + dy[k]};
        if (!valid(nx, ny))
        {
          continue;
        }
        if (visited[nx][ny])
        {
          continue;
        }
        visited[nx][ny] = true;
        q.push(Point{nx, ny});
      }
    }
  }

  void set_segment()
  {
    for (auto i{0}; i < n; ++i)
    {
      set_segment_x(a[i], b[i], c[i]);
    }
    for (auto i{0}; i < m; ++i)
    {
      set_segment_y(d[i], e[i], f[i]);
    }
  }

  void set_segment_x(ll xa, ll xb, ll yc)
  {
    int ia = x.to_index(xa);
    int ib = x.to_index(xb);
    int jc = y.to_index(yc);
    for (auto i{ia}; i <= ib; ++i)
    {
      dir[i][jc - 1][1] = false;
      dir[i][jc][3] = false;
    }
  }

  void set_segment_y(ll xd, ll ye, ll yf)
  {
    int id = x.to_index(xd);
    int je = y.to_index(ye);
    int jf = y.to_index(yf);
    for (auto j{je}; j <= jf; ++j)
    {
      dir[id - 1][j][0] = false;
      dir[id][j][2] = false;
    }
  }

  bool valid(int i, int j)
  {
    return 0 <= i && i < size_x && 0 <= j && j < size_y;
  }

  ll area(int i, int j)
  {
    ll width{x.to_raw(i + 1) - x.to_raw(i)};
    ll height{y.to_raw(j + 1) - y.to_raw(j)};
    return height * width;
  }

  ll answer()
  {
    for (auto i{0}; i < size_x; ++i)
    {
      if (visited[i][0] || visited[i][size_y - 1])
      {
        No();
      }
    }
    for (auto j{0}; j < size_y; ++j)
    {
      if (visited[0][j] || visited[size_x - 1][j])
      {
        No();
      }
    }
    ll ans{0};
    for (auto i{0}; i < size_x; ++i)
    {
      for (auto j{0}; j < size_y; ++j)
      {
        if (visited[i][j])
        {
          ans += area(i, j);
        }
      }
    }
    return ans;
  }
};

// ----- main() -----

int main()
{
  int n, m;
  cin >> n >> m;
  Solve solve(n, m);
  solve.flush();
}
