#define DEBUG 1
/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 10/7/2020, 7:10:56 PM
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
// ----- AtCoder Library -----
#include <atcoder/all>
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
// ----- mint -----
using mint = atcoder::modint1000000007;
// using mint = atcoder::modint998244353;
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
// ----- Math -----
using atcoder::floor_sum;
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

class Solve
{

public:
  Solve()
  {
  }

  void flush()
  {
  }

private:
};

// ----- main() -----

/*
int main()
{
  Solve solve;
  solve.flush();
}
*/

combination C;

int main()
{
  ll k;
  string s;
  cin >> k >> s;
  mint ans{0};
  ll y{static_cast<ll>(s.size())};
  for (auto x{0}; x <= y; ++x)
  {
    ans += C(y + k - x - 1, k - 1) * mint{26}.pow(x) * mint{25}.pow(k - x);
  }
  cout << ans << endl;
}
