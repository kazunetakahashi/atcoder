#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/22/2019, 9:32:40 PM
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
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
typedef long long ll;
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
const int MAX_SIZE = 1000010;
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
  mint &operator/=(const mint &a) { return (*this *= power(MOD - 2)); }
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
mint inv[MAX_SIZE];
mint fact[MAX_SIZE];
mint factinv[MAX_SIZE];
void init()
{
  inv[1] = 1;
  for (int i = 2; i < MAX_SIZE; i++)
  {
    inv[i] = (-inv[mint::MOD % i]) * (mint::MOD / i);
  }
  fact[0] = factinv[0] = 1;
  for (int i = 1; i < MAX_SIZE; i++)
  {
    fact[i] = mint(i) * fact[i - 1];
    factinv[i] = inv[i] * factinv[i - 1];
  }
}
mint choose(int n, int k)
{
  if (n >= 0 && k >= 0 && n - k >= 0)
  {
    return fact[n] * factinv[k] * factinv[n - k];
  }
  return 0;
}
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// const double epsilon = 1e-10;
// const ll infty = 1000000000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

class UnionFind
{
public:
  vector<long long> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n)
  {
    par.assign(n, -1);
  }

  int root(int x)
  {
    if (par[x] < 0)
    {
      return x;
    }
    return par[x] = root(par[x]);
  }

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
};

int N;
int x[100010];
int y[100010];
bool visited[100010];

vector<int> X[100010];
vector<int> Y[100010];

set<int> used_x;
set<int> used_y;

void add_point(int P, UnionFind &uf, int k)
{
  visited[P] = true;
  used_x.insert(x[P]);
  used_y.insert(y[P]);
  if (k == 0)
  {
    for (auto e : X[x[P]])
    {
      if (!visited[e])
      {
        uf.merge(P, e);
        add_point(e, uf, 1);
      }
    }
  }
  else if (k == 1)
  {
    for (auto e : Y[y[P]])
    {
      if (!visited[e])
      {
        uf.merge(P, e);
        add_point(e, uf, 0);
      }
    }
  }
}

ll solve(int P)
{
#if DEBUG == 1
  cerr << "solve(" << P << ")" << endl;
#endif
  used_x.clear();
  used_y.clear();
  UnionFind uf(N);
  add_point(P, uf, 0);
  add_point(P, uf, 1);
  ll s = uf.size(P);
  ll a = 0, b = 0;
  a = used_x.size();
  b = used_y.size();
#if DEBUG == 1
  cerr << "a = " << a << ", b = " << b << ", s = " << s << endl;
#endif
  return a * b - s;
}

int main()
{
  // init();
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> x[i] >> y[i];
    X[x[i]].push_back(i);
    Y[y[i]].push_back(i);
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    if (!visited[i])
    {
      ans += solve(i);
    }
  }
  cout << ans << endl;
}