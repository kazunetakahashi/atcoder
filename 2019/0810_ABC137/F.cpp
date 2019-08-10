#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 8/10/2019, 9:27:29 PM
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

typedef vector<mint> Poly;

ostream &operator<<(ostream &o_str, const Poly &p)
{
  o_str << "{ ";
  for (auto i = 0u; i < p.size(); i++)
  {
    o_str << p[i];
    if (i < p.size() - 1)
    {
      o_str << ", ";
    }
  }
  return o_str << " }";
}

void reduce(Poly &v)
{
  while (!v.empty() && v.back() == 0)
  {
    v.pop_back();
  }
}

bool is_zero(Poly p)
{
  reduce(p);
  return p.empty();
}

Poly operator+(Poly p, Poly q)
{
  reduce(p);
  reduce(q);
  if (p.size() < q.size())
  {
    return q + p;
  }
  else
  {
    for (auto i = 0; i < (int)q.size(); i++)
    {
      p[i] += q[i];
    }
  }
  reduce(p);
  return p;
}

Poly operator-(Poly p)
{
  reduce(p);
  for (auto i = 0; i < (int)p.size(); i++)
  {
    p[i] = -p[i];
  }
  reduce(p);
  return p;
}

Poly operator-(Poly p, Poly q)
{
  return p + (-q);
}

Poly operator*(Poly p, Poly q)
{
  reduce(p);
  reduce(q);
  if (is_zero(p) || is_zero(q))
  {
    return {};
  }
  Poly ans(p.size() + q.size() - 1, 0);
  for (auto k = 0u; k < ans.size(); k++)
  {
    for (auto i = 0u; i <= k; i++)
    {
      auto j = k - i;
      if (i < p.size() && j < q.size())
      {
        ans[k] += p[i] * q[j];
      }
    }
  }
  reduce(ans);
  return ans;
}

Poly operator*(Poly p, mint v)
{
  reduce(p);
  for (auto &x : p)
  {
    x *= v;
  }
  return p;
}

Poly operator*(mint v, Poly p)
{
  return p * v;
}

void flush(Poly p)
{
  while ((ll)p.size() < mint::MOD)
  {
    p.push_back(0);
  }
  for (auto i = 0; i < mint::MOD; i++)
  {
    cout << p[i];
    if (i < mint::MOD - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
}

mint eval(Poly p, mint v)
{
  reduce(p);
  mint x = 1;
  mint ans = 0;
  for (auto b : p)
  {
    ans += b * x;
    x *= v;
  }
  return ans;
}

Poly one(mint k)
{
  return {-k, 1};
}

int main()
{
  cin >> mint::MOD;
  combination C{};
  vector<ll> W;
  for (auto i = 0LL; i < mint::MOD; i++)
  {
    int a;
    cin >> a;
    if (a == 1)
    {
      W.push_back(i);
    }
  }
  Poly ans = {};
  for (auto e : W)
  {
    Poly base = {1};
    for (auto i = 0LL; i < mint::MOD; ++i)
    {
      if (i != e)
      {
        base = base * one(i);
      }
    }
#if DEBUG == 1
    cerr << "e = " << e << endl;
    cerr << base << endl;
#endif
    mint rev = eval(base, e);
    rev = C.inv[rev.x];
    base = base * rev;
    base = base * one(e);
#if DEBUG == 1
    cerr << base << endl;
#endif
    ans = ans + base;
  }
  flush(ans);
}