#define DEBUG 1
/**
 * File    : B2.cpp
 * Author  : Kazune Takahashi
 * Created : 7/22/2019, 3:04:34 AM
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

void doubling(ll N, const vector<int> &A, vector<vector<ll>> &a)
{
  vector<int> used(200010, -1);
  for (auto k = 0; k < 2; k++)
  {
    for (auto i = 0; i < N; i++)
    {
      if (used[A[i]] != -1)
      {
        a[0][used[A[i]] % N] = k * N + i - used[A[i]] + 1;
      }
      used[A[i]] = k * N + i;
    }
  }
  for (auto k = 1; k < 60; k++)
  {
    for (auto i = 0; i < N; i++)
    {
      a[k][i] = a[k - 1][i] + a[k - 1][(a[k - 1][i] + i) % N];
    }
  }
}

ll calc_start(ll N, ll K, const vector<vector<ll>> &a)
{
  ll sum = 0;
  ll now = 0;
  const ll C = N * K;
  while (true)
  {
    int ind = 0;
    for (auto k = 0; k < 60; k++)
    {
      if (a[k][now] + sum >= C)
      {
        ind = k - 1;
        break;
      }
    }
    if (ind == -1)
    {
      break;
    }
    sum += a[ind][now];
    now = sum % N;
  }
  return now;
}

deque<int> last_state(ll start, ll N, const vector<int> &A)
{
  deque<int> D;
  vector<bool> stacked(200010, false);
  for (auto i = start; i < N; i++)
  {
    if (!stacked[A[i]])
    {
      D.push_back(A[i]);
      stacked[A[i]] = true;
    }
    else
    {
      while (true)
      {
        int x = *D.rbegin();
        D.pop_back();
        stacked[x] = false;
        if (x == A[i])
        {
          break;
        }
      }
    }
  }
  return D;
}

void flush(const deque<int> &D)
{
  for (auto i = 0u; i < D.size(); i++)
  {
    cout << D[i];
    if (i < D.size() - 1)
    {
      cout << " ";
    }
  }
  cout << endl;
}

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  vector<vector<ll>> a(60, vector<ll>(N));
  doubling(N, A, a);
  ll start = calc_start(N, K, a);
  deque<int> D = last_state(start, N, A);
  flush(D);
}