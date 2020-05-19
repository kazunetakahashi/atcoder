#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 7/8/2019, 12:45:11 AM
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
using ll = long long;
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
class combination
{
public:
  vector<mint> inv, fact, factinv;
  static int MAX_SIZE;
  combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (int i = 2; i < MAX_SIZE; i++)
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
int combination::MAX_SIZE = 1e6 + 10;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// const double epsilon = 1e-10;
// const ll infty = 1000000000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

template <typename T>
class LCA
{
  int N, root, L;
  vector<vector<int>> to;
  vector<vector<T>> co;
  vector<int> dep;
  vector<T> costs;
  vector<vector<int>> par;

public:
  LCA(int n) : N{n}, to(n), co(n), dep(n), costs(n)
  {
    L = 0;
    while ((1 << L) < N)
    {
      ++L;
    }
    par = vector<vector<int>>(N + 1, vector<int>(L, N));
  }

  void add_edge(int a, int b, T c = 0)
  {
    to[a].push_back(b);
    co[a].push_back(c);
    to[b].push_back(a);
    co[b].push_back(c);
  }

  void init(int _root)
  {
    root = _root;
    dfs(root);
    for (auto i = 0; i < L - 1; i++)
    {
      for (auto v = 0; v < N; v++)
      {
        if (par[v][i] != -1)
        {
          par[v][i + 1] = par[par[v][i]][i];
        }
      }
    }
  }

  // LCA
  int operator()(int a, int b)
  {
    if (dep[a] > dep[b])
    {
      swap(a, b);
    }
    int gap = dep[b] - dep[a];
    for (auto i = L - 1; i >= 0; i--)
    {
      int len = 1 << i;
      if (gap >= len)
      {
        gap -= len;
        b = par[b][i];
      }
    }
    if (a == b)
    {
      return a;
    }
    for (auto i = L - 1; i >= 0; i--)
    {
      int na = par[a][i];
      int nb = par[b][i];
      if (na != nb)
      {
        a = na;
        b = nb;
      }
    }
    return par[a][0];
  }

  int length(int a, int b)
  {
    int c = (*this)(a, b);
    return dep[a] + dep[b] - 2 * dep[c];
  }

  T dist(int a, int b)
  {
    int c = (*this)(a, b);
    return costs[a] + costs[b] - 2 * costs[c];
  }

private:
  void dfs(int v, int d = 0, T c = 0, int p = -1)
  {
    if (p != -1)
    {
      par[v][0] = p;
    }
    dep[v] = d;
    costs[v] = c;
    for (auto i = 0u; i < to[v].size(); i++)
    {
      int u = to[v][i];
      if (u == p)
      {
        continue;
      }
      dfs(u, d + 1, c + co[v][i], v);
    }
  }
};

struct Edge
{
  int to, co, col;
  Edge(int to, int co, int col) : to{to}, co{co}, col{col} {}
};

struct Query
{
  int col, qid, coeff, y;
  Query(int col, int qid, int coeff, int y) : col{col}, qid{qid}, coeff{coeff}, y{y} {}
};

vector<Edge> es[100010];
vector<Query> qs[100010];
vector<ll> ans;
int cnt[100010];
ll sum[100010];

int N, Q;

void dfs(int v, int p = -1)
{
  for (auto q : qs[v])
  {
    ll x = -sum[q.col];
    x += (ll)q.y * cnt[q.col];
    ans[q.qid] += x * q.coeff;
  }
  for (auto e : es[v])
  {
    if (e.to == p)
    {
      continue;
    }
    cnt[e.col]++;
    sum[e.col] += e.co;
    dfs(e.to, v);
    cnt[e.col]--;
    sum[e.col] -= e.co;
  }
}

int main()
{
  cin >> N >> Q;
  LCA<ll> g(N);
  for (auto i = 0; i < N - 1; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a;
    --b;
    es[a].emplace_back(b, d, c);
    es[b].emplace_back(a, d, c);
    g.add_edge(a, b, d);
  }
  g.init(0);
  ans = vector<ll>(Q);
  for (auto i = 0; i < Q; i++)
  {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    --a;
    --b;
    int c = g(a, b);
    ans[i] = g.dist(a, b);
    qs[a].emplace_back(x, i, 1, y);
    qs[b].emplace_back(x, i, 1, y);
    qs[c].emplace_back(x, i, -2, y);
  }
  dfs(0);
  for (auto i = 0; i < Q; i++)
  {
    cout << ans[i] << endl;
  }
}