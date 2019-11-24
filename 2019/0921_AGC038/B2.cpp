#define DEBUG 1
/**
 * File    : B2.cpp
 * Author  : Kazune Takahashi
 * Created : 11/24/2019, 3:04:17 PM
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
  bool operator==(const Mint &a) const { return x == a.x; }
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

// ----- UnionFind -----

class UnionFind
{
  int N;
  vector<int> par;

public:
  UnionFind() : N{0} {}
  UnionFind(int N) : N{N}, par(N, -1) {}

  bool is_same(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
    {
      return false;
    }
    if (par[x] > par[y])
    {
      swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x)
  {
    return -par[root(x)];
  }

  int count_parts()
  {
    int ans{0};
    for (auto i = 0; i < N; i++)
    {
      if (root(i) < 0)
      {
        ++ans;
      }
    }
    return ans;
  }

private:
  int root(int x)
  {
    if (par[x] < 0)
    {
      return x;
    }
    return par[x] = root(par[x]);
  }
};

// ----- main() -----

vector<int> rev(vector<int> const &P)
{
  vector<int> Q(P.size());
  for (auto i = 0; i < static_cast<int>(P.size()); i++)
  {
    Q[P[i]] = i;
  }
  return Q;
}

void flush(int N, int K, UnionFind &uf)
{
  if (uf.size(N - K + 1) == 1)
  {
    cout << uf.count_parts() - 1 << endl;
  }
  else
  {
    cout << uf.count_parts() << endl;
  }
}

vector<int> ascend_sum(int N, int K, vector<int> const &P)
{
  vector<int> ascend(N - 1);
  for (auto i = 0; i < N - 1; i++)
  {
    ascend[i] = P[i] < P[i + 1] ? 0 : 1;
  }
  vector<int> res(N, 0);
  for (auto i = 1; i < N; i++)
  {
    res[i] = res[i - 1] + ascend[i - 1];
  }
  return res;
}

void connect_origin(int N, int K, vector<int> const &P, UnionFind &uf)
{
  vector<int> A{ascend_sum(N, K, P)};
  for (auto i = 0; i <= N - K; i++)
  {
    if (A[i + K] - A[i] == 0)
    {
      uf.merge(i, N - K + 1);
    }
  }
}

vector<bool> is_mini(int N, int K, vector<int> const &Q)
{
  vector<bool> res(N, false);
  set<int> S;
  for (auto e : Q)
  {
    S.insert(e);
    if (0 <= e && e <= N - K - 1)
    {
      auto it{S.find(e)};
      ++it;
      if (it == S.end() || *it - e > K)
      {
        res[e] = true;
      }
    }
  }
  return res;
}

vector<bool> is_maxi(int N, int K, vector<int> const &Q)
{
  vector<bool> res(N, false);
  set<int> S;
  for (auto e : Q)
  {
    S.insert(e);
    if (K <= e && e <= N - 1)
    {
      auto it{S.find(e)};
      auto it0{it};
      --it0;
      if (it == S.begin() || e - *it0 > K)
      {
        res[e] = true;
      }
    }
  }
  return res;
}

void connect_adjacent(int N, int K, vector<int> const &P, UnionFind &uf)
{
  vector<int> Q{rev(P)};
  vector<int> R(Q);
  reverse(R.begin(), R.end());
  vector<bool> mini{is_mini(N, K, Q)}, maxi{is_maxi(N, K, R)};
#if DEBUG == 1
  cerr << "is_mini ";
  for (auto x : mini)
  {
    cerr << x;
  }
  cerr << endl;
  cerr << "is_maxi ";
  for (auto x : maxi)
  {
    cerr << x;
  }
  cerr << endl;
#endif
  for (auto i = 0; i < N - K; i++)
  {
    if (mini[i] && maxi[i + K])
    {
      uf.merge(i, i + 1);
    }
  }
}

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  for (auto i = 0; i < N; i++)
  {
    cin >> P[i];
  }
  UnionFind uf(N - K + 2); // the node N - K + 1 is origin.
  connect_origin(N, K, P, uf);
  connect_adjacent(N, K, P, uf);
  flush(N, K, uf);
}
