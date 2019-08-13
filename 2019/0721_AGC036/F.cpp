#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 8/13/2019, 5:50:27 PM
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
constexpr double epsilon = 1e-10;
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

struct Element
{
  mint val;
  mint c;
  int ind;
  int ind_a;
  bool is_a;

  Element() {}
  Element(int i, mint v) : val{v}, ind{i}, is_a{true} {}
  Element(int i, mint v, mint _c) : val{v}, c{_c}, ind{i}, is_a{false} {}

  bool operator<(Element const &l) const
  {
    if (val == l.val)
    {
      return ind < l.ind;
    }
    return val < l.val;
  }
};

vector<Element> make_elements(ll N)
{
  vector<Element> res(2 * N);
  // make_A
  for (auto i = 0LL; i < N; i++)
  {
    ll X = sqrt(4 * N * N - (i + N) * (i + N)) + epsilon;
    res[i] = Element(N - 1 - i, X + 1);
  }
  // make_B
  for (auto i = 0LL; i < N; i++)
  {
    ll X = sqrt(4 * N * N - i * i) + epsilon;
    ll Y = sqrt(N * N - i * i) + epsilon;
    res[i + N] = Element(N - 1 - i, Y + 1, X + 1);
  }
  sort(res.begin(), res.end());
  // calc ind_a;
  ll now{0};
  for (auto i = 0LL; i < 2 * N; i++)
  {
    res[i].ind_a = now;
    if (res[i].is_a)
    {
      ++now;
    }
  }
  return res;
}

mint solve(ll N, vector<Element> const &V, ll k)
{
  vector<vector<mint>> dp(2 * N + 1, vector<mint>(2 * N + 1, 0));
  dp[0][0] = 1;
  for (auto x = 0; x < 2 * N; x++)
  {
    for (auto y = 0; y <= x; y++)
    {
      if (dp[x][y] == 0)
      {
        continue;
      }
      if (V[x].is_a)
      {
        dp[x + 1][y] += dp[x][y] * (V[x].val - V[x].ind_a - y);
      }
      else
      {
        dp[x + 1][y + 1] += dp[x][y] * (V[x].val - V[x].ind_a - y);
        dp[x + 1][y] += dp[x][y] * (V[x].c - N - k - (V[x].ind - y));
      }
    }
  }
  return dp[2 * N][k];
}

int main()
{
  ll N;
  cin >> N >> mint::MOD;
  vector<Element> V{make_elements(N)};
#if DEBUG == 1
  if (N < 100)
  {
    for (auto i = 0; i < 2 * N; i++)
    {
      cerr << "V[" << i << "] = ";
      if (V[i].is_a)
      {
        cerr << "a[" << V[i].ind << "] = " << V[i].val;
      }
      else
      {
        cerr << "b[" << V[i].ind << "] = " << V[i].val << ", c[" << V[i].ind << "] = " << V[i].c;
      }
      cerr << ", ind_a = " << V[i].ind_a << endl;
    }
  }
#endif
  mint ans{0};
  for (auto k = 0LL; k <= N; k++)
  {
    if (k % 2)
    {
      ans -= solve(N, V, k);
    }
    else
    {
      ans += solve(N, V, k);
    }
  }
  cout << ans << endl;
}