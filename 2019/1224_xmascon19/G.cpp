#define DEBUG 1
/**
 * File    : G.cpp
 * Author  : Kazune Takahashi
 * Created : 12/25/2019, 6:29:12 PM
 * Powered by Visual Studio Code
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
// ----- boost -----
#include <boost/rational.hpp>
// ----- using directives and manipulations -----
using boost::rational;
using namespace std;
using ll = long long;
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
  Mint(ll x) : x{x % MOD} {}
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
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// ----- frequently used constexpr -----
// constexpr double epsilon{1e-10};
// constexpr ll infty{1000000000000000LL};
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

// ----- Bipartite -----

// for C++14
// Bipartite<> graph(N);

template <typename T = int>
class Bipartite
{
public:
  struct edge
  {
    bool used;
    size_t rev;
    int from, to;
    T id;

    edge(int from, int to, size_t rev, T id = T{}, bool used = false) : used{used}, rev{rev}, from{from}, to{to}, id{id} {}
  };

private:
  int N;
  vector<vector<edge>> G;
  vector<edge *> match;
  vector<bool> used;

public:
  Bipartite(int N) : N{N}, G(N), match(N), used(N) {}

  void add_edge(int u, int v, T id = T{})
  {
    G[u].push_back({u, v, G[v].size(), id, false});
    G[v].push_back({v, u, G[u].size() - 1, id, false});
  }

  int bipartite_matching()
  {
    int res{0};
    fill(match.begin(), match.end(), nullptr);
    for (auto v = 0; v < N; v++)
    {
      if (!match[v])
      {
        fill(used.begin(), used.end(), false);
        if (dfs(v))
        {
          ++res;
        }
      }
    }
#if DEBUG == 1
    cerr << "res = " << res << endl;
#endif
    for (auto &e : match)
    {
      e->used = true;
    }
    return res;
  }

  vector<edge *> const &matching() const
  {
    return match;
  }

private:
  bool dfs(int v)
  {
    used[v] = true;
    for (auto &e : G[v])
    {
      if (e.used)
      {
        continue;
      }
      auto u{e.to};
      // for C++14
      auto w{match[u]};
      if (!w || (!used[w->to] && dfs(w->to)))
      {
        match[v] = &e;
        match[u] = &G[u][e.rev];
        return true;
      }
    }
    return false;
  }
};

// ----- main() -----

class Solve
{
  constexpr static int P{5};
  constexpr static int Q{2};
  constexpr static int C{P * P + Q * Q};

  int H, W;
  vector<string> S;
  Bipartite<> graph;
  vector<vector<bool>> G;

public:
  Solve(int H, int W, vector<string> const &S) : H{H}, W{W}, S(S), graph(2 * C), G(C, vector<bool>(C, true))
  {
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        if (S[i][j] == '.')
        {
          G[i % C][j % C] = false;
        }
      }
    }
    for (auto x = 0; x < C; x++)
    {
      for (auto y = 0; y < C; y++)
      {
        if (!G[x][y])
        {
          graph.add_edge(calc_k_A(x, y), calc_k_B(x, y));
        }
      }
    }
  }
  int calc() { return graph.bipartite_matching(); };

private:
  // helper function
  static int calc_k_A(int x, int y)
  {
    for (auto b = 0; b < Q; b++)
    {
      int tmp{Q * x + P * y + C * b};
      if (tmp % Q == 0)
      {
        return (tmp / Q) % C;
      }
    }
    assert(false);
    return -1;
  }
  static int calc_k_B(int x, int y)
  {
    for (auto b = 0; b < P; b++)
    {
      int tmp{P * x + Q * y + C * b};
      if (tmp % P == 0)
      {
        return (tmp / P) % C + C;
      }
    }
    assert(false);
    return -1;
  }
};

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  Solve solve(H, W, S);
  cout << solve.calc() << endl;
}
