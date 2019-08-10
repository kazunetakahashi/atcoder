#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 8/11/2019, 12:51:25 AM
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
constexpr ll infty = 1000000000000000LL;
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

using edge = tuple<ll, ll, ll>;

vector<int> V[2510];
vector<int> W[2510];
bool visit_zero[2510];
bool visit_N[2510];

void dfs(int k, bool *visit, vector<int> *v)
{
  if (!visit[k])
  {
    visit[k] = true;
    for (auto x : v[k])
    {
      if (!visit[x])
      {
        dfs(x, visit, v);
      }
    }
  }
}

int main()
{
  int N, M;
  ll P;
  cin >> N >> M >> P;
  vector<edge> E;
  for (auto i = 0; i < N; i++)
  {
    int A, B;
    ll C;
    cin >> A >> B >> C;
    --A;
    --B;
    C = -(C - P);
    E.emplace_back(A, B, C);
    V[A].push_back(B);
    W[B].push_back(A);
  }
  dfs(0, visit_zero, V);
  dfs(N - 1, visit_N, W);
  vector<bool> ok(N);
  for (auto i = 0; i < N; i++)
  {
    ok[i] = visit_zero[i] && visit_N[i];
#if DEBUG == 1
    if (ok[i])
    {
      cerr << "ok[" << i << "]" << endl;
    }
#endif
  }
  vector<ll> d(N, infty);
  d[0] = 0;
  bool updated{true};
  int step{0};
  while (updated)
  {
    updated = false;
    for (auto i = 0; i < M; i++)
    {
      int A, B;
      ll C;
      tie(A, B, C) = E[i];
      if (!ok[A] || !ok[B])
      {
        continue;
      }
      ll t = d[A] + C;
      if (t < d[B])
      {
        updated = true;
        d[B] = t;
      }
    }
    ++step;
    if (step > N)
    {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << max(0LL, -d[N - 1]) << endl;
}