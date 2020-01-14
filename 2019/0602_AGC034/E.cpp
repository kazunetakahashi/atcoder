#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 1/9/2020, 5:23:08 PM
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
constexpr ll infty{1000000000000000LL};
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
// ----- main() -----

struct Vertex
{
  ll h, c, l, r;
  Vertex() {}
  Vertex(ll h, ll c = 0, ll l = 0, ll r = 0) : h{h}, c{c}, l{l}, r{r} {}

  void upper()
  {
    l += c;
    r += c;
  }
};

ostream &operator<<(ostream &os, Vertex const &v)
{
  return os << "{h:" << v.h << ", c:" << v.c << ", l:" << v.l << ", r:" << v.r << "}";
}

class Solve
{
  // tree construction
  int N;
  string S;
  vector<vector<int>> V;

  // data structure
  int root;
  vector<Vertex> A;

public:
  Solve(int N, string S, vector<vector<int>> const &V) : N{N}, S{S}, V(V), A(N)
  {
    assert(static_cast<int>(S.size()) == N && static_cast<int>(V.size()) == N);
  }

  ll calc()
  {
    ll ans{infty};
    for (auto i = 0; i < N; i++)
    {
      ch_min(ans, solve(i));
    }
    return ans;
  }

private:
  ll solve(int root)
  {
#if DEBUG == 1
    cerr << "root = " << root << endl;
#endif
    init(root);
    dfs(root);
    if (A[root].l == 0)
    {
      return A[root].r / 2;
    }
    else
    {
      return infty;
    }
  }

  void init(int root)
  {
    Solve::root = root;
    for (auto i = 0; i < N; i++)
    {
      A[i] = Vertex(S[i] - '0');
    }
  }

  void dfs(int v, int parent = -1)
  {
    for (auto e : V[v])
    {
      if (e != parent)
      {
        dfs(e, v);
      }
    }
    ll sum_R{0};
    A[v].c += A[v].h;
    for (auto e : V[v])
    {
      if (e != parent)
      {
        A[e].upper();
        A[v].c += A[e].c;
        sum_R += A[e].r;
      }
    }
    A[v].r = sum_R;
    A[v].l = sum_R;
    for (auto e : V[v])
    {
      if (e != parent)
      {
        ll tmp_R{sum_R - A[e].r};
        if (tmp_R < A[e].l)
        {
          ch_min(A[v].l, A[e].l - tmp_R);
        }
        else
        {
          ch_min(A[v].l, sum_R % 2);
        }
      }
    }
#if DEBUG == 1
    cerr << "A[" << v << "] = " << A[v] << endl;
#endif
  }
};

int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<vector<int>> V(N);
  for (auto i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  Solve solve(N, S, V);
  ll ans{solve.calc()};
  if (ans == infty)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
  }
}
