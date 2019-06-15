#define DEBUG 1
/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 6/15/2019, 9:46:28 PM
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
  mint operator-() const { return mint(0) - *this; }
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

ll N;
ll X[2][3];
ll ans;

typedef tuple<ll, ll, ll, ll> state;
typedef vector<int> sat;

state change_G(state x, sat V, int t)
{
  ll n, g, s, b;
  tie(n, g, s, b) = x;
  for (auto e : V)
  {
    if (e == 3)
    {
      break;
    }
    else if (e == 0)
    {
      g += n / X[t][e];
      n %= X[t][e];
    }
    else if (e == 1)
    {
      s += n / X[t][e];
      n %= X[t][e];
    }
    else if (e == 2)
    {
      b += n / X[t][e];
      n %= X[t][e];
    }
  }
  return tie(n, g, s, b);
}

state change_N(state x, sat V, int t)
{
  ll n, g, s, b;
  tie(n, g, s, b) = x;
  for (auto e : V)
  {
    if (e == 3)
    {
      break;
    }
    else if (e == 0)
    {
      n += X[t][e] * g;
      g = 0;
    }
    else if (e == 1)
    {
      n += X[t][e] * s;
      s = 0;
    }
    else if (e == 2)
    {
      n += X[t][e] * b;
      b = 0;
    }
  }
  return tie(n, g, s, b);
}

vector<sat> W;

int main()
{
  cin >> N;
  ans = N;
  cin >> X[0][0] >> X[0][1] >> X[0][2];
  cin >> X[1][0] >> X[1][1] >> X[1][2];
  int alpha[4] = {0, 1, 2, 3};
  do
  {
    sat V;
    for (auto i = 0; i < 4; i++)
    {
      V.push_back(alpha[i]);
    }
    W.push_back(V);
  } while (next_permutation(alpha, alpha + 4));
  for (auto e0 : W)
  {
    state x = state(ans, 0, 0, 0);
    x = change_G(x, e0, 0);
    x = change_N(x, W[0], 1);
#if DEBUG == 1
    if (get<0>(x) > ans)
    {
      cerr << get<0>(x) << endl;
    }
#endif
    maxs(ans, get<0>(x));
  }
  for (auto e2 : W)
  {
    state x = state(ans, 0, 0, 0);
    x = change_G(x, e2, 1);
    x = change_N(x, W[0], 0);
    maxs(ans, get<0>(x));
  }
  cout << ans << endl;
}
