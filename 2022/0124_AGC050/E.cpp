#define DEBUG 0
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 1/24/2022, 12:46:28 PM
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
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/rational.hpp>
#include <atcoder/all>
using namespace std;
// using namespace atcoder;
using boost::rational;
using boost::integer::gcd; // for C++14 or for cpp_int
using boost::integer::lcm; // for C++14 or for cpp_int
using boost::multiprecision::cpp_int;
using ll = long long;
using ld = long double;
/***************************************************
    Fundermental Tools
 ***************************************************/
// ----- max_heap and min_heap -----
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
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
// ----- lcm and gcd for vector<T> -----
template <typename Container, typename T = typename Container::value_type>
T lcm(Container const &v)
{
  T res{*v.begin()};
  for (auto const &e : v)
  {
    res = lcm(res, e);
  }
  return res;
}
template <typename Container, typename T = typename Container::value_type>
T gcd(Container const &v)
{
  T res{*v.begin()};
  for (auto const &e : v)
  {
    res = gcd(res, e);
  }
  return res;
}
// ----- map_value -----
template <typename T, typename U>
U map_value(map<T, U> const &m, T const &v)
{
  if (m.find(v) == m.end())
  {
    return U{};
  }
  else
  {
    return m.at(v);
  }
}
// ----- mint -----
// using mint = atcoder::modint1000000007;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint; // atcoder::modint::set_mod(xxx);
// using mint = atcoder::static_modint<1000000009>;
// using mint0 = dynamic_modint<xxx>;
// using mint1 = dynamic_modint<yyy>;
istream &operator>>(istream &is, mint &x)
{
  ll t;
  is >> t;
  x = t;
  return is;
}
ostream &operator<<(ostream &os, mint const &x)
{
  return os << x.val();
}
// ----- Combination -----
template <typename Mint = mint>
class Combination
{
public:
  constexpr static ll MAX_SIZE{3'000'010LL};
  // constexpr static ll MAX_SIZE{30'000'010LL}; // if 10^7 is needed

  vector<mint> inv, fact, factinv;

  Combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i{2LL}; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[Mint::mod() % i]) * (Mint::mod() / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i{1LL}; i < MAX_SIZE; i++)
    {
      fact[i] = Mint(i) * fact[i - 1];
      factinv[i] = inv[i] * factinv[i - 1];
    }
  }

  Mint operator()(int n, int k)
  {
    if (n >= 0 && k >= 0 && n - k >= 0)
    {
      return fact[n] * factinv[k] * factinv[n - k];
    }
    return 0;
  }

  Mint catalan(int x, int y)
  {
    return (*this)(x + y, y) - (*this)(x + y, y - 1);
  }
};
// ----- for C++14 -----
using combination = Combination<mint>;
// ----- for C++17 -----
template <typename T, typename enable_if<is_integral<T>::value>::type * = nullptr>
size_t popcount(T x) { return bitset<64>(x).count(); }
size_t popcount(string const &S) { return bitset<200010>{S}.count(); }
// ----- Infty -----
template <typename T>
constexpr T Infty() { return numeric_limits<T>::max(); }
template <typename T>
constexpr T mInfty() { return numeric_limits<T>::min(); }
/***************************************************
    AtCoder Library / Data Structures
 ***************************************************/
// ----- FenwickTree -----
template <typename T = ll>
class FenwickTree : public atcoder::fenwick_tree<T>
{
public:
  using atcoder::fenwick_tree<T>::fenwick_tree;

  FenwickTree(vector<T> const &v) : FenwickTree(static_cast<int>(v.size()))
  {
    for (auto i{size_t{0}}; i < v.size(); ++i)
    {
      atcoder::fenwick_tree<T>::add(i, v[i]);
    }
  }

  T operator[](int i)
  {
    return atcoder::fenwick_tree<T>::sum(i, i + 1);
  }
};
/***************************************************
    AtCoder Library / Math
 ***************************************************/
// ----- Math -----
using atcoder::convolution;
using atcoder::convolution_ll;
using atcoder::floor_sum;
/***************************************************
    AtCoder Library / Graphs
 ***************************************************/
