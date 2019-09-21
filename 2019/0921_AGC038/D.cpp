#define DEBUG 1
/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/9/21 21:33:29
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
using namespace std;
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
using ll = long long;
class mint
{
public:
  static ll MOD;
  ll x;
  mint() : x(0) {}
  mint(ll x) : x(x % MOD) {}
  mint operator-() const { return x ? MOD - x : 0; }
  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  mint &operator-=(const mint &a) { return *this += -a; }
  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint &operator/=(const mint &a)
  {
    mint b{a};
    return *this *= b.power(MOD - 2);
  }
  mint operator+(const mint &a) const { return mint(*this) += a; }
  mint operator-(const mint &a) const { return mint(*this) -= a; }
  mint operator*(const mint &a) const { return mint(*this) *= a; }
  mint operator/(const mint &a) const { return mint(*this) /= a; }
  bool operator<(const mint &a) const { return x < a.x; }
  bool operator==(const mint &a) const { return x == a.x; }
  const mint power(ll N)
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
      mint half = power(N / 2);
      return half * half;
    }
  }
};
ll mint::MOD = 1e9 + 7;
istream &operator>>(istream &stream, mint &a) { return stream >> a.x; }
ostream &operator<<(ostream &stream, const mint &a) { return stream << a.x; }
class combination
{
public:
  vector<mint> inv, fact, factinv;
  static int MAX_SIZE;
  combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i = 2; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[mint::MOD % i]) * (mint::MOD / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i = 1; i < MAX_SIZE; i++)
    {
      fact[i] = mint(i) * fact[i - 1];
      factinv[i] = inv[i] * factinv[i - 1];
    }
  }
  mint operator()(int n, int k)
  {
    if (n >= 0 && k >= 0 && n - k >= 0)
    {
      return fact[n] * factinv[k] * factinv[n - k];
    }
    return 0;
  }
};
int combination::MAX_SIZE = 3000010;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// constexpr double epsilon = 1e-10;
// constexpr ll infty = 1000000000000000LL;
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
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

class UnionFind
{
  vector<long long> par;

public:
  UnionFind() {}
  UnionFind(int n) : par(n, -1) {}

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

  long long size(int x)
  {
    return -par[root(x)];
  }

  bool is_root(int x)
  {
    return (par[x] < 0);
  }

  void all_root()
  {
    for (auto i = 0u; i < par.size(); i++)
    {
      root(i);
    }
  }

  void view()
  {
    for (auto i = 0u; i < par.size(); i++)
    {
      cerr << "par[" << i << "] = " << par[i] << endl;
    }
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

ll N, M, Q;
int A[100010];
int B[100010];
int C[100010];
using edge = tuple<int, int>;
set<edge> S[2];

int main()
{
  cin >> N >> M >> Q;
  for (auto i = 0; i < Q; i++)
  {
    cin >> A[i] >> B[i] >> C[i];
  }
  if (M == N - 1)
  {
    for (auto i = 0; i < Q; i++)
    {
      if (C[i] == 1)
      {
        No();
      }
    }
    Yes();
  }
  for (auto i = 0; i < Q; i++)
  {
    if (A[i] > B[i])
    {
      swap(A[i], B[i]);
      edge e{A[i], B[i]};
      if (S[1 - C[i]].find(e) != S[1 - C[i]].end())
      {
        No();
      }
      S[C[i]].insert(e);
    }
  }
  UnionFind uf(N);
  for (auto e : S[0])
  {
    uf.merge(get<0>(e), get<1>(e));
#if DEBUG == 1
    cerr << get<0>(e) << ", " << get<1>(e) << endl;
#endif
  }
  uf.all_root();
#if DEBUG == 1
  uf.view();
#endif
  ll K{0};
  ll X{0};
  for (auto i = 0; i < N; i++)
  {
    if (uf.is_root(i))
    {
      X += uf.size(i) - 1;
      ++K;
    }
  }
  ll mini{X + K};
  ll maxi{X + K * (K - 1) / 2};
  assert(mini == N);
  if (K >= 3 && mini <= M && M <= maxi)
  {
    Yes();
  }
  No();
}