#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 8/4/2019, 9:42:41 PM
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

int N, K;
vector<int> A;
int sum = 0;

bool ok(int P)
{
  vector<int> B;
  for (auto i = 0; i < N; i++)
  {
    int x = (A[i] - (A[i] / P) * P);
    if (x > 0)
    {
      B.push_back(x);
    }
  }
  if (B.empty())
  {
    return true;
  }
  sort(B.begin(), B.end());
#if DEBUG == 1
  for (auto x : B)
  {
    cerr << x << " ";
  }
  cerr << endl;
#endif
  int pos = accumulate(B.begin(), B.end(), 0);
  int neg = 0;
  if (pos % P == 0 && pos <= K)
  {
    return true;
  }
  for (auto i = (int)B.size() - 1; i >= 0; i--)
  {
    pos -= B[i];
    neg += P - B[i];
#if DEBUG == 1
    cerr << "pos = " << pos << ", neg = " << neg << endl;
#endif
    if (pos <= K && neg <= K)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    A.push_back(a);
  }
  sum = accumulate(A.begin(), A.end(), 0);
  vector<int> X;
  for (auto i = 1; i <= sum; i++)
  {
    if (sum % i == 0)
    {
      int a = i;
      int b = sum / i;
      X.push_back(a);
      X.push_back(b);
      if (b <= a)
      {
        break;
      }
    }
  }
  sort(X.begin(), X.end());
  reverse(X.begin(), X.end());
#if DEBUG == 1
  cerr << "sum = " << sum << endl;
#endif
  for (auto x : X)
  {
#if DEBUG == 1
    cerr << "x = " << x << endl;
#endif
    if (ok(x))
    {
      cout << x << endl;
      return 0;
    }
  }
  assert(false);
}