// ----- UnionFind -----
using UnionFind = atcoder::dsu;
// ----- MaxFlow -----
template <typename Cap = ll>
class MaxFlow : public atcoder::mf_graph<Cap>
{
public:
  using atcoder::mf_graph<Cap>::mf_graph;

  int add_edge(int from, int to)
  {
    return atcoder::mf_graph<Cap>::add_edge(from, to, Cap{1});
  }
};
ostream &operator<<(ostream &os, typename atcoder::mf_graph<ll>::edge const &edge)
{
  return os << "from: " << edge.from << ", to: " << edge.to << ", cap: " << edge.cap << ", flow: " << edge.flow;
}
// ----- MinCostFlow -----
template <typename Cap = ll, typename Cost = ll>
class MinCostFlow : public atcoder::mcf_graph<Cap, Cost>
{
private:
  Cost infty;

public:
  using atcoder::mcf_graph<Cap, Cost>::mcf_graph;

  MinCostFlow(int n, Cost infty = Cost{0}) : atcoder::mcf_graph<Cap, Cost>::mcf_graph(n), infty{infty} {}

  int add_edge(int from, int to, Cap cap)
  {
    return atcoder::mcf_graph<Cap, Cost>::add_edge(from, to, cap, Cost{0});
  }

  int add_edge(int from, int to, Cap cap, Cost cost)
  {
    return atcoder::mcf_graph<Cap, Cost>::add_edge(from, to, cap, cost + infty);
  }

  pair<Cap, Cost> flow(int s, int t)
  {
    return flow(s, t, std::numeric_limits<Cap>::max());
  }

  pair<Cap, Cost> flow(int s, int t, Cap flow_limit)
  {
    return slope(s, t, flow_limit).back();
  }

  vector<pair<Cap, Cost>> slope(int s, int t)
  {
    return slope(s, t, numeric_limits<Cap>::max());
  }

  vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit)
  {
    auto res{atcoder::mcf_graph<Cap, Cost>::slope(s, t, flow_limit)};
    for (auto &[cap, cost] : res)
    {
      cost -= cap * infty;
    }
    return res;
  }

  typename atcoder::mcf_graph<Cap, Cost>::edge get_edge(int i)
  {
    auto res{atcoder::mcf_graph<Cap, Cost>::get_edge(i)};
    res.cost -= infty;
    return res;
  }

  vector<typename atcoder::mcf_graph<Cap, Cost>::edge> edges()
  {
    auto res{atcoder::mcf_graph<Cap, Cost>::edges()};
    for (auto &e : res)
    {
      e.cost -= infty;
    }
    return res;
  }
};
ostream &operator<<(ostream &os, typename atcoder::mcf_graph<ll, ll>::edge const &edge)
{
  return os << "from: " << edge.from << ", to: " << edge.to << ", cap: " << edge.cap << ", flow: " << edge.flow << ", cost: " << edge.cost;
}
// ----- StronglyConnectedComponents -----
using StronglyConnectedComponents = atcoder::scc_graph;
// ----- TwoSat -----
using TwoSat = atcoder::two_sat;
/***************************************************
    My Library / DP-Typical
 ***************************************************/
// ----- LongestIncreasingSubsequence -----
template <typename T>
class LongestIncreasingSubsequence
{
  struct Cache_LIS
  {
    typename vector<T>::iterator it;
    T value;
  };

  int n; // fixed
  T infty;
  vector<T> dp;
  stack<Cache_LIS> st;

public:
  LongestIncreasingSubsequence() {}
  LongestIncreasingSubsequence(int n, T infty = numeric_limits<T>::max()) : n{n}, infty{infty}, dp(n, infty) {}

  int query(T a)
  {
    auto it{lower_bound(dp.begin(), dp.end(), a)};
    auto value{*it};
    st.push(Cache_LIS{it, value});
    *it = a;
    return lower_bound(dp.begin(), dp.end(), infty) - dp.begin();
  }

  bool rollback()
  {
    if (st.empty())
    {
      return false;
    }
    auto const &c{st.top()};
    *c.it = c.value;
    st.pop();
    return true;
  }

private:
};
/***************************************************
    My Library / Graphs
 ***************************************************/
