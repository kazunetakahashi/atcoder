/**
 * File    : T.cpp
 * Author  : Kazune Takahashi
 * Created : 2/4/2019, 11:51:23 AM
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <numeric>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/tdpc/submissions/4169434 を参考にする。

typedef vector<ll> Poly;

ll mod_power(ll x, ll k)
{
  if (k == 0)
  {
    return 1;
  }
  if (k % 2 == 0)
  {
    ll t = mod_power(x, k / 2);
    return (t * t) % MOD;
  }
  return (mod_power(x, k - 1) * x) % MOD;
}

ll mod_rev(ll x)
{
  return mod_power(x, MOD - 2);
}

void reduce(Poly &v)
{
  while (!v.empty() && v.back() % MOD != 0)
  {
    v.pop_back();
  }
}

Poly X_k(int k, ll a)
{
  vector<ll> p(k + 1, 0);
  p[k] = a % MOD;
  return p;
}

Poly X_k(int k)
{
  vector<ll> p(k + 1, 0);
  p[k] = 1;
  return p;
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
      p[i] %= MOD;
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
    p[i] %= MOD;
    p[i] = MOD - p[i];
    p[i] %= MOD;
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
  Poly res(p.size() + q.size() - 1, 0);
  for (auto i = 0; i < (int)res.size(); i++)
  {
    for (auto j = 0; j <= i; j++)
    {
      if (j < (int)p.size() && i - j < (int)q.size())
      {
        res[i] += (p[j] * q[i - j]) % MOD;
        res[i] %= MOD;
      }
    }
  }
  reduce(res);
  return res;
}

Poly operator*(Poly p, ll k)
{
  reduce(p);
  Poly res(p.size());
  for (auto i = 0; i < (int)p.size(); i++)
  {
    res[i] = (p[i] * k) % MOD;
  }
  reduce(res);
  return res;
}

Poly operator*(ll k, Poly p)
{
  return p * k;
}

Poly monic(Poly p)
{
  reduce(p);
  if (is_zero(p))
  {
    return p;
  }
  ll m = p.back();
  ll rev_m = mod_rev(m);
  return rev_m * p;
}

bool is_monic(const Poly &p)
{
  return (p.back() == 1);
}

Poly shift(Poly &p, int k)
{
  reduce(p);
  Poly res(p.size() + k);
  for (auto i = 0; i < k; i++)
  {
    res[i] = 0;
  }
  for (auto i = k; i < (int)res.size(); i++)
  {
    res[i] = p[i - k];
  }
  return res;
}

Poly operator%(Poly p, Poly q)
{
  reduce(p);
  reduce(q);
  if (p.size() < q.size())
  {
    return p;
  }
  if (!is_monic(q))
  {
    return p % monic(q);
  }
  Poly s_q = shift(q, p.size() - q.size());
  Poly res = (p - p.back() * s_q);
  reduce(res);
  return res % q;
}

Poly mod_power(Poly q, ll k)
{
  if (k == 0)
  {
    return {1};
  }
  if (k % 2 == 0)
  {
    Poly t = mod_power(q, k / 2);
    return (t * t) % q;
  }
  return (mod_power(q, k - 1) * X_k(1)) % q;
}

ll K, N;
Poly k;
vector<ll> a;

int main()
{
  cin >> K >> N;
  if (N <= K)
  {
    cout << 1 << endl;
    return 0;
  }
  k = Poly(K + 1);
  for (auto i = 0; i < K; i++)
  {
    k[i] = 1;
  }
  k[K] = 1;
  a = vector<ll>(2 * K - 1);
  for (auto i = 0; i < K; i++)
  {
    a[i] = 1;
  }
  for (auto i = K; i < 2 * K - 1; i++)
  {
    a[i] = 0;
    for (auto j = 0; j < K; j++)
    {
      a[i] += (a[i - 1 - j] * k[K - 1 - j]) % MOD;
      a[i] %= MOD;
    }
  }
  cerr << "aaa" << endl;
  for (auto i = 0; i < K; i++)
  {
    k[i] = MOD - k[i];
    k[i] %= MOD;
  }
  Poly f = mod_power(k, N - 1 - K);
  ll ans = 0;
  for (auto i = 0; i < min(K, (ll)f.size()); i++)
  {
    ans += f[i] * a[K - 1 + i];
    ans %= MOD;
  }
  cout << ans << endl;
}