#define DEBUG 1
/**
 * File    : E2.cpp
 * Author  : Kazune Takahashi
 * Created : 7/27/2019, 11:59:18 PM
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

using point = tuple<ll, ll>;

ll K, X, Y;

vector<point> calc()
{
  if (X + Y == K)
  {
    return {point(X, Y)};
  }
  int N = (X + Y + K - 1) / K;
  if (N <= 1)
  {
    ++N;
  }
  if ((X + Y) % 2 != N * K % 2)
  {
    ++N;
  }
  vector<point> ans(N);
  if (N == 3 && X < K)
  {
    ll P = (K + X - Y) / 2;
    ans[0] = point(X, -(K - X));
    ans[1] = point(X + P, Y - (K - P));
    ans[2] = point(X, Y);
  }
  else
  {
    int over = (K * N - (X + Y)) / 2;
    for (auto i = 0; i < N; i++)
    {
      int dist = (i + 1) * K;
      if (dist <= Y + over)
      {
        ans[i] = point(0, dist);
      }
      else if (dist <= Y + over + X)
      {
        ans[i] = point(dist - Y - over, Y + over);
      }
      else
      {
        ans[i] = point(X, Y + (N - (i + 1)) * K);
      }
    }
  }
  return ans;
}

void Yes()
{
  bool x_f = false;
  bool y_f = false;
  bool swapped = false;
  if (X < 0)
  {
    X = -X;
    x_f = true;
  }
  if (Y < 0)
  {
    Y = -Y;
    y_f = true;
  }
  if (Y > X)
  {
    swap(X, Y);
    swapped = true;
  }
  vector<point> ans = calc();
  if (x_f)
  {
    for (auto &e : ans)
    {
      get<0>(e) *= -1;
    }
  }
  if (y_f)
  {
    for (auto &e : ans)
    {
      get<1>(e) *= -1;
    }
  }
  if (swapped)
  {
    for (auto &e : ans)
    {
      swap(get<0>(e), get<1>(e));
    }
  }
  cout << ans.size() << endl;
  for (auto &e : ans)
  {
    cout << get<0>(e) << " " << get<1>(e) << endl;
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