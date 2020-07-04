#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 7/5/2020, 2:42:27 AM
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

// ----- SuffixArray -----

template <typename Type = string>
class SuffixArray
{
public:
  // Sparse Table from drken-san
  // http://drken1215.hatenablog.com/entry/2019/09/16/014600
  template <typename T = int>
  class SparseTable
  {
    vector<vector<T>> dat;
    vector<int> height;

  public:
    SparseTable() {}
    SparseTable(vector<T> const &V)
    {
      int N{static_cast<int>(V.size())}, h{1};
      while ((1 << h) < N)
      {
        ++h;
      }
      dat.assign(h, vector<T>(1 << h));
      height.assign(N + 1, 0);
      for (int i = 2; i <= N; i++)
      {
        height[i] = height[i >> 1] + 1;
      }
      for (int i = 0; i < N; ++i)
      {
        dat[0][i] = V[i];
      }
      for (int i = 1; i < h; ++i)
      {
        for (int j = 0; j < N; ++j)
        {
          dat[i][j] = min(dat[i - 1][j], dat[i - 1][min(j + (1 << (i - 1)), N - 1)]);
        }
      }
    }

    T get(int a, int b) const
    {
      return min(dat[height[b - a]][a], dat[height[b - a]][b - (1 << height[b - a])]);
    }
  };

private:
  int N, K;
  Type S;
  vector<int> rank, sa, lcp;
  SparseTable<int> st;

public:
  SuffixArray() {}
  SuffixArray(Type const &S) : N{static_cast<int>(S.size())}, K{1}, S{S}, rank(N + 1), sa(N + 1), lcp(N)
  {
    // initialize for 1 char
    for (auto i = 0; i <= N; i++)
    {
      sa[i] = i;
    }
    for (auto i = 0; i < N; i++)
    {
      rank[i] = static_cast<int>(S[i]);
    }
    rank[N] = -1;
    // lambda for comparing
    auto compare_sa = [&](auto i, auto j) {
      if (rank[i] != rank[j])
      {
        return rank[i] < rank[j];
      }
      else
      {
        int ri{i + K <= N ? rank[i + K] : -1};
        int rj{j + K <= N ? rank[j + K] : -1};
        return ri < rj;
      }
    };
    // construct sa with rank
    vector<int> tmp(N + 1);
    for (; K <= N; K *= 2)
    {
      sort(sa.begin(), sa.end(), compare_sa);
      tmp[sa[0]] = 0;
      for (auto i = 1; i <= N; i++)
      {
        tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
      }
      swap(rank, tmp);
    }
    // construct lcp with sa and rank
    for (auto i = 0; i <= N; i++)
    {
      rank[sa[i]] = i;
    }
    int h{0};
    lcp[0] = 0;
    for (auto i = 0; i < N; i++)
    {
      int j{sa[rank[i] - 1]};
      if (h > 0)
      {
        --h;
      }
      for (; j + h < N && i + h < N; ++h)
      {
        if (S[j + h] != S[i + h])
        {
          break;
        }
      }
      lcp[rank[i] - 1] = h;
    }
    st = SparseTable<int>(lcp);
  }

  int operator[](int i) const
  {
    return sa[i];
  }

  vector<int> const &LCP() const
  {
    return lcp;
  }

  int LCP(int a, int b) const
  {
    return st.get(min(rank[a], rank[b]), max(rank[a], rank[b]));
  }

  bool contain(Type const &T) const
  {
    int b{lower_bound(T)};
    return b <= N && S.compare(sa[b], T.size(), T) == 0;
  }

  int count(Type const &T) const
  {
    int lb{lower_bound(T)};
    int ub{upper_bound(T)};
    if (lb > ub)
    {
      return 0;
    }
    return ub - lb + 1;
  }

private:
  template <typename T>
  void binary_search(int &a, int &b, T cmp) const
  {
    while (abs(a - b) > 1)
    {
      int c{(a + b) / 2};
      if (cmp(c))
      {
        a = c;
      }
      else
      {
        b = c;
      }
    }
  }

  int lower_bound(Type const &T) const
  {
    int a{-1}, b{N + 1};
    auto cmp = [&](auto c) {
      return S.compare(sa[c], T.size(), T) < 0;
    };
    binary_search(a, b, cmp);
    return b;
  }

  int upper_bound(Type const &T) const
  {
    int a{-1}, b{N + 1};
    auto cmp = [&](auto c) {
      return S.compare(sa[c], T.size(), T) <= 0;
    };
    binary_search(a, b, cmp);
    return a;
  }
};

// ----- Solve -----

class Solve
{
  string w;
  int n;
  int ans;
  SuffixArray<string> sa;
  vector<vector<int>> divisors;

public:
  Solve() : ans{0}
  {
    cin >> w;
    n = w.size();
    sa = SuffixArray<string>{w};
    divisors = vector<vector<int>>(n + 1);
    for (auto i{1}; i <= n; ++i)
    {
      for (auto j{2}; i * j <= n; ++j)
      {
        divisors[i * j].push_back(i);
      }
    }
  }

  void flush()
  {
    if (all_of(w.begin(), w.end(), [&](auto c) { return c == w[0]; }))
    {
      cout << n << endl;
      cout << 1 << endl;
    }
    else if (is_good(0, n))
    {
      cout << 1 << endl;
      cout << 1 << endl;
    }
    else
    {
      for (auto i{1}; i < n; ++i)
      {
        if (is_good(0, i) && is_good(i, n - i))
        {
          ++ans;
        }
      }
      cout << 2 << endl;
      cout << ans << endl;
    }
  }

private:
  bool is_good(int a, int s)
  {
    return none_of(divisors[s].begin(), divisors[s].end(), [&](auto d) { return has_period(a, s, d); });
  }

  bool has_period(int a, int s, int d)
  {
    return sa.LCP(a, a + d) >= s - d;
  }
};

// ----- main() -----

int main()
{
  Solve solve;
  solve.flush();
}
