#define DEBUG 1
/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 6/17/2019, 12:34:53 AM
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
const ll infty = 10000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

int N;

class D
{
public:
  vector<double> l, r;
  D() : l(3, infty), r(3, -infty) {}
  void add(double x, int v)
  {
    ++v;
    mins(l[v], x);
    maxs(r[v], x);
  }
  double get(double t)
  {
    double nl = infty, nr = -infty;
    for (auto i = 0; i < 3; i++)
    {
      mins(nl, l[i] + i * t);
      maxs(nr, r[i] + i * t);
    }
    return nr - nl;
  }
  vector<double> events()
  {
    vector<double> ts;
    for (auto i = 0; i < 3; i++)
    {
      for (auto j = 0; j < i; j++)
      {
        double t = (l[j] - l[i]) / (i - j);
        if (t > 0)
        {
          ts.push_back(t);
        }
        t = (r[j] - r[i]) / (i - j);
        if (t > 0)
        {
          ts.push_back(t);
        }
      }
    }
  }
};

int main()
{
  // init();
  cin >> N;
  D xd, yd;
  for (auto i = 0; i < N; i++)
  {
    int x, y;
    char d;
    cin >> x >> y >> d;
    if (d == 'L')
    {
      xd.add(x, -1);
      yd.add(y, 0);
    }
    if (d == 'R')
    {
      xd.add(x, 1);
      yd.add(y, 0);
    }
    if (d == 'U')
    {
      xd.add(x, 0);
      yd.add(y, 1);
    }
    if (d == 'D')
    {
      xd.add(x, 0);
      yd.add(y, -1);
    }
  }
  vector<double> ts;
  ts.push_back(0);
  ts.push_back(infty);
  {
    auto nts = xd.events();
    ts.insert(ts.end(), nts.begin(), nts.end());
  }
  {
    auto nts = yd.events();
    ts.insert(ts.end(), nts.begin(), nts.end());
  }
  double ans = 100000000000000000;
  for (auto t : ts)
  {
    double now = xd.get(t) * yd.get(t);
    mins(ans, now);
  }
}