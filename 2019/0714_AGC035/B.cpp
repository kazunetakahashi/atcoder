#define DEBUG 1
/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 7/14/2019, 10:10:17 PM
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
int combination::MAX_SIZE = 1e6 + 10;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// const double epsilon = 1e-10;
// const ll infty = 1000000000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

int N, M;
using edge = tuple<int, int>;
using info = tuple<int, int>;
vector<int> pts;
set<edge> rev;
vector<int> W[100010];
set<int> V[100010];
vector<edge> ans;
bool visited[100010];
int cnt[100010];
priority_queue<info, vector<info>, greater<info>> Q;

void No()
{
  cout << "-1" << endl;
  exit(0);
}

void make_path(int v, int w)
{
  vector<int> from(N, -1);
  queue<info> P;
  P.push(info(-1, v));
  while (!P.empty())
  {
    int f = get<0>(P.front());
    int now = get<1>(P.front());
    P.pop();
    if (from[now] == -1)
    {
      from[now] = f;
      if (now == w)
      {
        break;
      }
      for (auto x : W[now])
      {
        if (from[x] == -1)
        {
          P.push(info(now, x));
        }
      }
    }
  }
  v = from[w];
  while (v != -1)
  {
    edge e = edge(v, w);
    edge f = edge(w, v);
    if (rev.find(e) == rev.end())
    {
      rev.insert(e);
      rev.insert(f);
    }
    else
    {
      rev.erase(e);
      rev.erase(f);
    }
    w = v;
    v = from[w];
  }
}

void make_rev()
{
  for (auto i = 0u; i < pts.size(); i += 2)
  {
    int v = pts[i];
    int w = pts[i + 1];
    make_path(v, w);
  }
}

void solve()
{
  for (auto i = 0; i < N; i++)
  {
    Q.push(info(V[i].size(), i));
  }
  while (!Q.empty())
  {
    // int sz = get<0>(Q.top());
    int v = get<1>(Q.top());
    Q.pop();
    if (!visited[v])
    {
      visited[v] = true;
      for (auto x : V[v])
      {
        ans.push_back(edge(x, v));
        cnt[x]++;
        V[x].erase(v);
        Q.push(info(V[x].size(), x));
      }
      auto ed = ans.end();
      auto it = ed - V[v].size();
      while (it != ed)
      {
        if (cnt[get<0>(*it)] % 2 == 1)
        {
          cnt[get<0>(*it)]--;
          cnt[get<1>(*it)]++;
          swap(get<0>(*it), get<1>(*it));
        }
        ++it;
      }
      if (cnt[v] % 2 == 0)
      {
        it--;
        cnt[get<0>(*it)]--;
        cnt[get<1>(*it)]++;
        swap(get<0>(*it), get<1>(*it));
      }
      V[v].clear();
    }
  }
}

void Yes()
{
  assert((int)ans.size() == M);
  vector<int> c(N, 0);
  for (auto x : ans)
  {
    c[get<0>(x)]++;
  }
  for (auto i = 0; i < N; i++)
  {
    if (c[i] % 2 == 1)
    {
      pts.push_back(i);
    }
  }
  if (!pts.empty())
  {
    make_rev();
  }
  for (auto x : ans)
  {
    if (rev.find(x) != rev.end())
    {
      swap(get<0>(x), get<1>(x));
    }
    cout << get<0>(x) + 1 << " " << get<1>(x) + 1 << endl;
  }
  exit(0);
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    V[a].insert(b);
    V[b].insert(a);
    W[a].push_back(b);
    W[b].push_back(a);
  }
  if (M % 2 == 1)
  {
    No();
  }
  solve();
  Yes();
}