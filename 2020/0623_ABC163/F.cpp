#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/6/23 5:42:51
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
  int src, dst, id, rev;
  // ll cost;
  Edge() {}
  Edge(int src, int dst, int id, int rev) : src{src}, dst{dst}, id{id}, rev{rev} {}

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
    switch (type)
    {
    case GraphType::Undirected:
    {
      Edge edge{v, w, static_cast<int>(E.size()), static_cast<int>(E.size())};
      edge.added_edge(V);
      edge.added_rev(V);
      E.push_back(edge);
      break;
    }
    case GraphType::Directed:
    {
      Edge edge{v, w, static_cast<int>(E.size()), static_cast<int>(E.size())};
      edge.added_edge(V);
      E.push_back(edge);
      break;
    }
    case GraphType::RevEdge:
    {
      Edge edge{v, w, static_cast<int>(E.size()), static_cast<int>(E.size()) + 1};
      edge.added_edge(V);
      edge.added_rev(V);
      E.push_back(edge);
      E.push_back(edge.rev_edge());
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

// ----- Solve -----

chrono::system_clock::time_point time_start = chrono::system_clock::now();

void TimeStamp()
{
  cerr << chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - time_start).count() << endl;
}

struct SubTree
{
  ll id, size;
};

class Solve
{
  ll N, id;
  vector<queue<SubTree>> Q;
  vector<ll> C;
  vector<vector<Edge>> V;
  vector<vector<ll>> S;
  vector<ll> color_to_count;

public:
  Solve(ll N) : N{N}, id{0}, Q(N), C(N), S(N), color_to_count(N, 0)
  {
    for (auto i{0}; i < N; ++i)
    {
      cin >> C[i];
      C[i]--;
      color_to_count[C[i]]++;
    }
    V = ReadTree(N);
  }

  void flush()
  {
    dfs();
    for (auto i{0}; i < N; ++i)
    {
      auto sum{accumulate(S[i].begin(), S[i].end(), 0)};
      S[i].push_back(N - sum - color_to_count[i]);
      ll ans{0};
      for (auto e : S[i])
      {
        ans += e * (e + 1) / 2;
      }
#if DEBUG == 1
      cerr << "S[" << i << "] : ";
      for (auto e : S[i])
      {
        cerr << e << ", ";
      }
      cerr << endl;
#endif
      cout << N * (N + 1) / 2 - ans << endl;
    }
  }

private:
  ll dfs(ll src = 0, ll parent = -1)
  {
#if DEBUG == 1
    TimeStamp();
    cerr << "dfs(" << src << ")" << endl;
#endif
    auto src_id{id++};
    auto &subtree_queue{Q[C[src]]};
    for (auto const &e : V[src])
    {
      if (e.dst == parent)
      {
        continue;
      }
      auto colorless_tree_size{dfs(e.dst, src)};
      while (!subtree_queue.empty() && subtree_queue.front().id > src_id)
      {
        colorless_tree_size -= subtree_queue.front().size;
        subtree_queue.pop();
      }
      S[C[src]].push_back(colorless_tree_size);
    }
    auto subtree_size{id - src_id};
    subtree_queue.push(SubTree{src_id, subtree_size});
    return subtree_size;
  }
};

// ----- main() -----

int main()
{
  ll N;
  cin >> N;
  Solve solve(N);
  solve.flush();
}
