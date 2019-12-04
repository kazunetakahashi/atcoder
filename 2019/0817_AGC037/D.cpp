#define DEBUG 1
/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 12/4/2019, 9:34:03 AM
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
  vector<int> match;
  vector<bool> used;
  vector<edge *> collection;

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
    fill(match.begin(), match.end(), -1);
    collection.clear();
    for (auto v = 0; v < N; v++)
    {
      if (match[v] < 0)
      {
        fill(used.begin(), used.end(), false);
        if (dfs(v))
        {
          ++res;
        }
      }
    }
#if DEBUG == 1
    for (auto e : collection)
    {
      cerr << "(" << e->from << ", " << e->to << "): id = " << e->id << endl;
    }
#endif
    for (auto e : collection)
    {
      e->used = true;
      auto &f{G[e->to][e->rev]};
      if (!f.used)
      {
        collection.push_back(&f);
      }
    }
    return res;
  }

  vector<edge *> const &collect() const
  {
    return collection;
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
      auto w{match[u]};
      if (w < 0 || (!used[w] && dfs(w)))
      {
        match[v] = u;
        match[u] = v;
        collection.push_back(&e);
        return true;
      }
    }
    return false;
  }
};

// ----- main() -----

void flush(vector<vector<int>> const &V)
{
  assert(!V.empty());
  for (auto j = size_t{0}; j < V[0].size(); j++)
  {
    for (auto i = size_t{0}; i < V.size(); i++)
    {
      cout << V[i][j] + 1;
      if (i < V.size() - 1)
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

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < M; j++)
    {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  Bipartite graph(2 * N);
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < M; j++)
    {
      graph.add_edge(i, A[i][j] / M + N, A[i][j]);
    }
  }
  vector<vector<int>> B(M, vector<int>(N));
  for (auto i = 0; i < M; i++)
  {
    assert(graph.bipartite_matching() == N);
    assert(static_cast<int>(graph.collect().size()) == 2 * N);
    for (auto ptr : graph.collect())
    {
      if (ptr->from < N)
      {
        B[i][ptr->from] = ptr->id;
      }
    }
  }
  auto C = B;
  for (auto i = 0; i < M; i++)
  {
    sort(C[i].begin(), C[i].end());
  }
  flush(B);
  flush(C);
}
