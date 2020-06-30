#define DEBUG 1
/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/7/1 4:52:30
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
  cout << "No" << endl;
  exit(0);
}

// ----- Solve -----

template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> const &v)
{
  int n = v.size();
  for (auto i{0}; i < n; ++i)
  {
    for (auto j{0}; j < n; ++j)
    {
      os << v[i][j];
      if (j < n - 1)
      {
        os << " ";
      }
      else
      {
        os << endl;
      }
    }
  }
  return os;
}

template <typename T>
void Transpose(vector<vector<T>> &mat)
{
  int n = mat.size();
  for (auto i{0}; i < n; ++i)
  {
    for (auto j{i + 1}; j < n; ++j)
    {
      swap(mat[i][j], mat[j][i]);
    }
  }
}

enum class State
{
  AllZero,
  AllOne,
  AnyZero,
  AnyOne
};

class Solve
{
  int n;
  vector<State> xAxis, yAxis;
  vector<vector<bool>> res;

public:
  Solve(int n, vector<State> xAxis, vector<State> yAxis) : n{n}, xAxis{xAxis}, yAxis{yAxis}, res(n, vector<bool>(n, 0)) {}

  vector<vector<bool>> Answer()
  {
    FillAll();
    ChangeAxis();
    FillAll();
    ChangeAxis();
    FillSame();
    FixUp();
    ChangeAxis();
    FixUp();
    ChangeAxis();
    Check();
    ChangeAxis();
    Check();
    ChangeAxis();
    return res;
  }

private:
  void ChangeAxis()
  {
    Transpose(res);
    swap(xAxis, yAxis);
  }

  void Check()
  {
    for (auto i{0}; i < n; ++i)
    {
      switch (xAxis[i])
      {
      case State::AllOne:
        for (auto j{0}; j < n; ++j)
        {
          if (res[i][j] == 0)
          {
            No();
          }
        }
        break;
      case State::AllZero:
        for (auto j{0}; j < n; ++j)
        {
          if (res[i][j] == 1)
          {
            No();
          }
        }
        break;
      case State::AnyOne:
        for (auto j{0}; j < n; ++j)
        {
          if (res[i][j] == 1)
          {
            break;
          }
        }
        No();
        break;
      case State::AnyZero:
        for (auto j{0}; j < n; ++j)
        {
          if (res[i][j] == 0)
          {
            break;
          }
        }
        No();
        break;
      default:
        assert(false);
        break;
      }
    }
  }

  void FixUp()
  {
    for (auto i{0}; i < n; ++i)
    {
      if (xAxis[i] != State::AnyOne)
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
        if (yAxis[j] != State::AnyZero)
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

  void FillAll()
  {
    for (auto i{0}; i < n; ++i)
    {
      if (xAxis[i] == State::AllOne)
      {
        for (auto j{0}; j < n; ++j)
        {
          res[i][j] = 1;
        }
      }
    }
  }

  void FillSame()
  {
    for (auto i{0}; i < n; ++i)
    {
      for (auto j{0}; j < n; ++j)
      {
        if (xAxis[i] == State::AnyOne && yAxis[i] == State::AnyOne)
        {
          res[i][j] = 1;
        }
      }
    }
  }
};

// ----- main() -----

vector<State> make_axis(vector<bool> const &s, vector<bool> const &u)
{
  assert(s.size() == u.size());
  vector<State> ans(s.size());
  for (auto i{size_t{0}}; i < s.size(); ++i)
  {
    if (!s[i] && !u[i])
    {
      ans[i] = State::AnyZero;
    }
    else if (!s[i] && u[i])
    {
      ans[i] = State::AllOne;
    }
    else if (s[i] && !u[i])
    {
      ans[i] = State::AllZero;
    }
    else
    {
      ans[i] = State::AnyOne;
    }
  }
  return ans;
}

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
    vector<State> xAxis{make_axis(s, u)}, yAxis{make_axis(t, v)};
    Solve solve(n, xAxis, yAxis);
    auto res{solve.Answer()};
    for (auto i{0}; i < n; ++i)
    {
      for (auto j{0}; j < n; ++j)
      {
        ans[i][j] |= static_cast<ll>(res[i][j]) << k;
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
