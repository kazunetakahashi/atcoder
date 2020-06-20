#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/6/21 1:36:25
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

// ----- ReadGraph -----
// Referring to ymatsux-san's source code: https://atcoder.jp/contests/abc138/submissions/7016619

struct Edge
{
  int src, dst, id, rev_id;
  // ll cost;
  Edge() {}
  Edge(int src, int dst, int id, int rev_id) : src{src}, dst{dst}, id{id}, rev_id{rev_id} {}
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

tuple<vector<vector<Edge>>, vector<Edge>> ReadGraphWithEdges(int N, int M, bool is_undirected = true, bool is_one_indexed = true)
{
  vector<vector<Edge>> V(N);
  vector<Edge> E(2 * M);
  int ind{0};
  for (auto i = 0; i < M; ++i)
  {
    int v, w;
    cin >> v >> w;
    if (is_one_indexed)
    {
      --v;
      --w;
    }
    Edge edge{v, w, ind, ind + 1};
    edge.added_edge(V);
    E[ind++] = edge;
    Edge edge_rev{w, v, ind, ind - 1};
    edge_rev.added_edge(V);
    E[ind++] = edge_rev;
  }
  return make_tuple(V, E);
}

vector<vector<Edge>> ReadGraph(int N, int M, bool is_undirected = true, bool is_one_indexed = true)
{
  return get<0>(ReadGraphWithEdges(N, M, is_undirected, is_one_indexed));
}

tuple<vector<vector<Edge>>, vector<Edge>> ReadTreeWithEdges(int N)
{
  return ReadGraphWithEdges(N, N - 1);
}

vector<vector<Edge>> ReadTree(int N)
{
  return ReadGraph(N, N - 1);
}

// ----- Solve -----

combination C;

class Solve
{
  int N;
  vector<vector<Edge>> V;
  vector<Edge> E;
  vector<ll> S;
  vector<mint> dp;
  vector<bool> visited_S;
  vector<bool> visited_dp;

public:
  Solve(int N) : N{N}, S(2 * N - 2, 0), dp(2 * N - 2, 0), visited_S(2 * N - 2, false), visited_dp(2 * N - 2, false)
  {
    tie(V, E) = ReadTreeWithEdges(N);
  }

  void flush()
  {
    for (auto i{0}; i < N; ++i)
    {
      cout << answer(i) << endl;
    }
  }

private:
  ll children_size(int v)
  {
    ll T{1};
    for (auto const &e : V[v])
    {
      T += calc_S(e.id);
    }
    for (auto const &e : V[v])
    {
      if (visited_S[e.rev_id])
      {
        continue;
      }
      auto X{T};
      X -= calc_S(e.id);
      S[e.rev_id] = X;
      visited_S[e.rev_id] = true;
    }
    return T;
  }

  mint answer(int v)
  {
    auto T{children_size(v)};
    auto ans{C.fact[T - 1]};
    for (auto const &e : V[v])
    {
      ans *= calc_dp(e.id) * C.factinv[calc_S(e.id)];
    }
    for (auto const &e : V[v])
    {
      if (visited_dp[e.rev_id])
      {
        continue;
      }
      auto X{ans};
      X /= C.fact[T - 1];
      X *= C.fact[calc_S(e.rev_id) - 1];
      X /= calc_dp(e.id) * C.factinv[calc_S(e.id)];
      dp[e.rev_id] = X;
      visited_dp[e.rev_id] = true;
    }
    return ans;
  }

  ll calc_S(int id)
  {
    if (visited_S[id])
    {
      return S[id];
    }
    visited_S[id] = true;
    auto src{E[id].dst};
    auto parent{E[id].src};
    S[id] = 1;
    for (auto const &e : V[src])
    {
      if (e.dst == parent)
      {
        continue;
      }
      S[id] += calc_S(e.id);
    }
    return S[id];
  }

  mint calc_dp(int id)
  {
    if (visited_dp[id])
    {
      return dp[id];
    }
    visited_dp[id] = true;
    auto src{E[id].dst};
    auto parent{E[id].src};
    dp[id] = C.fact[calc_S(id) - 1];
    for (auto const &e : V[src])
    {
      if (e.dst == parent)
      {
        continue;
      }
      dp[id] *= calc_dp(e.id) * C.factinv[calc_S(e.id)];
    }
    return dp[id];
  }
};

// ----- main() -----

int main()
{
  int N;
  cin >> N;
  Solve solve(N);
  solve.flush();
}
