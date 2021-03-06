#define DEBUG 1
/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-29 22:23:01
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

ll N, K;
ll X;
mint dp[100010][100];
mint dp_sum[100010][100];
mint dp2[100010][100];
mint dp2_sum[100010][100];
mint cnt[100010];

int main()
{
  // init();
  cin >> N >> K;
  int C = -1;
  X = sqrt(N) + 10;
  for (auto i = 1; i <= X; i++)
  {
    ll ub = max(N / i, X);
    ll lb = max(N / (i + 1), X);
    cnt[i] = ub - lb;
    if (ub == X && lb == X)
    {
      C = i;
      break;
    }
  }
#if DEBUG == 1
  cerr << "X = " << X << endl;
  cerr << "C = " << C << endl;
#endif
  dp[1][0] = 1;
  for (auto t = 0; t < K; t++)
  {
#if DEBUG == 1
    cerr << "t = " << t << endl;
#endif
    for (auto i = 1; i <= X; i++)
    {
      dp_sum[i][t] += dp[i][t] + dp_sum[i - 1][t];
    }
    for (auto i = 1; i <= C; i++)
    {
      dp2_sum[i][t] += dp2[i][t] + dp2_sum[i - 1][t];
    }
    for (auto j = 1; j <= X; j++)
    {
      dp[j][t + 1] += dp_sum[min(X, N / j)][t];
      dp2[j][t + 1] += cnt[j] * dp_sum[j][t];
    }
    for (auto j = 1; j < C; j++)
    {
      dp[j][t + 1] += dp2_sum[C - 1][t] - dp2_sum[j - 1][t];
    }
  }
  mint ans = 0;
  for (auto i = 1; i <= X; i++)
  {
    ans += dp[i][K];
  }
  for (auto i = 1; i < C; i++)
  {
    ans += dp2[i][K];
  }
  cout << ans << endl;
}