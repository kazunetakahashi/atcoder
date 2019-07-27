#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 7/27/2019, 9:24:13 PM
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

ll K;
ll X, Y;

class point
{
public:
  ll x, y;

  point(ll _x, ll _y) : x{_x}, y{_y} {}

  bool valid()
  {
    return (x + y) % 2 == 0;
  }

  ostream &flush(ostream &os)
  {
    assert(valid());
    return os << (x + y) / 2 << " " << (y - x) / 2 << endl;
  }

  void add(ll _x, ll _y)
  {
    assert(abs(_x) == K || abs(_y) == K);
    assert((_x + _y) % 2 == 0);
    x += _x;
    y += _y;
  }
};

vector<ll> make_cat(ll k)
{
  if (k == 0)
  {
    return {};
  }
  ll sgn = (k > 0) ? 1 : -1;
  k *= sgn;
  vector<ll> ans = {k % K};
  for (auto i = 0; i < k / K; i++)
  {
    ans.push_back(K);
  }
  for (auto &x : ans)
  {
    x *= sgn;
  }
  return ans;
}

vector<point> make_vec()
{
  vector<ll> A = make_cat(X + Y);
  vector<ll> B = make_cat(X - Y);
}

void Yes()
{
  assert(false);
  vector<point> V = make_vec();
  cout << V.size() << endl;
  for (auto x : V)
  {
    x.flush(cout);
  }
  exit(0);
}
void No()
{
  cout << "-1" << endl;
  exit(0);
}

bool judge()
{
  return ((K % 2 == 1) || ((X + Y) % 2 == 0));
}

int main()
{
  cin >> K >> X >> Y;
  if (judge())
  {
    Yes();
  }
  No();
}