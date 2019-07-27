#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 7/28/2019, 1:18:49 AM
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
  cout << "-1" << endl;
  exit(0);
}

class UnionFind
{
  vector<long long> par;

public:
  UnionFind() {}
  UnionFind(int n) : par(n, -1) {}

  bool is_same(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
    {
      return false;
    }
    if (par[x] > par[y])
    {
      swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  long long size(int x)
  {
    return -par[root(x)];
  }

private:
  int root(int x)
  {
    if (par[x] < 0)
    {
      return x;
    }
    return par[x] = root(par[x]);
  }
};

template <typename T>
class RollingHash
{
  string S;
  static T B;
  vector<T> H;

public:
  RollingHash(string s, int t = -1) : S{s}
  {
    if (t == -1)
    {
      t = s.size();
    }
    assert(1 <= t && t <= static_cast<int>(s.size()));
    H = make_init_hash(t);
  }

  RollingHash(string s, size_t t) : RollingHash{s, static_cast<int>(t)} {}

  size_t size()
  {
    return S.size() + 1u - H.size();
  }

  const T operator[](size_t t) const { return H[t]; }

private:
  T Sm(size_t k) { return static_cast<T>(S[k]); }
  vector<T> make_init_hash(int);
};

template <typename T>
T RollingHash<T>::B = 1234567;

template <typename T>
vector<T> RollingHash<T>::make_init_hash(int t)
{
  vector<T> res(S.size() + 1 - t);
  T now = 0;
  const T pb = B.power(t);
  for (auto i = 0; i < t; i++)
  {
    now = now * B + Sm(i);
  }
  res[0] = now;
  for (auto i = 0u; i < res.size() - 1; i++)
  {
    res[i + 1] = res[i] * B - Sm(i) * pb + Sm(i + t);
  }
  return res;
}

int main()
{
  string S, T;
  cin >> S >> T;
  int N = S.size();
  stringstream U{};
  U << S << S << S;
  for (auto i = 0; i < 2 * static_cast<int>(T.size()) / N; i++)
  {
    U << S;
  }
  S = U.str();
#if DEBUG == 1
  cerr << "S = " << S << endl;
#endif
  vector<bool> ok(N, false);
  RollingHash<mint> rh_S{S, T.size()};
  RollingHash<mint> rh_T{T};
  const mint base = rh_T[0];
#if DEBUG == 1
  cerr << "rh_S.size() = " << rh_S.size() << endl;
  cerr << "rh_T.size() = " << rh_T.size() << endl;
  cerr << "base = " << base << endl;
#endif
  for (auto i = 0; i < N; i++)
  {
    ok[i] = (rh_S[i] == base);
#if DEBUG == 1
    cerr << "rh_S[" << i << "] = " << rh_S[i] << endl;
    if (ok[i])
    {
      cerr << "ok[" << i << "]" << endl;
    }
#endif
  }
  UnionFind uf{N};
  for (auto i = 0; i < N; i++)
  {
    int j = (i + T.size()) % N;
    if (ok[i] && ok[j])
    {
      if (!uf.merge(i, j))
      {
        No();
      }
    }
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    if (ok[i])
    {
      maxs(ans, uf.size(i));
    }
  }
  cout << ans << endl;
}