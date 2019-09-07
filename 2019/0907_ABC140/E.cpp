#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/9/7 21:38:52
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

ll N;

using point = tuple<ll, ll>;

vector<vector<ll>> solve(vector<ll> const &V)
{
  vector<vector<ll>> ans(2, vector<ll>(N, -1));
  priority_queue<point, vector<point>, greater<point>> P, Q;
  for (auto i = 0LL; i < N; i++)
  {
    while (!Q.empty() && get<0>(Q.top()) < V[i])
    {
      ll val, ind;
      tie(val, ind) = Q.top();
      Q.pop();
      ans[1][ind] = i - ind - 1;
    }
    while (!P.empty() && get<0>(P.top()) < V[i])
    {
      ll val, ind;
      tie(val, ind) = P.top();
      P.pop();
      ans[0][ind] = i - ind - 1;
      Q.push(point(val, ind));
    }
    P.push(point(V[i], i));
  }
#if DEBUG == 1
  for (auto i = 0; i < N; i++)
  {
    cerr << "ans[0][" << i << "] = " << ans[0][i] << endl;
    cerr << "ans[1][" << i << "] = " << ans[1][i] << endl;
  }
#endif
  for (auto i = 0; i < N; i++)
  {
    if (ans[0][i] == -1)
    {
      assert(ans[1][i] == -1);
      ans[0][i] = N - i - 1;
      ans[1][i] = 0;
    }
    else if (ans[1][i] == -1)
    {
      ans[1][i] = N - i - 1;
    }
    else
    {
      ans[1][i] -= ans[0][i];
    }
  }
#if DEBUG == 1
  for (auto i = 0; i < N; i++)
  {
    cerr << "ans[0][" << i << "] = " << ans[0][i] << endl;
    cerr << "ans[1][" << i << "] = " << ans[1][i] << endl;
  }
#endif
  return ans;
}

int main()
{
  cin >> N;
  vector<ll> V(N);
  for (auto i = 0; i < N; i++)
  {
    cin >> V[i];
  }
  vector<vector<ll>> left{solve(V)};
  reverse(V.begin(), V.end());
  vector<vector<ll>> right{solve(V)};
  for (auto i = 0; i < 2; i++)
  {
    reverse(right[i].begin(), right[i].end());
  }
#if DEBUG == 1
  for (auto i = 0; i < N; i++)
  {
    cerr << "left[0][" << i << "] = " << left[0][i] << endl;
    cerr << "left[1][" << i << "] = " << left[1][i] << endl;
    cerr << "right[0][" << i << "] = " << right[0][i] << endl;
    cerr << "right[1][" << i << "] = " << right[1][i] << endl;
  }
#endif
  ll ans{0LL};
  for (auto i = 0; i < N; i++)
  {
    ans += (left[0][i] * right[1][i] + left[1][i] * right[0][i]) * V[i];
  }
  cout << ans << endl;
}