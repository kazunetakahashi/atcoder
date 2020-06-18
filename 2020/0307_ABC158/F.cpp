#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/19/2020, 12:05:07 AM
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

// ----- SegTree -----
// Referring to the following great materials.
//  - tsutaj-san's article: https://tsutaj.hatenablog.com/entry/2017/03/30/224339
//  - drken-san's article: https://drken1215.hatenablog.com/entry/2019/02/19/110200
//  - tsutaj-san's libary: https://tsutaj.github.io/cpp_library/library/structure/strc_021_dynamic_lazy_segtree.cpp.html
// Many thanks to them.

template <typename Monoid, typename Action>
class SegTree
{
  struct SegNode
  {
    bool need_update;
    unique_ptr<SegNode> left, right;
    Monoid value;
    Action lazy_value;

    // constructor
    SegNode() {}
    SegNode(Monoid value, Action lazy_value)
        : need_update{false},
          left{nullptr},
          right{nullptr},
          value{value},
          lazy_value{lazy_value} {}

    // copy constructor
    SegNode(SegNode const &node)
        : need_update{node.need_update},
          value{node.value},
          lazy_value{node.lazy_value}
    {
      if (node.left)
      {
        left = make_unique<SegNode>(*(node.left));
      }
      if (node.right)
      {
        left = make_unique<SegNode>(*(node.right));
      }
    }

    // copy assignment
    SegNode &operator=(SegNode const &node)
    {
      SegNode tmp{node};
      swap(tmp, *this);
      return *this;
    }

    // move constructor
    SegNode(SegNode &&node)
        : need_update{node.need_update},
          left{move(node.left)},
          right{move(node.right)},
          value{node.value},
          lazy_value{node.lazy_value} {}

    // move assignment
    SegNode &operator=(SegNode &&node)
    {
      swap(need_update, node.need_update);
      swap(left, node.left);
      swap(right, node.right);
      swap(value, node.value);
      swap(lazy_value, node.lazy_value);
      return *this;
    }
  };

  using FuncAction = function<void(Monoid &, Action)>;
  using FuncMonoid = function<Monoid(Monoid, Monoid)>;
  using FuncLazy = function<void(Action &, Action)>;
  using FuncIndex = function<Action(Action, int)>;

  // fields
  int N;
  unique_ptr<SegNode> root;
  // unities
  Monoid unity_monoid;
  Action unity_action;
  // functions
  FuncAction func_update;
  FuncMonoid func_combine;
  FuncLazy func_lazy;
  FuncIndex func_accumulate;

public:
  // constructor
  SegTree() {}
  SegTree(
      int n, Monoid unity_monoid, Action unity_action,
      FuncAction func_update,
      FuncMonoid func_combine,
      FuncLazy func_lazy,
      FuncIndex func_accumulate)
      : N{1}, root{make_unique<SegNode>(unity_monoid, unity_action)},
        unity_monoid{unity_monoid}, unity_action{unity_action},
        func_update{func_update},
        func_combine{func_combine},
        func_lazy{func_lazy},
        func_accumulate{func_accumulate}
  {
    while (N < n)
    {
      N <<= 1;
    }
  }

  // copy constructor
  SegTree(SegTree const &tree)
      : N{tree.N}, unity_monoid{tree.unity_monoid}, unity_action{tree.unity_action},
        func_update{tree.func_update},
        func_combine{tree.func_combine},
        func_lazy{tree.func_lazy},
        func_accumulate{tree.func_accumulate}
  {
    if (tree.root)
    {
      root = make_unique<SegNode>(*(tree.root));
    }
  }

  // copy assignment
  SegTree &operator=(SegTree const &tree)
  {
    SegTree tmp{tree};
    swap(tmp, *this);
    return *this;
  }

  // move constructor
  SegTree(SegTree &&tree)
      : N{tree.N}, root{move(tree.root)},
        unity_monoid(tree.unity_monoid), unity_action(tree.unity_action),
        func_update{tree.func_update},
        func_combine{tree.func_combine},
        func_lazy{tree.func_lazy},
        func_accumulate{tree.func_accumulate} {}

  // move assignment
  SegTree &operator=(SegTree &&tree)
  {
    swap(N, tree.N);
    swap(root, tree.root);
    swap(unity_monoid, tree.unity_monoid);
    swap(unity_action, tree.unity_action);
    swap(func_update, tree.func_update);
    swap(func_combine, tree.func_combine);
    swap(func_lazy, tree.func_lazy);
    swap(func_accumulate, tree.func_accumulate);
    return *this;
  }

