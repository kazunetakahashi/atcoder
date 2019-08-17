#define DEBUG 1
/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/8/17 21:17:12
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

combination C{};

class info
{
public:
  char c;
  ll l;
  vector<ll> v;

  info() {}
  info(char _c, ll _l) : c{_c}, l{_l}, v{0, 0, 0} {}
};

vector<info> make_vec(string const &S)
{
  vector<info> ans;
  char c{S[0]};
  ll now{0};
  for (auto x : S)
  {
#if DEBUG == 1
    cerr << "x = " << x << endl;
#endif
    if (c == x)
    {
      ++now;
    }
    else
    {
      ans.emplace_back(c, now);
      now = 1;
      c = x;
    }
  }
  ans.emplace_back(c, now);
  return ans;
}

mint calc(vector<info> const &V)
{
  mint ans{1};
  for (auto e : V)
  {
    for (auto x : e.v)
    {
      ans *= C.fact[x];
    }
  }
  return ans;
}

void make_v(vector<info> &V)
{
  map<char, ll> M;
  M['R'] = M['G'] = M['B'] = 0;
  for (auto &e : V)
  {
    char c{e.c};
    ll now{M[c]};
    ll next{now + e.l};
    vector<ll> X;
    for (auto x : M)
    {
      if (x.first == c)
      {
        continue;
      }
      X.push_back(x.second);
    }
    sort(X.begin(), X.end());
    if (now < X[0])
    {
      e.v[0] = min(X[0], next) - now;
    }
    if (X[0] < X[1])
    {
      e.v[1] = min(X[1], next) - max(X[0], now);
    }
    if (X[1] < next)
    {
      e.v[2] = next - max(X[1], now);
    }
    M[c] = next;
  }
}

int main()
{
  string S;
  cin >> S;
  ll N = S.size() / 3;
  vector<info> V{make_vec(S)};
  make_v(V);
#if DEBUG == 1
  for (auto e : V)
  {
    cerr << e.c << e.l << ": {" << e.v[0] << ", " << e.v[1] << ", " << e.v[2] << "}" << endl;
  }
#endif
  mint ans{calc(V) * C.fact[N]};
  cout << ans << endl;
}