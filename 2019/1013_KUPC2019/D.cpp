#define DEBUG 1
/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/10/13 13:55:01
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
template <typename T>
void ch_max(T &left, T right)
{
  if (left < right)
  {
    left = right;
  }
}
template <typename T>
void ch_min(T &left, T right)
{
  if (left > right)
  {
    left = right;
  }
}
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
ll mint::MOD = 998244353;
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

using info = tuple<vector<int>, vector<int>>;

void all(int N)
{
  vector<int> V(2 * N);
  for (auto i = 0; i < 2 * N; i++)
  {
    V[i] = i;
  }
  int cnt{0};
  set<info> S;
  do
  {
    vector<int> X, Y;
    for (auto i = 0; i < N; i++)
    {
      X.push_back(V[i]);
      Y.push_back(V[i + N]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    bool ok = true;
    for (auto i = 0; i < N; i++)
    {
      if (X[i] > Y[i])
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      info F = info(X, Y);
      if (S.find(F) == S.end())
      {
        for (auto i = 0; i < N; i++)
        {
          cerr << X[i];
        }
        cerr << endl;
        for (auto i = 0; i < N; i++)
        {
          cerr << Y[i];
        }
        cerr << endl;
        ++cnt;
        S.insert(F);
      }
    }
  } while (next_permutation(V.begin(), V.end()));
  cerr << "cnt = " << cnt << endl;
}

combination C;

mint catalan(ll n)
{
  return C(2 * n, n) * C.inv[n + 1];
}

int main()
{
  int N;
  string S;
  cin >> N >> S;
  mint ans{1};
  vector<ll> X;
  char c = S[0];
  ll now = 0;
  for (auto x : S)
  {
    if (c == x)
    {
      now++;
    }
    else
    {
      X.push_back(now);
      now = 1;
      c = x;
    }
  }
  X.push_back(now);
  for (auto x : X)
  {
    ans *= catalan(x);
  }
  cout << ans << endl;
}