// ----- LowestCommonAncestor -----
class LowestCommonAncestor
{
  // helper classes
  struct Edge
  {
    // Initialized by initializer list. Take care for the order of the field.
    int src, dst;
    ll cost;
  };

  struct Vertex
  {
    int depth;
    ll length;
  };

  // fields
  int N, root, L;
  vector<vector<Edge>> E;
  vector<Vertex> V;
  vector<vector<int>> ancestors;

  // methods
public:
  LowestCommonAncestor(int N, int root = 0);
  void add_edge(int a, int b, ll c = 0);
  void init();
  void init(int root); // after adding all edges.

  // LowestCommonAncestor
  int operator()(int a, int b);

  int depth(int a, int b) { return V[a].depth + V[b].depth - 2 * V[(*this)(a, b)].depth; }
  int depth(int v) { return depth(v, root); }
  ll length(int a, int b) { return V[a].length + V[b].length - 2 * V[(*this)(a, b)].length; }
  ll length(int v) { return length(v, root); }
  int parent(int v) { return ancestors[v][0]; }

private:
  void dfs(int v, int d = 0, ll l = 0, int p = -1);
};
// LowestCommonAncestor: implement
LowestCommonAncestor::LowestCommonAncestor(int N, int root) : N{N}, root{root}, L{0}, E(N), V(N)
{
  while ((1 << L) < N)
  {
    ++L;
  }
  ancestors = vector<vector<int>>(N + 1, vector<int>(L, N));
}
void LowestCommonAncestor::add_edge(int a, int b, ll c)
{
  E[a].push_back(LowestCommonAncestor::Edge{a, b, c});
  E[b].push_back(LowestCommonAncestor::Edge{b, a, c});
}
void LowestCommonAncestor::init(int root)
{
  LowestCommonAncestor::root = root;
  init();
}
void LowestCommonAncestor::init()
{
  dfs(root);
  for (auto i = 0; i < L - 1; i++)
  {
    for (auto v = 0; v < N; v++)
    {
      if (ancestors[v][i] != -1)
      {
        ancestors[v][i + 1] = ancestors[ancestors[v][i]][i];
      }
    }
  }
}
int LowestCommonAncestor::operator()(int a, int b)
{
  if (V[a].depth > V[b].depth)
  {
    swap(a, b);
  }
  int gap = V[b].depth - V[a].depth;
  for (auto i = L - 1; i >= 0; i--)
  {
    int len{1 << i};
    if (gap >= len)
    {
      gap -= len;
      b = ancestors[b][i];
    }
  }
  if (a == b)
  {
    return a;
  }
  for (auto i = L - 1; i >= 0; i--)
  {
    int na{ancestors[a][i]};
    int nb{ancestors[b][i]};
    if (na != nb)
    {
      a = na;
      b = nb;
    }
  }
  return ancestors[a][0];
}
void LowestCommonAncestor::dfs(int v, int d, ll l, int p)
{
  if (p != -1)
  {
    ancestors[v][0] = p;
  }
  V[v].depth = d;
  V[v].length = l;
  for (auto const &e : E[v])
  {
    int u{e.dst};
    if (u == p)
    {
      continue;
    }
    dfs(u, d + 1, l + e.cost, v);
  }
}
// ----- WarshallFloyd -----
template <typename T>
void WarshallFloyd(vector<vector<T>> &V, T infinity = numeric_limits<T>::max())
{
  // It is valid to apply this method for
  //  - a directed/undirected graph,
  //  - a graph whose edge may be negative.
  //    - Negative cycle can be detected by V[i][i] < 0 if we initialize V[i][i] = 0.
  auto N{static_cast<int>(V.size())};
  for (auto k{0}; k < N; ++k)
  {
    for (auto i{0}; i < N; ++i)
    {
      for (auto j{0}; j < N; ++j)
      {
        if (V[i][k] == infinity || V[k][j] == infinity)
        {
          continue;
        }
        ch_min(V[i][j], V[i][k] + V[k][j]);
      }
    }
  }
}
/***************************************************
    My Library / Math
 ***************************************************/
// ----- Permutation -----
struct Permutation
{
  vector<int> V;

  Permutation() {}
  Permutation(vector<int> const &V) : V{V} {}

