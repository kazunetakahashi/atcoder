#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 12/3/2019, 9:06:22 AM
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

// ----- Dinic -----

class Dinic
{
  struct edge
  {
    int to;
    ll cap;
    int rev;
  };
  constexpr static ll INFTY = 10000000000000010LL;

  int N;
  vector<vector<edge>> G;
  vector<ll> level;
  vector<size_t> iter;

public:
  Dinic() {}
  Dinic(int N) : N{N}, G(N), level(N), iter(N) {}

  void add_edge(int from, int to, ll cap = 1LL)
  {
    G[from].push_back({to, cap, static_cast<int>(G[to].size())});
    G[to].push_back({from, 0, static_cast<int>(G[from].size() - 1)});
  }

  ll max_flow(int s, int t)
  {
    ll flow{0LL};
    while (true)
    {
      bfs(s);
      if (level[t] < 0)
      {
        return flow;
      }
      fill(iter.begin(), iter.end(), 0u);
      ll f;
      while ((f = dfs(s, t, INFTY)) > 0LL)
      {
        flow += f;
      }
    }
  }

private:
  void bfs(int s)
  {
    fill(level.begin(), level.end(), -1);
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
      int v{Q.front()};
      Q.pop();
      for (auto &e : G[v])
      {
        if (e.cap > 0LL && level[e.to] < 0)
        {
          level[e.to] = level[v] + 1;
          Q.push(e.to);
        }
      }
    }
  }

  ll dfs(int v, int t, ll f)
  {
    if (v == t)
    {
      return f;
    }
    for (auto &i = iter[v]; i < G[v].size(); i++)
    {
      edge &e{G[v][i]};
      if (e.cap > 0LL && level[v] < level[e.to])
      {
        ll d{dfs(e.to, t, min(f, e.cap))};
        if (d > 0LL)
        {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0LL;
  }
};

// ----- main() -----

class Permutation
{
  int N;
  vector<int> P;
  vector<int> V;

public:
  Permutation(int N, vector<int> const &P) : N{N}, P{P}, V(N, -1)
  {
    make_V();
  }

  bool isolated(int v)
  {
    return P[v] == v;
  }

  int composed(int v)
  {
    return V[v];
  }

  int per(int v)
  {
    return P[v];
  }

private:
  void make_V()
  {
    int k{0};
    for (auto i = 0; i < N; i++)
    {
      if (V[i] != -1)
      {
        continue;
      }
      int now{i};
      while (V[now] == -1)
      {
        V[now] = k;
        now = P[now];
      }
      ++k;
    }
  }
};

int main()
{
  int N;
  cin >> N;
  vector<int> P(N), Q(N);
  for (auto i = 0; i < N; i++)
  {
    cin >> P[i];
  }
  for (auto i = 0; i < N; i++)
  {
    cin >> Q[i];
  }
  Permutation A(N, P);
  Permutation B(N, Q);
  constexpr int C{2};
  constexpr int src{0};
  constexpr int dst{1};
  Dinic dinic(C + 2 * N);
  ll ans{0LL};
  for (auto i = 0; i < N; i++)
  {
    if (A.isolated(i) && B.isolated(i))
    {
      ++ans;
    }
    else if (A.isolated(i))
    {
      dinic.add_edge(B.composed(i) + N + C, dst);
    }
    else if (B.isolated(i))
    {
      dinic.add_edge(src, A.composed(i) + C);
    }
    else
    {
      dinic.add_edge(A.composed(i) + C, B.composed(i) + N + C);
      if (A.per(i) == B.per(i))
      {
        dinic.add_edge(B.composed(i) + N + C, A.composed(i) + C);
      }
    }
  }
  cout << N - dinic.max_flow(src, dst) << endl;
}
