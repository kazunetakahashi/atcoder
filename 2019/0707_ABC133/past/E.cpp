#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 7/7/2019, 9:44:50 PM
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

  combination()
  {
    inv = vector<mint>(MAX_SIZE);
    fact = vector<mint>(MAX_SIZE);
    factinv = vector<mint>(MAX_SIZE);
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

ll N, K;
vector<int> V[100010];
vector<int> children[100010];
bool visited[100010];

void dfs(int n)
{
  if (!visited[n])
  {
    visited[n] = true;
    for (auto x : V[n])
    {
      if (!visited[x])
      {
        children[n].push_back(x);
        dfs(x);
      }
    }
  }
}

int main()
{
  combination C{};
  cin >> N >> K;
  for (auto i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  dfs(0);
  queue<int> Q;
  Q.push(0);
  mint ans = K;
  while (!Q.empty())
  {
    int n = Q.front();
    Q.pop();
    ll child = children[n].size();
    ll D = K - 1;
    if (n != 0)
    {
      D--;
    }
#if DEBUG == 1
    cerr << "n = " << n << ", D = " << D << ", child = " << child << endl;
#endif
    ans *= C(D, child) * C.fact[child];
    for (auto x : children[n])
    {
      Q.push(x);
    }
  }
  cout << ans << endl;
}