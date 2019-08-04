#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 8/5/2019, 1:06:42 AM
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

template <typename T>
class SegTree
{ // 0-indexed, [0, N).
private:
  int N;
  T *dat;
  T UNIT; // モノイドの単位元

  static T func(T x, T y)
  { // ここで演算を定義する。圏、特にモノイドであればなんでも良い。
    // 実装はモノイドであるとする。
    // return min(x, y);
    return x + y;
  }

  static T _update(T x, T y)
  { // update で 値をどうするかを書く。
    // return y;
    return func(x, y);
  }

public:
  SegTree() {}

  SegTree(int n, T unit)
  { // ここで unit を定義するのも変な実装だけどめんどいからこれでいい。
    // min の場合は INFTY = (1LL << 60)
    // + の場合は 0 とする。
    UNIT = unit;
    N = 1;
    while (N < n)
    {
      N *= 2;
    }
    dat = new T[2 * N - 1];
    for (auto i = 0; i < 2 * N - 1; ++i)
    {
      dat[i] = UNIT;
    }
  }

  void update(int k, T a)
  {
    k += N - 1;
    dat[k] = _update(dat[k], a);
    while (k > 0)
    {
      k = (k - 1) / 2;
      dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

private:
  T find(int a, int b, int k, int l, int r)
  {
    if (r <= a || b <= l)
      return UNIT;
    if (a <= l && r <= b)
      return dat[k];
    T vl = find(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = find(a, b, k * 2 + 2, (l + r) / 2, r);
    return func(vl, vr);
  }

public:
  T find(int a, int b)
  { // [a, b) の find をする。
    return find(a, b, 0, 0, N);
  }
};

using info = tuple<ll, ll, ll, ll>;
using point = tuple<ll, ll, int>;

vector<point> V;
vector<info> I;

int main()
{
  int N;
  cin >> N;
  set<int> set_x, set_y;
  for (auto i = 0; i < N; i++)
  {
    int x, y;
    cin >> x >> y;
    V.emplace_back(x, y, i);
    set_x.insert(x);
    set_y.insert(y);
  }
  I.resize(N);
  map<int, int> map_x, map_y;
  {
    auto it = set_x.begin();
    for (auto i = 0; i < N; i++)
    {
      map_x[*it] = i;
      ++it;
    }
  }
  {
    auto it = set_y.begin();
    for (auto i = 0; i < N; i++)
    {
      map_y[*it] = i;
      ++it;
    }
  }
  for (auto i = 0; i < N; i++)
  {
    get<0>(V[i]) = map_x[get<0>(V[i])];
    get<1>(V[i]) = map_y[get<0>(V[i])];
  }
  sort(V.begin(), V.end());
  {
    SegTree<ll> tree{N, 0};
    for (auto i = 0; i < N; i++)
    {
      int x, y, ind;
      tie(x, y, ind) = V[i];
      ll k = tree.find(0, y);
      get<0>(I[ind]) = k;
      get<1>(I[ind]) = i - k;
      tree.update(y, 1);
    }
  }
  reverse(V.begin(), V.end());
  {
    SegTree<ll> tree{N, 0};
    for (auto i = 0; i < N; i++)
    {
      int x, y, ind;
      tie(x, y, ind) = V[i];
      ll k = tree.find(0, y);
      get<2>(I[ind]) = k;
      get<3>(I[ind]) = i - k;
      tree.update(y, 1);
    }
  }
  mint ans = 0;
  for (auto i = 0; i < N; i++)
  {
    ll a, b, c, d;
    tie(a, b, c, d) = I[i];
#if DEBUG == 1
    cerr << "(" << a << ", " << b << ", " << c << ", " << d << ")" << endl;
#endif
    ans += mint{2}.power(N);
    ans -= mint{2}.power(a + b);
    ans -= mint{2}.power(a + c);
    ans -= mint{2}.power(b + d);
    ans -= mint{2}.power(c + d);
    ans += mint{2}.power(a);
    ans += mint{2}.power(b);
    ans += mint{2}.power(c);
    ans += mint{2}.power(d);
  }
  cout << ans << endl;
}