#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/7/1 1:44:15
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
using ll = unsigned long long;
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
  cout << "-1" << endl;
  exit(0);
}

// ----- Solve -----

class Solve
{
  int n;
  vector<bool> s, t, u, v;
  vector<vector<int>> res;

public:
  Solve(int n, vector<bool> s, vector<bool> t, vector<bool> u, vector<bool> v) : n{n}, s{s}, t{t}, u{u}, v{v}, res(n, vector<int>(n, -1))
  {
#if DEBUG == 1
    cerr << "problem: " << endl;
    for (auto i{0}; i < n; ++i)
    {
      cerr << "s[" << i << "] = " << s[i] << endl;
    }
    for (auto i{0}; i < n; ++i)
    {
      cerr << "t[" << i << "] = " << t[i] << endl;
    }
    for (auto i{0}; i < n; ++i)
    {
      cerr << "u[" << i << "] = " << u[i] << endl;
    }
    for (auto i{0}; i < n; ++i)
    {
      cerr << "v[" << i << "] = " << v[i] << endl;
    }
#endif
  }

  vector<vector<int>> answer()
  {
    prepare();
    fill_zero();
    fixed_up();
#if DEBUG == 1
    for (auto i{0}; i < n; ++i)
    {
      for (auto j{0}; j < n; ++j)
      {
        cerr << res[i][j];
        if (j < n - 1)
        {
          cerr << " ";
        }
        else
        {
          cerr << endl;
        }
      }
    }
#endif
    final_check();
    return res;
  }

private:
  void ch(int i, int j, int v)
  {
    if (res[i][j] == -1)
    {
      res[i][j] = v;
    }
    else if (res[i][j] != v)
    {
      No();
    }
  }

  void final_check()
  {
    for (auto i{0}; i < n; ++i)
    {
      int tmp{res[i][0]};
      if (!s[i])
      {
        for (auto j{0}; j < n; ++j)
        {
          tmp &= res[i][j];
        }
      }
      else
      {
        for (auto j{0}; j < n; ++j)
        {
          tmp |= res[i][j];
        }
      }
      if (tmp != u[i])
      {
        No();
      }
    }
    for (auto j{0}; j < n; ++j)
    {
      int tmp{res[0][j]};
      if (!t[j])
      {
        for (auto i{0}; i < n; ++i)
        {
          tmp &= res[i][j];
        }
      }
      else
      {
        for (auto i{0}; i < n; ++i)
        {
          tmp |= res[i][j];
        }
      }
      if (tmp != v[j])
      {
        No();
      }
    }
  }

  void fixed_up()
  {
    for (auto i{0}; i < n; ++i)
    {
#if DEBUG == 1
      cerr << "i = " << i << endl;
#endif
      if (!(s[i] && u[i]))
      {
        continue;
      }
      bool ok{false};
      for (auto j{0}; j < n; ++j)
      {
        if (res[i][j] == 1)
        {
          ok = true;
          break;
        }
      }
      if (ok)
      {
        continue;
      }
      for (auto j{0}; j < n; ++j)
      {
        if (!(!t[j] && !v[j]))
        {
          continue;
        }
        int cnt{0};
        for (auto k{0}; k < n; ++k)
        {
          if (res[k][j] == 0)
          {
            ++cnt;
          }
        }
#if DEBUG == 1
        cerr << "cnt = " << cnt << endl;
#endif
        if (cnt <= 1)
        {
          continue;
        }
        res[i][j] = 1;
        ok = true;
        break;
      }
      if (!ok)
      {
        No();
      }
    }
    for (auto j{0}; j < n; ++j)
    {
      if (!(t[j] && v[j]))
      {
        continue;
      }
      bool ok{false};
      for (auto i{0}; i < n; ++i)
      {
        if (res[i][j] == 1)
        {
          ok = true;
          break;
        }
      }
      if (ok)
      {
        continue;
      }
      for (auto i{0}; i < n; ++i)
      {
        if (!(!s[j] && !u[j]))
        {
          continue;
        }
        int cnt{0};
        for (auto k{0}; k < n; ++k)
        {
          if (res[i][k] == 0)
          {
            ++cnt;
          }
        }
        if (cnt <= 1)
        {
          continue;
        }
        res[i][j] = 1;
        ok = true;
        break;
      }
      if (!ok)
      {
        No();
      }
    }
  }

