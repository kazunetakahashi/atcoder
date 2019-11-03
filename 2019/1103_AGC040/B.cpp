#define DEBUG 1
/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/11/4 0:40:34
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

using contest = tuple<ll, ll>;

ll solve_one(int N, vector<contest> &V)
{
  sort(V.begin(), V.end());
  vector<ll> maxi_L(N), maxi_R(N);
  maxi_L[0] = get<1>(V[0]);
  for (auto i = 1; i < N; i++)
  {
    maxi_L[i] = max(maxi_L[i - 1], get<1>(V[i]));
  }
  maxi_R[N - 1] = get<1>(V[N - 1]);
  for (auto i = N - 2; i >= 0; i--)
  {
    maxi_R[i] = max(maxi_R[i + 1], get<1>(V[i]));
  }
  ll ans{0LL};
  for (auto i = 0; i < N - 1; i++)
  {
    ll first{max(0LL, get<0>(V[0]) - maxi_L[i] + 1)};
    ll second{max(0LL, get<0>(V[i + 1]) - maxi_R[i + 1] + 1)};
    ch_max(ans, first + second);
  }
  return ans;
}

ll solve_two(int N, vector<contest> &V)
{
  sort(V.begin(), V.end());
  vector<ll> maxi_L(N), maxi_R(N);
  maxi_L[0] = get<1>(V[0]);
  for (auto i = 1; i < N; i++)
  {
    maxi_L[i] = max(maxi_L[i - 1], get<1>(V[i]));
  }
  maxi_R[N - 1] = get<1>(V[N - 1]);
  for (auto i = N - 2; i >= 0; i--)
  {
    maxi_R[i] = max(maxi_R[i + 1], get<1>(V[i]));
  }
  vector<ll> maxi_ex(N);
  maxi_ex[0] = maxi_R[1];
  maxi_ex[N - 1] = maxi_L[N - 2];
  for (auto i = 1; i < N - 1; i++)
  {
    maxi_ex[i] = max(maxi_L[i - 1], maxi_R[i + 1]);
  }
  for (auto i = 0; i < N; i++)
  {
    cerr << get<0>(V[i]) << " " << get<1>(V[i]) << endl;
  }
  for (auto i = 0; i < N; i++)
  {
    cerr << "maxi_ex[" << i << "] = " << maxi_ex[i] << endl;
  }
  vector<ll> length(N);
  for (auto i = 0; i < N; i++)
  {
    length[i] = get<0>(V[i]) - get<1>(V[i]) + 1;
  }
  ll ans{length[0] + max(0LL, 1 + get<0>(V[1]) - maxi_ex[0])};
  for (auto i = 1; i < N; i++)
  {
    ch_max(ans, length[i] + max(0LL, 1 + get<0>(V[0]) - maxi_ex[i]));
  }
  return ans;
}

int main()
{
  ll N;
  cin >> N;
  vector<contest> V(N);
  for (auto i = 0; i < N; i++)
  {
    ll L, R;
    cin >> L >> R;
    V[i] = contest(R, L);
  }
  ll ans{solve_one(N, V)};
  ch_max(ans, solve_two(N, V));
  cout << ans << endl;
}