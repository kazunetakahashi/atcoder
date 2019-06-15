#define DEBUG 1
/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 6/15/2019, 9:15:16 PM
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
  mint operator-() const { return mint(0) - *this; }
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
ll A[100010];

void solve()
{
  int ind = 0;
  for (auto i = 0; i < N; i++)
  {
    if (A[i] > 0)
    {
      ind = i;
      break;
    }
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    ans += abs(A[i]);
  }
  cout << ans << endl;
  ll now = A[0];
  for (auto i = ind; i < N - 1; i++)
  {
    cout << now << " " << A[i] << endl;
    now -= A[i];
  }
  ll now2 = A[N - 1];
  for (auto i = 1; i < ind; i++)
  {
    cout << now2 << " " << A[i] << endl;
    now2 -= A[i];
  }
  cout << now2 << " " << now << endl;
}

void solve_plus()
{
  ll ans = -A[0];
  for (auto i = 1; i < N; i++)
  {
    ans += abs(A[i]);
  }
  cout << ans << endl;
  ll now = A[0];
  for (auto i = 1; i < N - 1; i++)
  {
    cout << now << " " << A[i] << endl;
    now -= A[i];
  }
  cout << A[N - 1] << " " << now << endl;
}

void solve_minus()
{
  ll ans = A[N - 1];
  for (auto i = 0; i < N; i++)
  {
    ans += abs(A[i]);
  }
  cout << ans << endl;
  ll now = A[N - 1];
  for (auto i = 0; i < N - 1; i++)
  {
    cout << now << " " << A[i] << endl;
    now -= A[i];
  }
}

int main()
{
  // init();
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sort(A, A + N);
  if (A[0] > 0)
  {
    solve_plus();
  }
  else if (A[N - 1] < 0)
  {
    solve_minus();
  }
  else
  {
    solve();
  }
}