  void update(int a, int b, Action const &x) { update(root.get(), a, b, x, 0, N); }
  void update(int a, Action const &x) { update(a, a + 1, x); }
  Monoid query(int a, int b) { return query(root.get(), a, b, 0, N); }
  Monoid query(int a) { return query(a, a + 1); }
  Monoid operator[](size_t i) { return query(static_cast<int>(i)); }

private:
  void node_maker(unique_ptr<SegNode> &pt) const
  {
    if (!pt)
    {
      pt = make_unique<SegNode>(unity_monoid, unity_action);
    }
  }

  void evaluate(SegNode *node, int l, int r)
  {
    if (!node->need_update)
    {
      return;
    }
    func_update(node->value, func_accumulate(node->lazy_value, r - l));
    if (r - l > 1)
    {
      node_maker(node->left);
      func_lazy(node->left->lazy_value, node->lazy_value);
      node->left->need_update = true;
      node_maker(node->right);
      func_lazy(node->right->lazy_value, node->lazy_value);
      node->right->need_update = true;
    }
    node->lazy_value = unity_action;
    node->need_update = false;
  }

  void update(SegNode *node, int a, int b, Action const &x, int l, int r)
  {
    evaluate(node, l, r);
    if (b <= l || r <= a)
    {
      return;
    }
    if (a <= l && r <= b)
    {
      func_lazy(node->lazy_value, x);
      node->need_update = true;
      evaluate(node, l, r);
    }
    else
    {
      auto mid{(l + r) >> 1};
      node_maker(node->left);
      update(node->left.get(), a, b, x, l, mid);
      node_maker(node->right);
      update(node->right.get(), a, b, x, mid, r);
      node->value = func_combine(node->left->value, node->right->value);
    }
  }

  Monoid query(SegNode *node, int a, int b, int l, int r)
  {
    if (b <= l || r <= a)
    {
      return unity_monoid;
    }
    evaluate(node, l, r);
    if (a <= l && r <= b)
    {
      return node->value;
    }
    auto mid{(l + r) >> 1};
    auto vl{(node->left ? query(node->left.get(), a, b, l, mid) : unity_monoid)};
    auto vr{(node->right ? query(node->right.get(), a, b, mid, r) : unity_monoid)};
    return func_combine(vl, vr);
  }
};

// ----- RangePlusQuery -----
//  - update(i, x) : a[i] += x;,
//  - update(s, t, x) : a[i] += x; for all i \in [s, t),
//  - query(i) : return a[i];,
//  - query(s, t) : return the sum a[i] where i runs on [s, t).

// ----- RangeSumQuery -----
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja
//  - update(i, x) : a[i] += x;,
//  - query(s, t) : return the sum a[i] where i runs on [s, t).

// ----- RangeAddQuery -----
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=ja
//  - update(s, t, x) : a[i] += x; for all i \in [s, t),
//  - query(i) : return a[i].

// ----- RSU_RAU -----
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja
//  - update(s, t, x) : a[i] += x; for all i \in [s, t),
//  - query(s, t) : return the sum a[i] where i runs on [s, t).

template <typename Monoid>
SegTree<Monoid, Monoid> RangePlusQuery(int N, Monoid const &monoid_zero)
{
  using Action = Monoid;
  return SegTree<Monoid, Action>{
      N, monoid_zero, monoid_zero,
      [](Monoid &x, Action y) { x += y; },
      [](Monoid x, Monoid y) { return x + y; },
      [](Action &x, Action y) { return x += y; },
      [](Action x, int y) { return x * static_cast<Action>(y); }};
}

template <typename Monoid>
SegTree<Monoid, Monoid> RangePlusQuery(int N)
{
  return RangePlusQuery<Monoid>(N, 0);
}

// ----- RangeMinQuery -----
//  - update(i, x) : a[i] = x;,
//  - update(s, t, x) : a[i] = x; for all i \in [s, t),
//  - query(i) : return a[i];,
//  - query(s, t) : return the minimum of a[i] where i runs on [s, t).

// ----- RangeMinimumQuery -----
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=ja
//  - update(i, x) : a[i] = x;,
//  - query(s, t) : return the minimum of a[i] where i runs on [s, t).

// ----- RangeUpdateQuery -----
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&lang=ja
//  - update(s, t, x) : a[i] = x; for all i \in [s, t),
//  - query(i) : return a[i].