  void fill_zero()
  {
    for (auto i{0}; i < n; ++i)
    {
      for (auto j{0}; j < n; ++j)
      {
        if (res[i][j] == -1)
        {
          res[i][j] = 0;
        }
      }
    }
  }

  void prepare()
  {
    for (auto i{0}; i < n; ++i)
    {
      if (!s[i] && u[i])
      {
        for (auto j{0}; j < n; ++j)
        {
          ch(i, j, 1);
        }
      }
      else if (s[i] && !u[i])
      {
        for (auto j{0}; j < n; ++j)
        {
          ch(i, j, 0);
        }
      }
    }
    for (auto i{0}; i < n; ++i)
    {
      if (!t[i] && v[i])
      {
        for (auto j{0}; j < n; ++j)
        {
          ch(j, i, 1);
        }
      }
      else if (t[i] && !v[i])
      {
        for (auto j{0}; j < n; ++j)
        {
          ch(j, i, 0);
        }
      }
    }
    for (auto i{0}; i < n; ++i)
    {
      for (auto j{0}; j < n; ++j)
      {
        if (res[i][j] == -1)
        {
          if (u[i] && v[j])
          {
            res[i][j] = 1;
          }
          else if (!u[i] && !v[j])
          {
            res[i][j] = 0;
          }
        }
      }
    }
  }
};

// ----- main() -----

constexpr int C{64};

int main()
{
  int n;
  cin >> n;
  vector<bool> s(n), t(n);
  vector<ll> us(n), vs(n);
  for (auto i{0}; i < n; ++i)
  {
    int x;
    cin >> x;
    s[i] = x;
  }
  for (auto i{0}; i < n; ++i)
  {
    int x;
    cin >> x;
    t[i] = x;
  }
  for (auto i{0}; i < n; ++i)
  {
    cin >> us[i];
  }
  for (auto i{0}; i < n; ++i)
  {
    cin >> vs[i];
  }
  vector<vector<ll>> ans(n, vector<ll>(n, 0));
  for (auto k{0}; k < C; ++k)
  {
    vector<bool> u(n), v(n);
    for (auto i{0}; i < n; ++i)
    {
      u[i] = (us[i] >> k & 1);
    }
    for (auto i{0}; i < n; ++i)
    {
      v[i] = (vs[i] >> k & 1);
    }
    Solve solve(n, s, t, u, v);
    auto res{solve.answer()};
    for (auto i{0}; i < n; ++i)
    {
      for (auto j{0}; j < n; ++j)
      {
        ans[i][j] |= static_cast<ll>(res[i][j]) << k;
      }
    }
#if DEBUG == 1
    for (auto i{0}; i < n; ++i)
    {
      for (auto j{0}; j < n; ++j)
      {
        cerr << ans[i][j];
        if (j < n - 1)
        {
          cerr << " ";
        }
        else
        {
          cerr << endl;
        }
      }
    }
#endif
    for (auto i{0}; i < n; ++i)
    {
      auto tmp{ans[i][0]};
      if (!s[i])
      {
        for (auto j{0}; j < n; ++j)
        {
          tmp &= ans[i][j];
        }
      }
      else
      {
        for (auto j{0}; j < n; ++j)
        {
          tmp |= ans[i][j];
        }
      }
      if (tmp != (us[i] & ((1ULL << k) - 1)))
      {
#if DEBUG == 1
        cerr << "failed: k = " << k << ", i = " << i << endl;
        cerr << "tmp = " << tmp << ", " << (us[i] & ((1ULL << k) - 1)) << endl;
#endif
        No();
      }
    }
    for (auto j{0}; j < n; ++j)
    {
      auto tmp{ans[0][j]};
      if (!t[j])
      {
        for (auto i{0}; i < n; ++i)
        {
          tmp &= ans[i][j];
        }
      }
      else
      {
        for (auto i{0}; i < n; ++i)
        {
          tmp |= ans[i][j];
        }
      }
      if (tmp != vs[j])
      {
#if DEBUG == 1
        cerr << "failed: k = " << k << ", j = " << j << endl;
#endif
        No();
      }
    }
  }
  for (auto i{0}; i < n; ++i)
  {
    for (auto j{0}; j < n; ++j)
    {
      cout << ans[i][j];
      if (j < n - 1)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }
}
