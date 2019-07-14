#define DEBUG 1
/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 7/15/2019, 3:17:20 AM
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

using edge = tuple<int, int>;
vector<edge> ans;

void Yes()
{
  cout << "Yes" << endl;
  for (auto e : ans)
  {
    cout << get<0>(e) << " " << get<1>(e) << endl;
  }
  exit(0);
}
void No()
{
  cout << "No" << endl;
  exit(0);
}
int N;

void add_edge(int a, int b)
{
  ans.push_back(edge(a, b));
}

void solve()
{
  add_edge(N + 1, N + 2);
  add_edge(N + 2, 3);
  add_edge(3, 1);
  add_edge(1, 2);
  add_edge(2, 3 + N);
  for (auto i = 4; i + 1 <= N; i += 2)
  {
    add_edge(1, i);
    add_edge(i, i + 1 + N);
    add_edge(1, i + 1);
    add_edge(i + 1, i + N);
  }
  if (N % 2 == 0)
  {
    int a = -1;
    for (auto i = 30; i >= 0; i--)
    {
      if (N >> i & 1)
      {
        a = (1 << i);
        break;
      }
    }
    assert(a != -1);
    int b = N - a;
    add_edge(N, a);
    add_edge(b, N + N);
  }
}

int main()
{
  cin >> N;
  if (N <= 2)
  {
    No();
  }
  for (auto i = 0; i < 30; i++)
  {
    if (N == (1 << i))
    {
      No();
    }
  }
  solve();
  Yes();
}