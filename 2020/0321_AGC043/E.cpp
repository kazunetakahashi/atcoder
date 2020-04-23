#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 4/23/2020, 7:08:47 PM
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
  Mint &operator++(int)
  {
    Mint tmp{*this};
    ++*this;
    return tmp;
  }
  Mint &operator--() { return *this -= 1; }
  Mint &operator--(int)
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

// ----- Point -----

using Point = tuple<int, int>;

ostream &operator<<(ostream &os, Point const &pt)
{
  return os << get<0>(pt) << " " << get<1>(pt);
}

// ----- Cycle -----

class Cycle
{
  int num;
  bool pos;

public:
  Cycle(int num, bool pos) : num{num}, pos{pos} {}

  vector<Point> path() const
  {
    vector<Point> ans;
    for (auto i = 0; i <= num; ++i)
    {
      ans.push_back(Point(i, 0));
    }
    if (pos)
    {
      ans.push_back(Point(num + 1, 0));
      ans.push_back(Point(num + 1, 1));
      ans.push_back(Point(num, 1));
    }
    else
    {
      ans.push_back(Point(num, 1));
      ans.push_back(Point(num + 1, 1));
      ans.push_back(Point(num + 1, 0));
    }
    for (auto i = num; i >= 1; --i)
    {
      ans.push_back(Point(i, 0));
    }
    return ans;
  }

  Cycle inv() const
  {
    return Cycle(num, !pos);
  }
};

class Chain
{
  vector<Cycle> V;

public:
  Chain() {}
  Chain(Cycle c) : V{c} {}
  Chain(vector<Cycle> V) : V(V) {}

  Chain(int mask)
  {
    int cnt{0};
    while ((mask >> cnt) != 0)
    {
      if ((mask >> cnt) & 1)
      {
        merge(cnt);
      }
      ++cnt;
    }
  }

  vector<Point> path() const
  {
    vector<Point> ans;
    for (auto const &e : V)
    {
      auto tmp{e.path()};
      copy(tmp.begin(), tmp.end(), back_inserter(ans));
    }
    return ans;
  }

  vector<Cycle> const &seq() const
  {
    return V;
  }

  void operator+=(Chain const &other)
  {
    copy(other.seq().begin(), other.seq().end(), back_inserter(V));
  }

private:
  void merge(int n)
  {
    if (V.empty())
    {
      V.push_back(Cycle{n, true});
    }
    else
    {
      auto inverse{inv()};
      *this += Chain{Cycle{n, true}};
      *this += inverse;
      *this += Chain{Cycle{n, false}};
    }
  }

  Chain inv() const
  {
    vector<Cycle> W;
    for (auto it = V.rbegin(); it != V.rend(); ++it)
    {
      W.push_back(it->inv());
    }
    return Chain(W);
  }
};

// ----- Solve -----

class Solve
{
  int N;
  vector<bool> V;
  Chain C;
  bool possible;

public:
  Solve(int N, string A) : N{N}, V(1 << N), possible{true}
  {
    for (auto i = 0; i < 1 << N; ++i)
    {
      V[i] = (A[i] == '1');
    }
  }

  void answer()
  {
    if (check())
    {
      construct();
    }
    else
    {
      possible = false;
    }
    flush();
  }

private:
  bool check() const
  {
    for (auto i = 0; i < 1 << N; ++i)
    {
      for (auto j = 0; j < 1 << N; ++j)
      {
        if ((i & j) == j)
        {
          if (!V[j] && V[i])
          {
            return false;
          }
        }
      }
    }
    return true;
  }

  void construct()
  {
    for (auto i = 0; i < 1 << N; ++i)
    {
      if (V[i])
      {
        continue;
      }
      bool create{true};
      for (auto j = 0; j < 1 << N; ++j)
      {
        if ((i & j) == j && !V[j])
        {
          create = false;
          break;
        }
      }
      if (create)
      {
        C += Chain(i);
      }
    }
  }

  void flush() const
  {
    if (possible)
    {
      cout << "Possible" << endl;
    }
    else
    {
      cout << "Impossible" << endl;
      return;
    }
    for (auto const &e : C.path())
    {
      cout << e << endl;
    }
  }
};

// ----- main() -----

int main()
{
  int N;
  cin >> N;
  string A;
  cin >> A;
  Solve solve(N, A);
  solve.answer();
}
