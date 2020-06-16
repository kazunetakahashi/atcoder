#define DEBUG 0
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/17/2020, 1:01:35 AM
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
  cout << "-1" << endl;
  exit(0);
}

// ----- Solve -----

using Bomb = tuple<int, int>;

struct Edge
{
  int src, dst, id, on;
  // ll cost;
  Edge() {}
  Edge(int src, int dst, int id, int on = false) : src{src}, dst{dst}, id{id}, on{on} {}
  // Edge(int src, int dst, ll cost) : src{src}, dst{dst}, cost{cost} {}

  void added_edge(vector<vector<Edge>> &V)
  {
    V[src].push_back(*this);
  }

  void added_rev(vector<vector<Edge>> &V)
  {
    V[dst].push_back(rev());
  }

  Edge rev()
  {
    Edge edge{*this};
    swap(edge.src, edge.dst);
    return edge;
  }
};

class Solve
{
  int N, M;
  vector<Bomb> bombs;
  vector<bool> B;
  vector<vector<Edge>> V;
  vector<bool> table;
  vector<bool> visited;

public:
  Solve(int N, int M) : N{N}, M{M}, bombs(N), B(N + 1), V(N + 1), table(M, false), visited(N + 1, false)
  {
    // bombs
    for (auto i{0}; i < N; ++i)
    {
      int a, b;
      cin >> a >> b;
      bombs[i] = Bomb{a, b};
    }
    sort(bombs.begin(), bombs.end());
#if DEBUG == 1
    for (auto i{0}; i < N; ++i)
    {
      cerr << "bombs[" << i << "] = (" << get<0>(bombs[i]) << ", " << get<1>(bombs[i]) << ")" << endl;
    }
#endif
    // B
    B[0] = get<1>(bombs[0]);
    for (auto i{1}; i < N; ++i)
    {
      B[i] = get<1>(bombs[i]) ^ get<1>(bombs[i - 1]);
    }
    B[N] = get<1>(bombs[N - 1]);
    // V
    for (auto i{0}; i < M; ++i)
    {
      int l, r;
      cin >> l >> r;
      // The following two lines are referring to https://atcoder.jp/contests/abc155/submissions/10163379
      auto v{static_cast<int>(distance(bombs.begin(), lower_bound(bombs.begin(), bombs.end(), Bomb{l, -1})))};
      auto w{static_cast<int>(distance(bombs.begin(), lower_bound(bombs.begin(), bombs.end(), Bomb{r, 2})))};
#if DEBUG == 1
      cerr << "l = " << l << ", r = " << r << ", v = " << v << ", w = " << w << endl;
#endif
      if (v == w)
      {
        continue;
      }
      Edge edge{v, w, i};
      edge.added_edge(V);
      edge.added_rev(V);
    }
  }

  void flush()
  {
    make_table();
    int cnt{0};
    for (auto i{0}; i < M; ++i)
    {
      if (table[i])
      {
        ++cnt;
      }
    }
    cout << cnt << endl;
    for (auto i{0}; i < M; ++i)
    {
      if (table[i])
      {
        cout << i + 1;
        --cnt;
        if (cnt > 0)
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

private:
  void make_table()
  {
    for (auto i{0}; i < N + 1; ++i)
    {
      if (!visited[i])
      {
        if (dfs(i) == 1)
        {
          No();
        }
      }
    }
    for (auto i{0}; i < N + 1; ++i)
    {
      for (auto const &e : V[i])
      {
        if (e.on)
        {
          table[e.id] = true;
        }
      }
    }
  }

  int dfs(int src)
  {
    visited[src] = true;
    auto sum{B[src] ? 1 : 0};
    for (auto &e : V[src])
    {
      if (visited[e.dst])
      {
        continue;
      }
      auto tmp{dfs(e.dst)};
      sum += tmp;
      e.on = (tmp == 1);
    }
    return sum & 1;
  }
};

// ----- main() -----

int main()
{
  int N, M;
  cin >> N >> M;
  Solve solve(N, M);
  solve.flush();
}
