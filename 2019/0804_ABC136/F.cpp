#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 5/23/2020, 3:38:16 PM
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
  const Mint power(ll N) const
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

// ----- SegTree -----

template <typename T>
class SegTree
{ // 0-indexed, [0, N).
private:
  int N;
  vector<T> dat;
  T unit;  // モノイドの単位元
  T(*func) // モノイドの演算
  (T, T);
  T(*_update) // update で値をどうするか書く
  (T, T);

public:
  SegTree() {}

  SegTree(int n, T unit, T (*func)(T, T), T (*_update)(T, T)) : N{1}, unit{unit}, func{func}, _update{_update}
  {
    while (N < n)
    {
      N *= 2;
    }
    dat = vector<T>(2 * N - 1, unit);
  }

  void update(int k, T a)
  {
    k += N - 1;
    dat[k] = _update(dat[k], a);
    while (k > 0)
    {
      k = (k - 1) / 2;
      dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

private:
  T find(int a, int b, int k, int l, int r)
  {
    if (r <= a || b <= l)
    {
      return unit;
    }
    if (a <= l && r <= b)
    {
      return dat[k];
    }
    T vl = find(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = find(a, b, k * 2 + 2, (l + r) / 2, r);
    return func(vl, vr);
  }

public:
  T find(int a, int b)
  { // [a, b) の find をする。
    return find(a, b, 0, 0, N);
  }
};

// ----- frequently used examples -----

// for +
auto func2 = [](auto x, auto y) {
  return x + y;
};
auto _update2 = [](auto x, auto y) {
  return y;
};
constexpr ll unit2{0LL};
// SegTree<ll> tree2{N, unit2, func2, _update2};

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
};

// ----- main() -----

using Point = tuple<int, int>;
const mint two{2};

int main()
{
  ll N;
  cin >> N;
  vector<Point> P(N);
  vector<int> VX, VY;
  for (auto i = 0LL; i < N; ++i)
  {
    int x, y;
    cin >> x >> y;
    P[i] = Point{x, y};
    VX.push_back(x);
    VY.push_back(y);
  }
  Compressor<int> X{VX}, Y{VY};
  vector<int> I(N);
  for (auto i = 0LL; i < N; ++i)
  {
    int x, y;
    tie(x, y) = P[i];
    I[X.to_index(x)] = Y.to_index(y);
  }
  SegTree<ll> tree{static_cast<int>(N), unit2, func2, _update2};
  mint ans{0};
  for (auto i = 0LL; i < N; ++i)
  {
    ll a{tree.find(0, I[i])};
    ll b{i - a};
    ll c{I[i] - a};
    ll d{N - a - b - c - 1};
#if DEBUG == 1
    cerr << "I[" << i << "] = " << I[i] << endl;
    cerr << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;
#endif
    ans += two.power(N) - 1 - two.power(a + b) - two.power(a + c) - two.power(b + d) - two.power(c + d) + two.power(a) + two.power(b) + two.power(c) + two.power(d);
    tree.update(I[i], 1);
  }
  cout << ans << endl;
}