  static Permutation unit(size_t N)
  {
    vector<int> X(N);
    for (auto i = 0; i < static_cast<int>(N); ++i)
    {
      X[i] = i;
    }
    return Permutation{X};
  }

  size_t size() const { return V.size(); }
  int operator[](size_t i) const { return V[i]; }

  Permutation inverse() const
  {
    vector<int> Q(size());
    for (auto i = 0; i < static_cast<int>(size()); ++i)
    {
      Q[(*this)[i]] = i;
    }
    return Permutation{Q};
  }

  Permutation operator*(Permutation const &Q) const
  {
    assert(size() == Q.size());
    vector<int> R(size());
    for (auto i = 0; i < static_cast<int>(size()); ++i)
    {
      R[i] = (*this)[Q[i]];
    }
    return Permutation{R};
  }

  Permutation &operator*=(Permutation const &Q)
  {
    return *this = *this * Q;
  }

  Permutation pow(int n)
  {
    if (n == 0)
    {
      return unit(size());
    }
    if (n & 1)
    {
      auto W{pow(n / 2)};
      return W * W;
    }
    return *this * pow(n - 1);
  }
};
// ----- Mat (matrix) and Vec -----
template <typename T = ll>
using Vec = vector<T>;
template <typename T = ll>
using Mat = Vec<Vec<T>>;
// operators of Vec / Mat
template <typename T = ll>
Vec<T> operator+(Vec<T> const &A)
{
  return A;
}
template <typename T = ll>
Vec<T> &operator+=(Vec<T> &A, Vec<T> const &B)
{
  assert(A.size() == B.size());
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    A[i] += B[i];
  }
  return A;
}
template <typename T = ll>
Vec<T> &operator+=(Vec<T> &A, T K)
{
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    A[i] += K;
  }
  return A;
}
template <typename T = ll>
Vec<T> operator+(Vec<T> const &A, Vec<T> const &B)
{
  auto C{A};
  C += B;
  return C;
}
template <typename T = ll>
Vec<T> operator+(Vec<T> const &A, T K)
{
  auto C{A};
  C += K;
  return C;
}
template <typename T = ll>
Vec<T> operator+(T K, Vec<T> const &A)
{
  return A + K;
}
template <typename T = ll>
Vec<T> operator-(Vec<T> const &A)
{
  Vec<T> C(A.size());
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    C[i] = -A[i];
  }
  return C;
}
template <typename T = ll>
Vec<T> &operator-=(Vec<T> &A, Vec<T> const &B)
{
  return A += (-B);
}
template <typename T = ll>
Vec<T> &operator-=(Vec<T> &A, T K)
{
  return A += (-K);
}
template <typename T = ll>
Vec<T> operator-(Vec<T> const &A, Vec<T> const &B)
{
  return A + (-B);
}
template <typename T = ll>
Vec<T> operator-(Vec<T> const &A, T K)
{
  return A + (-K);
}
template <typename T = ll>
Vec<T> operator-(T K, Vec<T> const &A)
{
  return K + (-A);
}
template <typename T = ll>
Vec<T> &operator*=(Vec<T> &A, T K)
{
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    A[i] *= K;
  }
  return A;
}
template <typename T = ll>
Vec<T> operator*(T K, Vec<T> const &A)
{
  auto C{A};
  C *= K;
  return C;
}
template <typename T = ll>
Vec<T> operator*(Vec<T> const &A, T K)
{
  return K * A;
}
template <typename T = ll>
Vec<T> &operator/=(Vec<T> &A, T K)
{
  return A *= (1 / K);
}
template <typename T = ll>
Vec<T> operator/(Vec<T> const &A, T K)
{
  return A * (1 / K);
}
template <typename T = ll>
Vec<T> &operator++(Vec<T> &A)
{
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    ++A[i];
  }
  return A;
}
template <typename T = ll>
Vec<T> operator++(Vec<T> &A, int)
{
  auto C{A};
  ++A;
  return C;
}
template <typename T = ll>
Vec<T> &operator--(Vec<T> &A)
{
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    --A[i];
  }
  return A;
}
template <typename T = ll>
Vec<T> operator--(Vec<T> &A, int)
{
  auto C{A};
  --A;
  return C;
}
// generator of unit matrix
// call example: Mat<T> A{unit_matrix<T>(s)};
template <typename T = ll>
Mat<T> UnitMatrix(size_t s)
{
  Mat<T> res(s, Vec<T>(s, T{0}));
  for (auto i = size_t{0}; i < s; ++i)
  {
    res[i][i] = T{1};
  }
  return res;
}
// multiply operators
template <typename T = ll>
Mat<T> operator*(Mat<T> const &A, Mat<T> const &B)
{
  assert(A.front().size() == B.size());
  Mat<T> C(A.size(), Vec<T>(B.front().size()));
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    for (auto j = size_t{0}; j < B.front().size(); j++)
    {
      for (auto k = size_t{0}; k < A.front().size(); k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}
template <typename T = ll>
Mat<T> &operator*=(Mat<T> &A, Mat<T> const &B)
{
  auto C{A * B};
  return A = C;
}
template <typename T = ll>
Vec<T> operator*(Mat<T> const &A, Vec<T> const &V)
{
  assert(A.front().size() == V.size());
  Vec<T> W(A.size());
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    for (auto j = size_t{0}; j < A.front().size(); j++)
    {
      W[i] += A[i][j] * V[j];
    }
  }
  return W;
}
template <typename T = ll>
Mat<T> Power(Mat<T> const &A, ll n)
{
  assert(A.size() == A.front().size());
  if (n == 0)
  {
    return UnitMatrix<T>(A.size());
  }
  if (n & 1)
  {
    return A * pow(A, n - 1);
  }
  auto B{pow(A, n / 2)};
  return B * B;
}
// Transpose
template <typename T = ll>
Mat<T> Transpose(Mat<T> const &A)
{
  Mat<T> C(A.front().size(), Vec<T>(A.size()));
  for (auto i = size_t{0}; i < A.size(); i++)
  {
    for (auto j = size_t{0}; j < A.front().size(); j++)
    {
      C[j][i] = A[i][j];
    }
  }
  return C;
}
/***************************************************
    My Library / Numbers
 ***************************************************/
// ----- Sieve -----
class Sieve
{
  static constexpr ll MAX_SIZE{1000010LL};
  ll N;
  vector<ll> f;
  vector<ll> prime_nums;

public:
  Sieve(ll N = MAX_SIZE) : N{N}, f(N, 0), prime_nums{}
  {
    f[0] = f[1] = -1;
    for (auto i = 2; i < N; i++)
    {
      if (f[i])
      {
        continue;
      }
      prime_nums.push_back(i);
      f[i] = i;
      for (auto j = 2 * i; j < N; j += i)
      {
        if (!f[j])
        {
          f[j] = i;
        }
      }
    }
  }

  bool is_prime(ll x) const
  { // 2 \leq x \leq MAX_SIZE^2
    if (x < N)
    {
      return f[x] == x;
    }
    for (auto e : prime_nums)
    {
      if (x % e == 0)
      {
        return false;
      }
    }
    return true;
  }

  vector<ll> const &primes() const
  {
    return prime_nums;
  }

  vector<ll> factor_list(ll x) const
  {
    if (x < 2)
    {
      return {};
    }
    vector<ll> res;
    auto it{prime_nums.begin()};
    if (x < N)
    {
      while (x != 1)
      {
        res.push_back(f[x]);
        x /= f[x];
      }
    }
    else
    {
      while (x != 1 && it != prime_nums.end())
      {
        if (x % *it == 0)
        {
          res.push_back(*it);
          x /= *it;
        }
        else
        {
          ++it;
        }
      }
      if (x != 1)
      {
        res.push_back(x);
      }
    }
    return res;
  }

  vector<tuple<ll, ll>> factor(ll x) const
  {
    if (x < 2)
    {
      return {};
    }
    auto factors{factor_list(x)};
    vector<tuple<ll, ll>> res{make_tuple(factors[0], 0)};
    for (auto x : factors)
    {
      if (x == get<0>(res.back()))
      {
        get<1>(res.back())++;
      }
      else
      {
        res.emplace_back(x, 1);
      }
    }
    return res;
  }

  map<ll, ll> factor_map(ll x) const
  {
    map<ll, ll> res;
    auto factors{factor(x)};
    for (auto x : factors)
    {
      res[get<0>(x)] = get<1>(x);
    }
    return res;
  }
};
// ----- EulerNums -----
class EulerNums
{
  static constexpr ll MAX_SIZE{1000010LL};
  ll N;
  vector<ll> table;

public:
  EulerNums(ll N = MAX_SIZE) : N{N}
  {
    table.resize(N);
    for (auto i = 0; i < N; i++)
    {
      table[i] = i;
    }
    for (auto i = 2; i < N; i++)
    {
      if (table[i] == i)
      {
        for (auto j = i; j < N; j += i)
        {
          table[j] = table[j] / i * (i - 1);
        }
      }
    }
  }

  ll euler(ll n)
  {
    if (n < N)
    {
      return table[N];
    }
    else
    {
      ll res{n};
      for (auto i = 2LL; i * i <= n; i++)
      {
        if (n % i == 0)
        {
          res = res / i * (i - 1);
        }
        for (; n % i == 0; n /= i)
        {
        }
      }
      if (n != 1)
      {
        res = res / n * (n - 1);
      }
      return res;
    }
  }
};
class LinearMod
{
  vector<ll> A, B, M;

public:
  LinearMod() {}

  void add(ll a, ll b, ll m)
  {
    A.push_back(a);
    B.push_back(b);
    M.push_back(m);
  }

  tuple<ll, ll> get()
  {
    assert(A.size() == B.size() && B.size() == M.size());
    ll x{0}, m{1};
    for (auto i = size_t{0}; i < A.size(); i++)
    {
      ll a{A[i] * m};
      ll b{B[i] - A[i] * x};
      ll d{gcd(M[i], a)};
      if (b % d != 0)
      {
        return make_tuple(0, -1);
      }
      ll t{b / d * mod_inverse(a / d, M[i] / d) % (M[i] / d)};
      x = x + m * t;
      m *= M[i] / d;
    }
    return make_tuple(x % m, m);
  }

private:
  static ll extra_gcd(ll a, ll b, ll &x, ll &y)
  {
    ll d{a};
    if (b != 0)
    {
      d = extra_gcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    else
    {
      x = 1;
      y = 0;
    }
    return d;
  }

  static ll mod_inverse(ll a, ll m)
  {
    ll x, y;
    extra_gcd(a, m, x, y);
    return (m + x % m) % m;
  }
};
/***************************************************
    My Library / Tools
 ***************************************************/
// ----- Compressor -----
template <typename T = ll>
class Compressor
{
  vector<T> raw;
  map<T, int> index;

public:
  Compressor() {}

  template <typename Container>
  Compressor(Container const &V) { append(V); }

  template <typename Iter>
  Compressor(Iter first, Iter last) { append(first, last); }

  template <typename Container>
  void append(Container const &V) { append(V.begin(), V.end()); }

  template <typename Iter>
  void append(Iter first, Iter last)
  {
    set<T> S(first, last);
    raw = vector<T>(S.begin(), S.end());
    sort(raw.begin(), raw.end());
    for (auto i = size_t{0}; i < raw.size(); ++i)
    {
      index[raw[i]] = i;
    }
  }

  T to_raw(int i) { return raw[i]; }
  int to_index(T t) { return index[t]; }
};
// ----- RunLengthCompress -----
template <typename T>
auto RunLengthCompress(T const &S) -> vector<tuple<remove_const_t<remove_reference_t<decltype(S[0])>>, int>>
{
  using U = remove_const_t<remove_reference_t<decltype(S[0])>>;
  vector<tuple<U, int>> res;
  U c{S[0]};
  int x{0};
  for (auto e : S)
  {
    if (c == e)
    {
      ++x;
    }
    else
    {
      res.emplace_back(c, x);
      c = e;
      x = 1;
    }
  }
  res.emplace_back(c, x);
  return res;
}
// ----- Make 2D, 3D, 4D Vectors -----
template <typename T>
vector<vector<T>> Make2DVector(size_t d0, size_t d1, T v = T{})
{
  return vector<vector<T>>(d0, vector<T>(d1, v));
}
template <typename T>
vector<vector<vector<T>>> Make3DVector(size_t d0, size_t d1, size_t d2, T v = T{})
{
  return vector<vector<vector<T>>>(d0, Make2DVector(d1, d2, v));
}
template <typename T>
vector<vector<vector<vector<T>>>> Make4DVector(size_t d0, size_t d1, size_t d2, size_t d3, T v = T{})
{
  return vector<vector<vector<vector<T>>>>(d0, Make3DVector(d1, d2, d3, v));
}
// ----- vector istream and ostream -----
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
  for (auto it{v.begin()}; it != v.end(); ++it)
  {
    is >> *it;
  }
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<vector<T> *> &&v)
{
  for (auto it{v.begin()}; it + 1 != v.end(); ++it)
  {
    assert((*it)->size() == (*(it + 1))->size());
  }
  auto s{(*v.begin())->size()};
  for (auto i{size_t{0}}; i < s; ++i)
  {
    for (auto it{v.begin()}; it != v.end(); ++it)
    {
      cin >> (**it)[i];
    }
  }
  return is;
}
template <typename T, typename U>
ostream &FlushVector(vector<T> const &v, U const &s = "\n", ostream &os = cout)
{
  for (auto it{v.begin()}; it != v.end(); ++it)
  {
    os << *it;
    if (it + 1 != v.end())
    {
      os << s;
    }
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> const &v)
{
  return FlushVector(v, "\n", os);
}
/***************************************************
    Frequently Used Structures
 ***************************************************/
// ----- Constants -----
// constexpr double epsilon{1e-10};
// constexpr ll infty{1'000'000'010LL}; // or
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
/***************************************************
    Solutions
 ***************************************************/

// ----- Solve -----

class Solve
{
  static constexpr int T{3};
  using Event = tuple<ll, bool, int>;
  using Segment = tuple<ll, ll>;

private:
  vector<ll> m, g, m_prime, a, q, R;
  ll lcm_m_prime;
  ll gcd_m_prime;
  vector<map<ll, ll>> m_factor;
  Sieve sieve;

public:
  Solve() : m(T), g(T), m_prime(T), a(T), q(T), R(T), m_factor(T), sieve{}
  {
    for (auto i{0}; i < T; ++i)
    {
      cin >> g[i];
      ll red;
      cin >> red;
      m[i] = g[i] + red;
    }
  }

  void flush()
  {
    make_variables();
#if DEBUG == 1
    for (auto i{0}; i < T; ++i)
    {
      cerr << "m[" << i << "] = " << m[i] << ", ";
      cerr << "g[" << i << "] = " << g[i] << ", ";
      cerr << "m_prime[" << i << "] = " << m_prime[i] << ", ";
      cerr << "a[" << i << "] = " << a[i] << ", ";
      cerr << "q[" << i << "] = " << q[i] << ", ";
      cerr << "R[" << i << "] = " << R[i] << endl;
    }
    cerr << "lcm_m_prime = " << lcm_m_prime << ", gcd_m_prime = " << gcd_m_prime << endl;
#endif
#if DEBUG == 1
    for (auto i{0}; i < T; ++i)
    {
      cerr << "Events for i = " << i << endl;
      for (auto [time, started, id] : make_event(R[i], i))
      {
        cerr << "time = " << time << ", started = " << started << ", id = " << id << endl;
      }
    }
#endif
#if DEBUG == 1
    for (auto [start, goal] : make_segment(R))
    {
      cerr << "[" << start << ", " << goal << ")" << endl;
    }
    cerr << "count_green = " << count_green(R) << endl;
#endif
    mint ans{calc()};
    cout << ans << endl;
  }

private:
  mint calc()
  {
    mint ans{0};
    ans += count_green({R[0], R[1], R[2]});
    ans += count_green({R[0], R[1], m_prime[2]}) * q[2];
    ans += count_green({R[0], m_prime[1], R[2]}) * q[1];
    ans += count_green({R[0], m_prime[1], m_prime[2]}) * q[1] * q[2];
    ans += count_green({m_prime[0], R[1], R[2]}) * q[0];
    ans += count_green({m_prime[0], R[1], m_prime[2]}) * q[0] * q[2];
    ans += count_green({m_prime[0], m_prime[1], R[2]}) * q[0] * q[1];
    ans += count_green({m_prime[0], m_prime[1], m_prime[2]}) * q[0] * q[1] * q[2];
    ans *= compensation();
    return ans;
  }

  mint compensation()
  {
    vector<cpp_int> M(3);
    for (auto i{0}; i < T; ++i)
    {
      M[i] = m[i];
    }
    cpp_int A{1};
    for (auto i{0}; i < T; ++i)
    {
      A *= M[i];
    }
    auto B{lcm(M)};
    cpp_int ans{(A / B) % 998244353};
    return static_cast<mint>(static_cast<ll>(ans));
  }

  mint count_green(vector<ll> const &r)
  {
    auto V{make_segment(r)};
    auto ans{0LL};
    auto L{m_prime[2]};
    auto K{r[2]};
    for (auto [start, goal] : V)
    {
      auto q_start{start / L}, s_start{start % L}, q_goal{goal / L}, s_goal{goal % L};
      ans += max(K - s_start, 0LL) + min(s_goal, K) + (q_goal - q_start - 1) * K;
    }
    return ans;
  }

  vector<Segment> make_segment(vector<ll> const &r)
  {
    auto V{make_event(r[0], 0)};
    auto W{make_event(r[1], 1)};
    V.insert(V.end(), W.begin(), W.end());
    sort(V.begin(), V.end());
    vector<bool> is_started(2, false);
    vector<Segment> res;
    ll start_time{0};
    for (auto const &[time, started, id] : V)
    {
      if (is_started[0] && is_started[1] && !started)
      {
        res.emplace_back(start_time, time);
      }
      else if ((!is_started[0] && is_started[1] && started && id == 0) || (is_started[0] && !is_started[1] && started && id == 1))
      {
        start_time = time;
      }
      is_started[id] = started;
    }
    return res;
  }

  vector<Event> make_event(ll r, int n)
  {
    if (r == 0)
    {
      return {};
    }
    vector<Event> res;
    auto L{m_prime[n]};
    if (r == L)
    {
      res.emplace_back(0, true, n);
      res.emplace_back(lcm_m_prime, false, n);
      return res;
    }
    for (auto i{0}; i < lcm_m_prime / L; ++i)
    {
      res.emplace_back(i * L, true, n);
      res.emplace_back(i * L + r, false, n);
    }
    return res;
  }

  void make_variables()
  {
    for (auto i{0}; i < T; ++i)
    {
      m_factor[i] = sieve.factor_map(m[i]);
    }
    for (auto i{0}; i < T; ++i)
    {
      factor_reduce(m_factor[i], m_factor[(i + 1) % T], m_factor[(i + 2) % T]);
    }
    for (auto i{0}; i < T; ++i)
    {
      m_prime[i] = factor_multiply(m_factor[i]);
    }
    lcm_m_prime = lcm(m_prime);
    gcd_m_prime = gcd(m_prime);
    using info_for_sort = tuple<ll, ll, ll>; // m_prime, m, g;
    vector<info_for_sort> V;
    for (auto i{0}; i < T; ++i)
    {
      V.emplace_back(m_prime[i], m[i], g[i]);
    }
    sort(V.rbegin(), V.rend());
    for (auto i{0}; i < T; ++i)
    {
      auto const &[x, y, z] = V[i];
      m_prime[i] = x;
      m[i] = y;
      g[i] = z;
    }
    for (auto i{0}; i < T; ++i)
    {
      a[i] = lcm_m_prime / m_prime[i];
      q[i] = g[i] / m_prime[i];
      R[i] = g[i] % m_prime[i];
    }
  }

  void factor_reduce(map<ll, ll> &x, map<ll, ll> const &y, map<ll, ll> const &z)
  {
    for (auto &[p, n] : x)
    {
      ch_min(n, max(map_value(y, p), map_value(z, p)));
    }
  }

  ll factor_multiply(map<ll, ll> const &f)
  {
    auto res{1LL};
    for (auto [p, n] : f)
    {
      for (auto i{0}; i < n; ++i)
      {
        res *= p;
      }
    }
    return res;
  }
};

// ----- main() -----

int main()
{
  Solve solve;
  solve.flush();
}