// ----- RMQ_RUQ -----
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja
//  - update(s, t, x) : a[i] = x; for all i \in [s, t),
//  - query(s, t) : return the minimum of a[i] where i runs on [s, t).

template <typename Monoid>
SegTree<Monoid, Monoid> RangeMinQuery(int N, Monoid const &monoid_infty)
{
  using Action = Monoid;
  return SegTree<Monoid, Action>{
      N, monoid_infty, monoid_infty,
      [](Monoid &x, Action y) { x = y; },
      [](Monoid x, Monoid y) { return min(x, y); },
      [](Action &x, Action y) { return x = y; },
      [](Action x, int) { return x; }};
}

template <typename Monoid>
SegTree<Monoid, Monoid> RangeMinQuery(int N)
{
  return RangeMinQuery<Monoid>(N, numeric_limits<Monoid>::max());
}

// ----- RMQ_RAQ -----
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja
//  - update(s, t, x) : a[i] += x; for all i \in [s, t),
//  - query(s, t) : return the minimum of a[i] where i runs on [s, t).
// update should be called as follows.
// tree.update(s, t, make_tuple(x, true));

template <typename Monoid>
SegTree<Monoid, tuple<Monoid, bool>> RMQ_RAQ(int N, Monoid const &monoid_zero, Monoid const &monoid_infty)
{
  using Action = tuple<Monoid, bool>;
  auto tree{SegTree<Monoid, Action>{
      N, monoid_infty, Action{monoid_zero, true},
      [](Monoid &x, Action y) {
        if (get<1>(y))
        {
          x += get<0>(y);
        }
        else
        {
          x = get<0>(y);
        }
      },
      [](Monoid x, Monoid y) { return min(x, y); },
      [](Action &x, Action y) {
        if (get<1>(y))
        {
          get<0>(x) += get<0>(y);
        }
        else
        {
          x = y;
        }
      },
      [](Action x, int) { return x; }}};
  tree.update(0, N, Action{monoid_zero, false});
  return tree;
}

template <typename Monoid>
SegTree<Monoid, tuple<Monoid, bool>> RMQ_RAQ(int N)
{
  return RMQ_RAQ<Monoid>(N, 0, numeric_limits<Monoid>::max());
}

// ----- RSQ_RUQ -----
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I&lang=ja
//  - update(s, t, x) : a[i] = x; for all i \in [s, t),
//  - query(s, t) : return the sum of a[i] where i runs on [s, t).

template <typename Monoid>
SegTree<Monoid, Monoid> RSQ_RUQ(int N, Monoid const &monoid_zero)
{
  using Action = Monoid;
  return SegTree<Monoid, Action>{
      N, monoid_zero, monoid_zero,
      [](Monoid &x, Action y) { x = y; },
      [](Monoid x, Monoid y) { return x + y; },
      [](Action &x, Action y) { return x = y; },
      [](Action x, int y) { return x * static_cast<Action>(y); }};
}

template <typename Monoid>
SegTree<Monoid, Monoid> RSQ_RUQ(int N)
{
  return RSQ_RUQ<Monoid>(N, 0);
}

// ----- Solve -----

using Robot = tuple<ll, ll>;

class Solve
{
  int N;
  vector<Robot> robots;

public:
  Solve(int N) : N{N}, robots(N)
  {
    for (auto i{0}; i < N; ++i)
    {
      auto &[x, d] = robots[i];
      cin >> x >> d;
    }
    sort(robots.rbegin(), robots.rend());
  }

  void flush()
  {
    auto tree{RangeMinQuery<int>(N)};
    for (auto i{0}; i < N; ++i)
    {
      auto [x, d]{robots[i]};
      int ng{-1}, ok{i};
      while (abs(ok - ng) > 1)
      {
        int t{(ng + ok) / 2};
        if (get<0>(robots[t]) <= x + d)
        {
          ok = t;
        }
        else
        {
          ng = t;
        }
      }
      tree.update(i, min(i, tree.query(ok, i)));
    }
    vector<mint> DP(N + 1);
    DP[0] = 1;
    for (auto i{0}; i < N; ++i)
    {
      DP[i + 1] = DP[i] + DP[tree[i]];
    }
    cerr << DP[N] << endl;
  }

private:
};

// ----- main() -----

int main()
{
  int N;
  cin >> N;
  Solve solve(N);
  solve.flush();
}
