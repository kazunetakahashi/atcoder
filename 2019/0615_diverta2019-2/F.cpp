#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/16/2019, 1:52:04 AM
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
// const ll infty = 1000000000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

int N;
ll w[10][10];
int X[10];
vector<ll> V;
unordered_set<int> H;

void make_vector()
{
  for (auto i = 0; i < N; i++)
  {
#if DEBUG == 1
    cerr << "aaa" << endl;
#endif
    ll mini = *max_element(V.begin(), V.end()) + 1;
#if DEBUG == 1
    cerr << "mini = " << mini << endl;
#endif
    for (auto i = mini;; i++)
    {
      if (H.find(i) != H.end())
      {
        continue;
      }
      for (auto &x : V)
      {
        if (H.find(x + i) != H.end())
        {
          continue;
        }
      }
      V.push_back(i);
#if DEBUG == 1
      cerr << "insert: " << i << endl;
#endif
      H.insert(i);
      for (auto &x : V)
      {
        H.insert(x + i);
      }
      break;
    }
  }
}

ll hamilton_path(int K)
{
  ll ans = 0;
  for (auto i = 0; i < K; i++)
  {
    X[i] = i;
  }
  do
  {
    ll t = 0;
    for (auto i = 0; i < K - 1; i++)
    {
      t += w[X[i]][X[i + 1]];
    }
    maxs(ans, t);
  } while (next_permutation(X, X + K));
  return ans;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    w[i][i] = 0;
  }
  make_vector();
  for (auto i = 1; i < N; i++)
  {
    ll M = hamilton_path(i) + 1;
    for (auto j = 0; j < i; j++)
    {
      w[i][j] = w[j][i] = M * V[j];
    }
  }
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cout << w[i][j];
      if (j < N - 1)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }
}