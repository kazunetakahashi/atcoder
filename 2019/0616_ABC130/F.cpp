#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/16/2019, 10:20:01 PM
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
const ll infty = 1000000000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

int N;
vector<ll> x;
vector<ll> y;

vector<ll> U, D, L, R;

double X[4][3];

double Z(int x, double t)
{
  if (x % 2 == 0)
  {
    return max(X[x][0], max(X[x][1] + t, X[x][2] - t));
  }
  else
  {
    return min(X[x][0], min(X[x][1] + t, X[x][2] - t));
  }
}

double S(double t)
{
  return (Z(0, t) - Z(1, t)) * (Z(2, t) - Z(3, t));
}

int main()
{
  // init();
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    ll p, q;
    char c;
    cin >> p >> q >> c;
    if (c == 'R' || c == 'L')
    {
      y.push_back(q);
      if (c == 'R')
      {
        R.push_back(p);
      }
      else
      {
        L.push_back(p);
      }
    }
    else
    {
      x.push_back(p);
      if (c == 'U')
      {
        U.push_back(q);
      }
      else
      {
        D.push_back(q);
      }
    }
  }
  X[0][0] = *max_element(x.begin(), x.end());
  X[0][1] = *max_element(U.begin(), U.end());
  X[0][2] = *max_element(D.begin(), D.end());
  X[1][0] = *min_element(x.begin(), x.end());
  X[1][1] = *min_element(U.begin(), U.end());
  X[1][2] = *min_element(D.begin(), D.end());
  X[2][0] = *max_element(y.begin(), y.end());
  X[2][1] = *max_element(R.begin(), R.end());
  X[2][2] = *max_element(L.begin(), L.end());
  X[3][0] = *min_element(y.begin(), y.end());
  X[3][1] = *min_element(R.begin(), R.end());
  X[3][2] = *min_element(L.begin(), L.end());
  double r = infty;
  double l = 0;
  for (auto i = 0; i < 1000; i++)
  {
    double s = (2 * r + l) / 3;
    double t = (r + 2 * l) / 3;
    ll A = S(s);
    ll B = S(t);
    if (A > B)
    {
      r = t;
    }
    else
    {
      l = t;
    }
  }
  cout << fixed << setprecision(12) << S(r) << endl;
}