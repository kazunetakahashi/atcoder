#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/7/1 1:44:13
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

// ----- Solve -----

struct Edge
{
  int src, dst, id, rev;
  ll cost, time;
  Edge() {}
  Edge(int src, int dst, int id, int rev, ll cost, ll time) : src{src}, dst{dst}, id{id}, rev{rev}, cost{cost}, time{time} {}

  void added_edge(vector<vector<Edge>> &V)
  {
    V[src].push_back(*this);
  }

  void added_rev(vector<vector<Edge>> &V)
  {
    V[dst].push_back(rev_edge());
  }

  Edge rev_edge()
  {
    Edge edge{*this};
    swap(edge.src, edge.dst);
    swap(edge.id, edge.rev);
    return edge;
  }
};

enum class GraphType
{
  Undirected,
  Directed,
  RevEdge,
};

tuple<vector<vector<Edge>>, vector<Edge>> ReadGraphWithEdges(int N, int M, GraphType type = GraphType::Undirected, bool is_one_indexed = true)
{
  vector<vector<Edge>> V(N);
  vector<Edge> E;
  for (auto i = 0; i < M; ++i)
  {
    int v, w;
    cin >> v >> w;
    if (is_one_indexed)
    {
      --v;
      --w;
    }
    ll cost, time;
    cin >> cost >> time;
    switch (type)
    {
    case GraphType::Undirected:
    {
      Edge edge{v, w, static_cast<int>(E.size()), static_cast<int>(E.size()), cost, time};
      edge.added_edge(V);
      edge.added_rev(V);
      E.push_back(edge);
      break;
    }
    default:
      break;
    }
  }
  return make_tuple(V, E);
}

vector<vector<Edge>> ReadGraph(int N, int M, GraphType type = GraphType::Undirected, bool is_one_indexed = true)
{
  return get<0>(ReadGraphWithEdges(N, M, type, is_one_indexed));
}

tuple<vector<vector<Edge>>, vector<Edge>> ReadTreeWithEdges(int N, GraphType type = GraphType::Undirected, bool is_one_indexed = true)
{
  return ReadGraphWithEdges(N, N - 1, type, is_one_indexed);
}

vector<vector<Edge>> ReadTree(int N, GraphType type = GraphType::Undirected, bool is_one_indexed = true)
{
  return ReadGraph(N, N - 1, type, is_one_indexed);
}

using Info = tuple<ll, ll, ll>; // time, vertex, coins

constexpr ll C{51};

class Solve
{
  ll n, m, s;
  vector<vector<Edge>> edges;
  vector<ll> coins, times;
  vector<vector<ll>> res;

public:
  Solve(ll n, ll m, ll s) : n{n}, m{m}, s{s}, edges(ReadGraph(n, m)), coins(n), times(n), res(n, vector<ll>(n * C, Infty<ll>()))
  {
    for (auto i{0}; i < n; ++i)
    {
      cin >> coins[i] >> times[i];
    }
  }

  void flush()
  {
    min_heap<Info> h;
    ch_min(s, n * C - 1);
    h.push(Info{0, 0, s});
    while (!h.empty())
    {
      auto [src_time, src, src_coin]{h.top()};
      h.pop();
      if (res[src][src_coin] == Infty<ll>())
      {
        res[src][src_coin] = src_time;
        for (auto const &e : edges[src])
        {
          auto dst_time{src_time + e.time};
          auto dst_coin{src_coin - e.cost};
          if (dst_coin < 0)
          {
            continue;
          }
          if (dst_coin >= n * C)
          {
            dst_coin = n * C - 1;
          }
          if (res[e.dst][dst_coin] == Infty<ll>())
          {
            h.push(Info(dst_time, e.dst, dst_coin));
          }
        }
        {
          auto dst_time{src_time + times[src]};
          auto dst_coin{src_coin + coins[src]};
          if (dst_coin >= n * C)
          {
            dst_coin = n * C - 1;
          }
          if (res[src][dst_coin] == Infty<ll>())
          {
            h.push(Info(dst_time, src, dst_coin));
          }
        }
      }
    }
    for (auto i{1}; i < n; ++i)
    {
      auto ans{Infty<ll>()};
      for (auto j{0}; j < n * C; ++j)
      {
        ch_min(ans, res[i][j]);
      }
      cout << ans << endl;
    }
  }

private:
};

// ----- main() -----

int main()
{
  ll n, m, s;
  cin >> n >> m >> s;
  Solve solve(n, m, s);
  solve.flush();
}
