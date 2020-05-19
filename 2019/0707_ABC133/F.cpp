#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 5/19/2020, 3:57:45 PM
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

// ----- LCA -----

template <typename T = ll>
class LCA
{
  int N, root, L;
  vector<vector<int>> to;
  vector<vector<T>> co;
  vector<int> dep;
  vector<T> costs;
  vector<vector<int>> par;

public:
  LCA(int n) : N{n}, L{0}, to(n), co(n), dep(n), costs(n)
  {
    while ((1 << L) < N)
    {
      ++L;
    }
    par = vector<vector<int>>(N + 1, vector<int>(L, N));
  }

  void add_edge(int a, int b, T c = 0)
  {
    to[a].push_back(b);
    co[a].push_back(c);
    to[b].push_back(a);
    co[b].push_back(c);
  }

  void init(int _root)
  {
    root = _root;
    dfs(root);
    for (auto i = 0; i < L - 1; i++)
    {
      for (auto v = 0; v < N; v++)
      {
        if (par[v][i] != -1)
        {
          par[v][i + 1] = par[par[v][i]][i];
        }
      }
    }
  }

  // LCA
  int operator()(int a, int b)
  {
    if (dep[a] > dep[b])
    {
      swap(a, b);
    }
    int gap = dep[b] - dep[a];
    for (auto i = L - 1; i >= 0; i--)
    {
      int len = 1 << i;
      if (gap >= len)
      {
        gap -= len;
        b = par[b][i];
      }
    }
    if (a == b)
    {
      return a;
    }
    for (auto i = L - 1; i >= 0; i--)
    {
      int na = par[a][i];
      int nb = par[b][i];
      if (na != nb)
      {
        a = na;
        b = nb;
      }
    }
    return par[a][0];
  }

  int depth(int a, int b)
  {
    int c = (*this)(a, b);
    return dep[a] + dep[b] - 2 * dep[c];
  }

  T cost(int a, int b)
  {
    int c = (*this)(a, b);
    return costs[a] + costs[b] - 2 * costs[c];
  }

private:
  void dfs(int v, int d = 0, T c = 0, int p = -1)
  {
    if (p != -1)
    {
      par[v][0] = p;
    }
    dep[v] = d;
    costs[v] = c;
    for (auto i = 0u; i < to[v].size(); i++)
    {
      int u = to[v][i];
      if (u == p)
      {
        continue;
      }
      dfs(u, d + 1, c + co[v][i], v);
    }
  }
};

// ----- main() -----

struct Query
{
  int id, color, y, coefficient;
};

struct Edge
{
  int src, dst, color, cost;
};

class Solve
{
  int N, Q;
  vector<vector<Edge>> V;
  vector<vector<Query>> W;
  LCA<int> lca;
  vector<int> ans;
  vector<int> sum, cnt;

public:
  Solve(int N, int Q) : N{N}, Q{Q}, V(N), W(Q), lca{N}, ans(Q), sum(N, 0), cnt(N, 0)
  {
    for (auto i = 0; i < N - 1; ++i)
    {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      --a;
      --b;
      V[a].push_back({a, b, c, d});
      V[b].push_back({b, a, c, d});
      lca.add_edge(a, b, d);
    }
    lca.init(0);
    for (auto i = 0; i < Q; ++i)
    {
      int x, y, u, v;
      cin >> x >> y >> u >> v;
      --x;
      --y;
      --u;
      --v;
      W[u].push_back({i, x, y, 1});
      W[v].push_back({i, x, y, 1});
      W[lca(u, v)].push_back({i, x, y, -2});
      ans[i] = lca.cost(u, v);
    }
  }

  void flush()
  {
#if DEBUG == 1
    cerr << "aaa" << endl;
#endif
    dfs();
    for (auto i = 0; i < Q; ++i)
    {
      cout << ans[i] << endl;
    }
  }

private:
  void dfs(int u = 0, int p = -1)
  {
#if DEBUG == 1
    cerr << "u = " << u << endl;
#endif
    for (auto const &q : W[u])
    {
      ans[q.id] += q.coefficient * (-sum[q.color] + cnt[q.color] * q.y);
    }
    for (auto const &e : V[u])
    {
      if (e.dst == p)
      {
        continue;
      }
      sum[e.color] += e.cost;
      cnt[e.color]++;
      dfs(e.dst, u);
      sum[e.color] -= e.cost;
      cnt[e.color]--;
    }
  }
};

int main()
{
  int N, Q;
  cin >> N >> Q;
  Solve solve(N, Q);
  solve.flush();
}
