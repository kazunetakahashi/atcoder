#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 7/20/2019, 10:15:22 PM
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
int combination::MAX_SIZE = 1e6 + 10;
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

int N, K;

int calc(const vector<int> &V)
{
  int ans = 0;
  for (auto i = 0; i < N; i++)
  {
    ans += abs(V[i] - i);
  }
  return ans;
}

vector<int> maxi_strange()
{
  vector<int> V;
  vector<bool> used(N, false);
  for (auto k = 0; k < N; k++)
  {
    int mini = 0, maxi = N - 1;
    for (auto i = 0; i < N; i++)
    {
      if (!used[i])
      {
        mini = i;
        break;
      }
    }
    for (auto i = N - 1; i >= 0; i--)
    {
      if (!used[i])
      {
        maxi = i;
        break;
      }
    }
    while (abs(maxi - mini) > 1)
    {
      int t = (maxi + mini) / 2;
      vector<int> W = V;
      vector<bool> used_t = used;
      W.push_back(t);
      used_t[t] = true;
      for (auto i = 0; i < N; i++)
      {
        if (!used_t[i])
        {
          W.push_back(i);
        }
      }
      if (calc(W) <= K)
      {
        mini = t;
      }
      else
      {
        maxi = t;
      }
    }
    used[mini] = true;
    V.push_back(mini);
  }
  return V;
}

vector<int> mini_strange()
{
  vector<int> V;
  vector<bool> used(N, false);
  for (auto k = 0; k < N; k++)
  {
    int mini = 0, maxi = N - 1;
    for (auto i = 0; i < N; i++)
    {
      if (!used[i])
      {
        mini = i;
        break;
      }
    }
    for (auto i = N - 1; i >= 0; i--)
    {
      if (!used[i])
      {
        maxi = i;
        break;
      }
    }
    while (abs(maxi - mini) > 1)
    {
      int t = (maxi + mini) / 2;
      vector<int> W = V;
      vector<bool> used_t = used;
      W.push_back(t);
      used_t[t] = true;
      for (auto i = N - 1; i >= 0; i--)
      {
        if (!used_t[i])
        {
          W.push_back(i);
        }
      }
      if (calc(W) >= K)
      {
        maxi = t;
      }
      else
      {
        mini = t;
      }
    }
    used[maxi] = true;
    V.push_back(maxi);
  }
  return V;
}

int main()
{
  cin >> N >> K;
  auto V = maxi_strange();
  auto W = mini_strange();
#if DEBUG == 1
  for (auto x : V)
  {
    cerr << x << " ";
  }
  cerr << endl;
#endif
#if DEBUG == 1
  for (auto x : W)
  {
    cerr << x << " ";
  }
  cerr << endl;
#endif
}